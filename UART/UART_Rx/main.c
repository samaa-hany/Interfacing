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
#include "LCD_Confg.h"
#include "LCD.h"
#include <avr/interrupt.h>
#include <util/delay.h>

uint8 Rx_Data = 0;

ISR(_VECTOR(13)) {
	Rx_Data = UART_Receiver_With_Interrupt();
}

uint8 main() {

	DIO_INIT();
	UART_INIT(51);
	if (Rx_Data == 0) {
		UART_Send_String("Samaa Hany0", 20);
		UART_Send_String("  Done0", 20);
	}
	while (1) {

		if (Rx_Data == HIGH) {
			DIO_Write_Channel(PORT_A0, HIGH);
		} else if (Rx_Data == LOW) {
			DIO_Write_Channel(PORT_A0, LOW);
		}
	}
	return 0;
}
