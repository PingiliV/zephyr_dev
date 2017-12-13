#include <errno.h>
#include <misc/__assert.h>
#include <device.h>
#include <init.h>
#include <soc.h>
#include <rs485.h>
//#include <uart.h>
/*
 * Verify Kconfig configuration
 */

#if CONFIG_USART_SAM_PORT_1 == 1

#if CONFIG_USART_SAM_PORT_1_BAUD_RATE == 0
#error "CONFIG_USART_SAM_PORT_1_BAUD_RATE has to be bigger than 0"
#endif

#endif


/* Device constant configuration parameters */
struct rs485_sam_dev_cfg {
	Usart *regs;
	u32_t periph_id;
	struct soc_gpio_pin rs485_pin_rx;
	struct soc_gpio_pin rs485_pin_tx;
	struct soc_gpio_pin rs485_pin_rts;
};

/* Device run time data */
struct rs485_sam_dev_data {
	u32_t baud_rate;
};

#define DEV_CFG(dev) \
	((const struct rs485_sam_dev_cfg *const)(dev)->config->config_info)
#define DEV_DATA(dev) \
	((struct rs485_sam_dev_data *const)(dev)->driver_data)


static int baudrate_set(Usart *const usart, u32_t baudrate,
			u32_t mck_freq_hz);


static int rs485_sam_init(struct device *dev)
{
	int retval;
	const struct rs485_sam_dev_cfg *const cfg = DEV_CFG(dev);
	struct rs485_sam_dev_data *const dev_data = DEV_DATA(dev);
	Usart *const usart = cfg->regs;

	/* Enable USART clock in PMC */
	soc_pmc_peripheral_enable(cfg->periph_id);
	printk("Called rs485_sam_init\n");

	/* Connect pins to the peripheral */
	soc_gpio_configure(&cfg->rs485_pin_rx);
	soc_gpio_configure(&cfg->rs485_pin_tx);
	soc_gpio_configure(&cfg->rs485_pin_rts);
	/* Reset and disable USART */
	usart->US_CR =   US_CR_RSTRX | US_CR_RSTTX
		       | US_CR_RXDIS | US_CR_TXDIS | US_CR_RSTSTA;

	/* Disable Interrupts */
	usart->US_IDR = 0xFFFFFFFF;

	/* 8 bits of data, no parity, 1 stop bit in normal mode */
	usart->US_MR =   US_MR_NBSTOP_1_BIT
		       | US_MR_PAR_NO
		       | US_MR_CHRL_8_BIT
		       | US_MR_USCLKS_MCK
		       | US_MR_USART_MODE_RS485;

	/* Set baud rate */
	retval = baudrate_set(usart, dev_data->baud_rate,
			      SOC_ATMEL_SAM_MCK_FREQ_HZ);
	if (retval != 0) {
		return retval;
	};

	/* Enable receiver and transmitter */
	usart->US_CR = US_CR_RXEN | US_CR_TXEN;

	return 0
}

static int rs485_sam_receive(struct device *dev, unsigned char *c)
{
	printk("Called rs485_sam_receive\n");
	return 0;
}

static unsigned char rs485_sam_send(struct device *dev, unsigned char c)
{
	printk("Called rs485_sam_receive\n");
	c = 'x';
	return c;
}

static int baudrate_set(Usart *const usart, u32_t baudrate,
			u32_t mck_freq_hz)
{
	printk("baudrate_set called \n");
	u32_t divisor;

	__ASSERT(baudrate,
		 "baud rate has to be bigger than 0");
	__ASSERT(mck_freq_hz/16 >= baudrate,
		 "MCK frequency is too small to set required baud rate");

	divisor = mck_freq_hz / 16 / baudrate;

	if (divisor > 0xFFFF) {
		return -EINVAL;
	};

	usart->US_BRGR = US_BRGR_CD(divisor);

	return 0;
}

static const struct rs485_driver_api rs485_sam_driver_api = {
	.poll_in = rs485_sam_receive,
	.poll_out = rs485_sam_send,
};

DEVICE_DEFINE(rs485_sam, CONFIG_SAM_RS485_0_NAME, &rs485_sam_init, rtc_qmsi_device_ctrl,
	      RTC_CONTEXT, NULL, POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEVICE,
	      &api);

/* USART1 */

#ifdef CONFIG_USART_SAM_PORT_1
static const struct rs485_sam_dev_cfg rs485_sam_config = {
	.regs = USART1,
	.periph_id = ID_USART1,
	.rs485_pin_rx = PIN_USART1_RXD,
	.rs485_pin_tx = PIN_USART1_TXD,
	.rs485_pin_rts = PIN_USART1_RTS,
};

static struct rs485_sam_dev_data rs485_sam_data = {
	.baud_rate = CONFIG_USART_SAM_PORT_1_BAUD_RATE,
};

DEVICE_AND_API_INIT(rs485_sam, CONFIG_USART_SAM_PORT_1_NAME, &rs485_sam_init,
		    &rs485_sam_data, &rs485_sam_config, PRE_KERNEL_1,
		    CONFIG_KERNEL_INIT_PRIORITY_DEVICE, &rs485_sam_driver_api);
#endif

