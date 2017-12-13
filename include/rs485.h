/*
 * Copyright (c) 2015 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief Public APIs for UART drivers
 */

#ifndef __INCrs485h
#define __INCrs485h

/**
 * @brief UART Interface
 * @defgroup uart_interface UART Interface
 * @ingroup io_interfaces
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <errno.h>
#include <stddef.h>

#include <device.h>

#ifdef CONFIG_PCI
#include <drivers/pci/pci.h>
#include <drivers/pci/pci_mgr.h>
#endif
/**
 * @brief Options for @a UART initialization.
 */
#if 0
#define UART_OPTION_AFCE 0x01

/** Common line controls for UART.*/
#define LINE_CTRL_BAUD_RATE	(1 << 0)
#define LINE_CTRL_RTS		(1 << 1)
#define LINE_CTRL_DTR		(1 << 2)
#define LINE_CTRL_DCD		(1 << 3)
#define LINE_CTRL_DSR		(1 << 4)

/* Common communication errors for UART.*/

/** @brief Overrun error */
#define UART_ERROR_OVERRUN  (1 << 0)

/** @brief Parity error */
#define UART_ERROR_PARITY   (1 << 1)

/** @brief Framing error */
#define UART_ERROR_FRAMING  (1 << 2)

/**
 * @typedef uart_irq_callback_t
 * @brief Define the application callback function signature for UART.
 *
 * @param port Device struct for the UART device.
 */
typedef void (*uart_irq_callback_t)(struct device *port);

/**
 * @typedef uart_irq_config_func_t
 * @brief For configuring IRQ on each individual UART device.
 *
 * @internal
 */
typedef void (*uart_irq_config_func_t)(struct device *port);

/**
 * @brief UART device configuration.
 *
 * @param port Base port number
 * @param base Memory mapped base address
 * @param regs Register address
 * @param sys_clk_freq System clock frequency in Hz
 */

struct uart_device_config {
	union {
		u32_t port;
		u8_t *base;
		u32_t regs;
	};

	u32_t sys_clk_freq;

#ifdef CONFIG_PCI
	struct pci_dev_info  pci_dev;
#endif /* CONFIG_PCI */

#ifdef CONFIG_UART_INTERRUPT_DRIVEN
	uart_irq_config_func_t	irq_config_func;
#endif
};
#endif
/** @brief Driver API structure. */
struct rs485_driver_api {
	/** Console I/O function */
	int (*poll_in)(struct device *dev, unsigned char *p_char);
	unsigned char (*poll_out)(struct device *dev, unsigned char out_char);

	/** Console I/O function */
	int (*err_check)(struct device *dev);

#ifdef CONFIG_UART_INTERRUPT_DRIVEN

	/** Interrupt driven FIFO fill function */
	int (*fifo_fill)(struct device *dev, const u8_t *tx_data, int len);

	/** Interrupt driven FIFO read function */
	int (*fifo_read)(struct device *dev, u8_t *rx_data, const int size);

	/** Interrupt driven transfer enabling function */
	void (*irq_tx_enable)(struct device *dev);

	/** Interrupt driven transfer disabling function */
	void (*irq_tx_disable)(struct device *dev);

	/** Interrupt driven transfer ready function */
	int (*irq_tx_ready)(struct device *dev);

	/** Interrupt driven receiver enabling function */
	void (*irq_rx_enable)(struct device *dev);

	/** Interrupt driven receiver disabling function */
	void (*irq_rx_disable)(struct device *dev);

	/** Interrupt driven transfer complete function */
	int (*irq_tx_complete)(struct device *dev);

	/** Interrupt driven receiver ready function */
	int (*irq_rx_ready)(struct device *dev);

	/** Interrupt driven error enabling function */
	void (*irq_err_enable)(struct device *dev);

	/** Interrupt driven error disabling function */
	void (*irq_err_disable)(struct device *dev);

	/** Interrupt driven pending status function */
	int (*irq_is_pending)(struct device *dev);

	/** Interrupt driven interrupt update function */
	int (*irq_update)(struct device *dev);

	/** Set the callback function */
	void (*irq_callback_set)(struct device *dev, uart_irq_callback_t cb);

#endif

#ifdef CONFIG_UART_LINE_CTRL
	int (*line_ctrl_set)(struct device *dev, u32_t ctrl, u32_t val);
	int (*line_ctrl_get)(struct device *dev, u32_t ctrl, u32_t *val);
#endif

#ifdef CONFIG_UART_DRV_CMD
	int (*drv_cmd)(struct device *dev, u32_t cmd, u32_t p);
#endif

};

/**
 * @brief Check whether an error was detected.
 *
 * @param dev UART device structure.
 *
 * @retval UART_ERROR_OVERRUN if an overrun error was detected.
 * @retval UART_ERROR_PARITY if a parity error was detected.
 * @retval UART_ERROR_FRAMING if a framing error was detected.
 * @retval UART_ERROR_BREAK if a break error was detected.
 * @retval 0 Otherwise.
 */
static inline int rs485_err_check(struct device *dev)
{
	const struct rs485_driver_api *api = dev->driver_api;

	if (api->err_check) {
		return api->err_check(dev);
	}
	return 0;
}


/**
 * @brief Poll the device for input.
 *
 * @param dev UART device structure.
 * @param p_char Pointer to character.
 *
 * @retval 0 If a character arrived.
 * @retval -1 If no character was available to read (i.e., the UART
 *            input buffer was empty).
 * @retval -ENOTSUP If the operation is not supported.
 */
static inline int rs485_poll_in(struct device *dev, unsigned char *p_char)
{
	const struct rs485_driver_api *api = dev->driver_api;

	return api->poll_in(dev, p_char);
}

/**
 * @brief Output a character in polled mode.
 *
 * This routine checks if the transmitter is empty.
 * When the transmitter is empty, it writes a character to the data
 * register.
 *
 * To send a character when hardware flow control is enabled, the handshake
 * signal CTS must be asserted.
 *
 * @param dev UART device structure.
 * @param out_char Character to send.
 *
 * @retval char Sent character.
 */
static inline unsigned char rs485_poll_out(struct device *dev,
					  unsigned char out_char)
{
	const struct rs485_driver_api *api = dev->driver_api;

	return api->poll_out(dev, out_char);
}

#ifdef __cplusplus
}
#endif

/**
 * @}
 */

#endif /* __INCuarth */
