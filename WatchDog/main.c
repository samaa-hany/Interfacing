/*
 * main.c
 *
 *  Created on: Jan 9, 2022
 *      Author: Samaa Seif
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO_Confg.h"
#include "DIO.h"
#include "util/delay.h"
#include "WatchDog.h"


uint8 main()
{
	DIO_INIT();
	DIO_Write_Channel(PORTC0,HIGH);
	_delay_ms(1000);
	WDG_Enable();
	//WDG_Disable();
	while(1)
	{

		DIO_Write_Channel(PORTC0,LOW);
		WDG_Refresh();
		while(1)
		{

		}

	}

	return 0;
}
