/*
 * LCD.c
 *
 *  Created on: Dec 25, 2021
 *      Author: Samaa Seif
 */
#include "STD_Types.h"
#include"MEMMAP.h"
#include"BIT_MATH.h"
#include"DIO_Confg.h"
#include"DIO.h"
#include"LCD_Confg.h"
#include"LCD.h"
#include"util/delay.h"


void LCD_vidInit(void)
{
	_delay_ms(30);
	LCD_vidSendCommand(lcd_SET);
	_delay_ms(15);
	LCD_vidSendCommand(lcd_HOME);
	_delay_ms(1);
	LCD_vidSendCommand(lcd_DPY_ON);
	_delay_ms(1);
	LCD_vidSendCommand(lcd_CLR);
	_delay_ms(15);
	LCD_vidSendCommand(lcd_ENT_MODE);
	_delay_ms(2);
	LCD_vidSendCommand(lcd_CURSER);
	_delay_ms(2);

}


void LCD_vidSendCommand(uint8 Cmd) {
	DIO_Write_Channel(RS, LOW);
	DIO_Write_Channel(RW, LOW);
	DIO_Write_Channel(E, HIGH);
	DIO_Write_Port(LCD_PORT, Cmd);

	DIO_Write_Channel(E, LOW);
	_delay_ms(5);

	DIO_Write_Channel(E, HIGH);
	_delay_ms(10);
}

void LCD_vidSendData(uint8 Data) {
	DIO_Write_Channel(RS, HIGH);
	DIO_Write_Channel(RW, LOW);
	DIO_Write_Channel(E, HIGH);
	DIO_Write_Port(LCD_PORT, Data);

	DIO_Write_Channel(E, LOW);
	_delay_ms(5);

	DIO_Write_Channel(E, HIGH);
	_delay_ms(10);
}

void LCD_vidWriteString(uint8* Stg, uint8 Ind) {
	for (uint8 i = 0; i < Ind; i++) {
		LCD_vidSendData(Stg[i]);
		_delay_ms(2);
	}
}

extern void LCD_vidGotoXY(uint8 X, uint8 Y) {
	if (Y > 0 && Y <= 16) {
		switch (X) {
		case 1:
			LCD_vidSendCommand(Y + 127);
			break;
		case 2:
			LCD_vidSendCommand(Y + 191);
			break;
		}
	}
}

/*extern void LCD_vidWriteExtraChar(uint8 X, uint8 Y) {
	if (((Y > 0) && (Y <= 16)) && ((X == 1) || (X == 2))) {
		LCD_vidSendCommand(64);
		for (uint8 i = 0; i < 64; i++) {
			LCD_vidSendData(Extra_Char[i]);
		}

		LCD_vidSendCommand(128);
		LCD_vidGotoXY(X,Y);
		for (uint8 i = 0; i < 64; i++) {
			LCD_vidSendData(Extra_Char[i]);
			_delay_ms(5);
		}
	}
}*/

