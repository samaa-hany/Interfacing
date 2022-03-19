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
		volatile uint32 Analog =  ((uint32)(1000 *(Global_ADC * Vref))) / 1024;
		//uint32 ldr=R*(V-Analog)/Analog;
		//printf("%d",ldr);
		uint32 Degree= (Analog/10);


		if (Degree >= 0 && Degree <= 50) {
			DIO_Write_Channel(LED1, HIGH);
			DIO_Write_Channel(LED2, LOW);
			DIO_Write_Channel(LED3, LOW);
		} else if (Degree > 50 && Degree <= 100) {
			DIO_Write_Channel(LED1, LOW);
			DIO_Write_Channel(LED2, HIGH);
			DIO_Write_Channel(LED3, LOW);
		} else if (Degree > 100 && Degree <= 150) {
			DIO_Write_Channel(LED1, LOW);
			DIO_Write_Channel(LED2, LOW);
			DIO_Write_Channel(LED3, HIGH);
		}
	}

	return 0;
}
