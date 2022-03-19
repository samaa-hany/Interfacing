/*
 * Traffic.c
 *
 *  Created on: Jan 14, 2022
 *      Author: Samaa Seif
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO_Confg.h"
#include "DIO.h"
#include "SEV_SEG.h"
#include "Traffic.h"
#define F_CPU 16000000UL
#include "util/delay.h"

uint8 Counter = 0, Toggle = 0, Traffic = 1, R_itreation, G_itreation;

void Traffic_MainFunction(void) {

	switch (Traffic) {
	/*Processing of Red LED*/
	case R_LED:
		DIO_Write_Channel(RED_LED, HIGH);
		SEV_Segment_Display(Counter / 10);
		DIO_Write_Channel(PORTA7, LOW);
		DIO_Write_Channel(PORTB0, HIGH);
		_delay_ms(15);
		SEV_Segment_Display(Counter % 10);
		DIO_Write_Channel(PORTA7, HIGH);
		DIO_Write_Channel(PORTB0, LOW);
		_delay_ms(15);
		Toggle += 10;
		if (Max_Toggle == Toggle) {
			Toggle = 0;
			Counter++;
			if (Counter > Traffic_Period) {
				Counter = 0;
				/*Processing of Yellow LED by turn of the Red LED and toggle the Yellow one*/
				for (R_itreation = 0; R_itreation < 5; R_itreation++) {
					SEV_Segment_Display(Counter);
					DIO_Write_Channel(RED_LED, LOW);
					DIO_Write_Channel(YELLOW_LED, HIGH);
					_delay_ms(250);
					DIO_Write_Channel(YELLOW_LED, LOW);
					_delay_ms(250);
				}
				Traffic = G_LED;
			}
		}

		break;
	/*Processing of Green LED*/
	case G_LED:
		DIO_Write_Channel(GREEN_LED, HIGH);
		SEV_Segment_Display(Counter / 10);
		DIO_Write_Channel(PORTA7, LOW);
		DIO_Write_Channel(PORTB0, HIGH);
		_delay_ms(15);
		SEV_Segment_Display(Counter % 10);
		DIO_Write_Channel(PORTA7, HIGH);
		DIO_Write_Channel(PORTB0, LOW);
		_delay_ms(15);
		Toggle += 10;
		if (Max_Toggle == Toggle) {
			Toggle = 0;
			Counter++;
			if (Counter > Traffic_Period) {
				Counter = 0;
				/*Processing of Yellow LED by turn of the Green LED and toggle the Yellow one*/
				for (G_itreation = 0; G_itreation < 5; G_itreation++) {
					SEV_Segment_Display(Counter);
					DIO_Write_Channel(GREEN_LED, LOW);
					DIO_Write_Channel(YELLOW_LED, HIGH);
					_delay_ms(250);
					DIO_Write_Channel(YELLOW_LED, LOW);
					_delay_ms(250);
				}
				Traffic = R_LED;
			}
		}
		break;
	}
}

