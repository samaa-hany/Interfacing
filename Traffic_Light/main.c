/*
 * main.c
 *
 *  Created on: Jan 12, 2022
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

uint8 main() {

	DIO_INIT();
	SEV_SEG_INIT();
	while (1) {
		Traffic_MainFunction();
	}
	return 0;
}
