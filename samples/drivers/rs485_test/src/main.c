/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*
 * @addtogroup t_uart_basic
 * @{
 * @defgroup t_uart_poll test_uart_poll
 * @brief TestPurpose: verify UART works well in poll mode
 * @details
 * - Test Steps
 *    - Poll Output:
 *      -# Output the prepared data using uart_poll_out(), and compare
 *         the output characters with the original characters.
 *    - Poll Input:
 *      -# Wait for data from UART console using uart_poll_in(). User sends
 *         data to UART console using echo "qwer" > /dev/ttyUSB* and waits
 *         for uart_poll_in() exit.
 * - Expected Results
 *   -# When test UART poll out, the return value from uart_poll_out()
 *      will be equal to the character sent out.
 *   -# When test UART poll in, the app will wait for input from UART
 *      console and exit after receiving '\n'.
 * @}
 */
#include <errno.h>
#include <zephyr.h>
#include <misc/printk.h>
#include <device.h>
#include "test_rs485.h"


static const char *poll_data = "This is a POLL test.\r\n";

static int test_poll_in(void)
{
	unsigned char recv_char;
	struct device *rs485_dev = device_get_binding(RS485_DEVICE_NAME);
#if 0
	if (!uart_dev) {
		TC_PRINT("Cannot get UART device\n");
		return TC_FAIL;
	}

	TC_PRINT("Please send characters to serial console\n");

	/* Verify uart_poll_in() */
	while (1) {
		while (uart_poll_in(uart_dev, &recv_char) < 0)
			;

		TC_PRINT("%c", recv_char);

		if ((recv_char == '\n') || (recv_char == '\r')) {
			break;
		}
	}

	return TC_PASS;
#endif
	printk("Atmel SAM RS485 driver test poll in called\n");
	rs485_poll_in(rs485_dev, &recv_char);
	return 0;
}

static int test_poll_out(void)
{
	int i;
	unsigned char sent_char;
	struct device *rs485_dev = device_get_binding(RS485_DEVICE_NAME);
#if 0
	if (!uart_dev) {
		TC_PRINT("Cannot get UART device\n");
		return TC_FAIL;
	}

	/* Verify uart_poll_out() */
	for (i = 0; i < strlen(poll_data); i++) {
		sent_char = uart_poll_out(uart_dev, poll_data[i]);

		if (sent_char != poll_data[i]) {
			TC_PRINT("expect send %c, actaul send %c\n",
						poll_data[i], sent_char);
			return TC_FAIL;
		}
	}

	return TC_PASS;
#endif
	printk("Atmel SAM RS485 driver test poll out called\n");
	rs485_poll_out(rs485_dev,'a');
	return 0;
}

void main(void)
{
	printk("Atmel SAM RS485 driver test invoked\n");
	test_poll_in();	
	test_poll_out();
}

