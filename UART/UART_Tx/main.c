/*
 * main.c
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
#include <avr/interrupt.h>

uint8 Rx_Data = 0;
ISR(_VECTOR(13)) {
	Rx_Data = UART_Receiver_With_Interrupt();
}

uint8 main() {

	uint8 Tx_Data0, Tx_Data1;

	DIO_INIT();
	UART_INIT(51);
	UART_Send_String("Samaa Hany0",20);

	while (1) {
		Tx_Data0 = DIO_Read_Channel(PORTA0);
		Tx_Data1 = DIO_Read_Channel(PORTA1);
		if ((Tx_Data0 == 0) && (Tx_Data1 == 1)) {
			UART_Send_Char(LOW);
		} else if ((Tx_Data0 == 1) && (Tx_Data1 == 0)) {
			UART_Send_Char(HIGH);
		}

	}

	return 0;
}



//			Tx_Data0 = DIO_Read_Channel(PORTA0);
//			Tx_Data1 = DIO_Read_Channel(PORTA1);
//			if((Tx_Data0 == 1) & (Tx_Data1 == 0)){
//
//			}
//		DIO_Write_Channel(PORTA0, HIGH);
//		DIO_Write_Channel(PORTA1, HIGH);
