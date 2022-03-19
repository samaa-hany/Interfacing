/*
 * main.c
 *
 *  Created on: Jan 22, 2022
 *      Author: Samaa Seif
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO_Confg.h"
#include "DIO.h"
#include "SPI.h"
#include "LCD_Confg.h"
#include "LCD.h"
#include <util/delay.h>
#include <avr/interrupt.h>

uint8 Rx_Data = 0;
//ISR(_VECTOR(12)){
//	Rx_Data = SPI_Receive_Data_With_Interrupt();
//}

uint8 main() {
	DIO_INIT();
	LCD_vidInit();
	SPI_INIT_MODE(LSB, Slave);
	//SPI_Interruprt(Enable);
	LCD_vidSendData('*');

	while (1) {
		LCD_vidGotoXY(1, 1);
		Rx_Data=SPI_Receive_Data();
		LCD_vidSendData(Rx_Data);
		_delay_ms(20);
	}

	return 0;
}

#if 0
Rx_Data = SPI_Receive_Data();
if (Rx_Data == HIGH) {
	DIO_Write_Channel(PORT_B0, HIGH);
} else if (Rx_Data == LOW) {
	DIO_Write_Channel(PORT_B0, LOW);
}

#endif
