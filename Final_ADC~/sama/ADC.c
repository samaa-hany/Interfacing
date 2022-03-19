/*
 * ADC.c
 *
 *  Created on: Jan 7, 2022
 *      Author: Samaa Seif
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO_Confg.h"
#include "DIO.h"
#include "ADC.h"

void ADC_INIT(void) {

	//Enable the Vref
	SET_BIT(ADMUX, CH6);
	CLR_BIT(ADMUX, CH7);

	// ADC Pre-scaler
	SET_BIT(ADCSRA, CH0);
	SET_BIT(ADCSRA, CH1);
	SET_BIT(ADCSRA, CH2);

	// Enable ADC
	SET_BIT(ADCSRA, CH7);

	// Enable ADC Interrupt
	SET_BIT(ADCSRA, CH3);

	// Enable Global Interrupt
	SET_BIT(SREG,CH7);
	ADMUX &= 0xf0;
}

void ADC_StartConversion(void) {

	//Start Conversion
	SET_BIT(ADCSRA, CH6);
}

uint16 ADC_Read(void) {
	return ADC;
}
