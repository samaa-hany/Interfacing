/*
 * WatchDog.c
 *
 *  Created on: Jan 9, 2022
 *      Author: Samaa Seif
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO_Confg.h"
#include "DIO.h"
#include "WatchDog.h"


void WDG_Enable(void)
{
	WDTCR=0x18;
}

void WDG_Disable(void)
{
	WDTCR=0x00;
}

void WDG_Refresh(void)
{
	asm volatile("wdr");
}

