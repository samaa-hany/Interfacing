/*
 * UART.c
 *
 *  Created on: Jan 21, 2022
 *      Author: Samaa Seif
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO_Confg.h"
#include "DIO.h"
#include "UART.h"
uint8 F = 0;

void UART_INIT(uint16 baud) {
	/* Set baud rate */
	UBRRL = baud;

	/* Enable Receiver and Transmitter: RXEN
	 *                                  TXEN */
	SET_BIT(UCSRB, Uart4);
	SET_BIT(UCSRB, Uart3);

	/* Set frame format: 8data, 2stop bit */
	CLR_BIT(UCSRC, Uart7);
	SET_BIT(UCSRC, Uart3);
	SET_BIT(UCSRC, Uart4);

	/*Enable Interrupt & Global Interrupt*/
	SET_BIT(UCSRB, Uart7);
	SET_BIT(SREG, Uart7);

}

void UART_Send_Char(uint8 data) {
	/* Wait for empty transmit (UDRE)*/
	while (!( UCSRA & (1 << Uart5)))
		;

	/* Sends the data */
	UDR = data;
}

void UART_Send_String(uint8* data, uint8 Length) {
	/* Sends the array of chars*/
	uint8 iteration = 0;
	for (iteration = 0; iteration <= Length; iteration++) {
		if (data[iteration] != '0') {
			UART_Send_Char(data[iteration]);
		} else if (data[iteration] == '0') {
			UART_Send_Char(data[iteration]);
			Length = iteration;
		}
	}
}

uint8 UART_Receive_Char(void) {
	/* Wait for data to be received (RXC)*/
	while (!(UCSRA & (1 << Uart7)))
		;

	/* Get and return received data */
	return UDR;
}

uint8 UART_Receiver_With_Interrupt(void) {
	/* Get and return received data */
	return UDR;
}
