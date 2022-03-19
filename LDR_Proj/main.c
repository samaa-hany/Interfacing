/*
 * main.c
 *
 *  Created on: Jan 7, 2022
 *      Author: Samaa Seif
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO_Confg.h"
#include "DIO.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include "ADC.h"

volatile uint32 Global_ADC;

ISR( __vector_16) {
	Global_ADC = ADC_Read();
}

uint8 main() {
	DIO_INIT();
	ADC_INIT();
	while (1) {
		ADC_StartConversion();
		volatile uint32 Analog = ((uint32) (1000 * (Global_ADC * Vref))) / 1024;

		if (Analog ==0) {
			DIO_Write_Channel(LED1, HIGH);
			DIO_Write_Channel(LED2, HIGH);
			DIO_Write_Channel(LED3, HIGH);
			DIO_Write_Channel(LED4, HIGH);
		} else if (Analog > 3 && Analog <= 7) {
			DIO_Write_Channel(LED1, HIGH);
			DIO_Write_Channel(LED2, HIGH);
			DIO_Write_Channel(LED3, HIGH);
			DIO_Write_Channel(LED4, LOW);
		} else if (Analog > 8 && Analog <= 15) {
			DIO_Write_Channel(LED1, HIGH);
			DIO_Write_Channel(LED2, HIGH);
			DIO_Write_Channel(LED3, LOW);
			DIO_Write_Channel(LED4, LOW);
		} else if (Analog > 18 && Analog <= 30) {
			DIO_Write_Channel(LED1, HIGH);
			DIO_Write_Channel(LED2, LOW);
			DIO_Write_Channel(LED3, LOW);
			DIO_Write_Channel(LED4, LOW);
		} else if (Analog > 40 && Analog <= 70) {
			DIO_Write_Channel(LED1, LOW);
			DIO_Write_Channel(LED2, LOW);
			DIO_Write_Channel(LED3, LOW);
			DIO_Write_Channel(LED4, LOW);
		}
	}
	return 0;
}
