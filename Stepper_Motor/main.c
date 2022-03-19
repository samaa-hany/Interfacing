/*
 * main.c
 *
 *  Created on: Dec 31, 2021
 *      Author: Samaa Seif
 */
#include"STD_Types.h"
#include"BIT_MATH.h"
#include"MEMMAP.h"
#include"DIO_Confg.h"
#include"DIO.h"
#include"Motor.h"
#include"util/delay.h"

uint8 main(void)
{
DIO_INIT();
while(1)
{
	Motor_CW_Full();
	Motor_CW_Half();

}

	return 0;
}

