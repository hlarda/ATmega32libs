#ifndef UART_CONFIG_H
#define UART_CONFIG_H

#define SYSTEM_CLK				8000000UL
#define UART_BAUD_RATE			9600UL

/*System Speed: UART_X1, UART_X2 */
#define UART_SYSTEM_SPEED				UART_X1
/*RX Complete Interrupt Enable: DISABLE, ENABLE*/
#define UART_RX_COMPLETE_INTERRUPT		DISABLE
/*TX Complete Interrupt Enable: DISABLE, ENABLE*/
#define UART_TX_COMPLETE_INTERRUPT		DISABLE
/*UDR Empty Interrupt Enable: DISABLE, ENABLE*/
#define UART_UDR_EMPTY_INTERRUPT		DISABLE
/*Receiver Enable: DISABLE, ENABLE*/
#define UART_RECEIVER_ENABLE		ENABLE
/*Transmitter Enable: DISABLE, ENABLE*/
#define UART_TRANSMITTER_ENABLE		ENABLE
/*UART Mode Select: ASYNCHRONOUS, SYNCHRONOUS*/
#define UART_MODE					ASYNCHRONOUS
/*Parity Mode: DISABLE, EVEN_PARITY, ODD_PARITY*/
#define UART_PARITY_MODE			DISABLE
/*Stop bit: STOP_BIT_1, STOP_BIT_2*/
#define UART_STOP_BIT				STOP_BIT_1
/*Data Size: DATA_SIZE_5_BIT, DATA_SIZE_6_BIT, DATA_SIZE_7_BIT, DATA_SIZE_8_BIT, DATA_SIZE_9_BIT*/
#define UART_DATA_SIZE				DATA_SIZE_8_BIT
/*Clock Polarity (for SYNCHRONOUS mode only): XCK_RISING_TX_XCH_FALLING_RX, XCK_RISING_RX_XCH_FALLING_TX*/
#define UART_CLOCK_POLARITY		XCK_RISING_TX_XCH_FALLING_RX

#endif