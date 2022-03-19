/*
 * Motor.c
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

void Motor_CW_Full(void) {
	DIO_Write_Port(Motor_PORT, 0x01);
	_delay_ms(10);
	DIO_Write_Port(Motor_PORT, 0x02);
	_delay_ms(10);
	DIO_Write_Port(Motor_PORT, 0x04);
	_delay_ms(10);
	DIO_Write_Port(Motor_PORT, 0x08);
	_delay_ms(10);

}


void Motor_CW_Half(void) {
	DIO_Write_Port(Motor_PORT, 0x09);
	_delay_ms(10);
	DIO_Write_Port(Motor_PORT, 0x01);
	_delay_ms(10);
	DIO_Write_Port(Motor_PORT, 0x03);
	_delay_ms(10);
	DIO_Write_Port(Motor_PORT, 0x02);
	_delay_ms(10);
	DIO_Write_Port(Motor_PORT, 0x06);
	_delay_ms(10);
	DIO_Write_Port(Motor_PORT, 0x04);
	_delay_ms(10);
	DIO_Write_Port(Motor_PORT, 0x0C);
	_delay_ms(10);
	DIO_Write_Port(Motor_PORT, 0x08);
	_delay_ms(10);
}

