/*
 * Safe_hdlr.c
 *
 *  Created on: Jan 3, 2022
 *      Author: Samaa Seif
 */
#include"STD_Types.h"
#include"BIT_MATH.h"
#include"MEMMAP.h"
#include"DIO_Confg.h"
#include"DIO.h"
#include"KEYPAD.h"
#include"LCD_Confg.h"
#include"LCD.h"
#include"util/delay.h"

uint8 key_value = NO_PRESSED_VALUE;
uint8 P, s, sum3, sum4, sum2, f, i = 0;

void Enter_New_Pass(void) {
	const uint8 Ent1[] = { "Enter New Pass:" };
	LCD_vidWriteString(&Ent1[0], 14);
	LCD_vidGotoXY(2, 1);
	LCD_vidWriteString(&Ent1[10], 5);
	LCD_vidGotoXY(2, 6);
	_delay_ms(200);
}

void Enter_Your_Pass(void) {
	const uint8 Ent1[] = { "Enter Your Pass:" };
	LCD_vidWriteString(&Ent1[0], 15);
	LCD_vidGotoXY(2, 1);
	LCD_vidWriteString(&Ent1[11], 5);
	LCD_vidGotoXY(2, 6);
	_delay_ms(200);
}

void Confirm_Pass(void) {
	const uint8 Ent2[] = { "Confirm Pass:" };
	LCD_vidSendCommand(lcd_CLR);
	LCD_vidGotoXY(1, 1);
	LCD_vidWriteString(&Ent2[0], 12);
	LCD_vidGotoXY(2, 1);
	LCD_vidWriteString(&Ent2[8], 5);
	LCD_vidGotoXY(2, 6);
	_delay_ms(200);
}

void Welcome(void) {
	const uint8 Ent3[] = { "Welcome ^-^" };
	LCD_vidWriteString(&Ent3[0], 12);
	_delay_ms(200);
}

void Safe_Opened(void) {
	const uint8 Ent4[] = { "Open Safe" };
	const uint8 Ent[] = { "Close" };
	const uint8 Ent1[] = { "Reset" };
	LCD_vidWriteString(&Ent4[0], 9);
	LCD_vidGotoXY(2, 1);
	LCD_vidWriteString(&Ent[0], 5);
	LCD_vidGotoXY(2, 7);
	LCD_vidWriteString(&Ent1[0], 5);
	DIO_Write_Channel(PORTA3, LOW);
	DIO_Write_Channel(PORTA4, HIGH);

	_delay_ms(200);
}

void Safe_Closed(void) {
	const uint8 Ent4[] = { "Safe Closed" };
	LCD_vidWriteString(&Ent4[0], 10);
	_delay_ms(200);
}

void Enter_Old_Pass(void) {
	const uint8 Ent5[] = { "Enter Old Pass:" };
	LCD_vidWriteString(&Ent5[0], 14);
	LCD_vidGotoXY(2, 1);
	LCD_vidWriteString(&Ent5[10], 5);
	LCD_vidGotoXY(2, 6);
	_delay_ms(200);
}

void Call_Admin(void) {
	const uint8 Ent3[] = { "Admin -_-" };
	LCD_vidWriteString(&Ent3[0], 9);
	LCD_vidGotoXY(2, 1);
	_delay_ms(200);
}

void Haramy(void) {
	const uint8 Ent3[] = { "Haramy -_-" };
	LCD_vidWriteString(&Ent3[0], 10);
	_delay_ms(2000);
}

uint8 Password_Data(void) {
	uint8 arr[5], sum = 0;
	s = 1000;
	for (i = 0; i < 5; i++) {
		key_value = NO_PRESSED_VALUE;
		while (key_value == NO_PRESSED_VALUE) {

			key_value = KEYPAD_READ();
		}
		arr[i] = key_value;
		P = key_value * s;
		s = s / 10;
		LCD_vidSendData('*');
		sum = sum + P;

	}
	return sum;
}

uint8 Password_Admin(void) {
	uint8 arr[5], sum = 0;
	uint8 admin_arr[5] = { '2', '0', '2', '2', 'E' };

	for (i = 0; i < 5; i++) {
		key_value = NO_PRESSED_VALUE;
		while (key_value == NO_PRESSED_VALUE) {
			key_value = KEYPAD_READ();
		}

		arr[i] = key_value;
		if (arr[i] != admin_arr[i])
			sum = sum + 0;
		else
			sum = sum + 1;
		LCD_vidSendData('*');
	}
	return sum;
}

void Close(void) {
	uint8 flag = 1;
	while (flag) {
		DIO_Write_Channel(PORTA3, HIGH);
		DIO_Write_Channel(PORTA4, LOW);
		_delay_ms(3000);
		DIO_Write_Channel(PORTA3, LOW);
		DIO_Write_Channel(PORTA4, LOW);
		flag = 0;
	}
}

void Confirmation(uint8 sum1, uint8 sum2) {
	uint8 flag = 1;
	while (flag) {
		if (sum1 == sum2) {
			flag = 0;
		} else {
			Enter_New_Pass();
			sum1 = Password_Data();
			LCD_vidSendCommand(lcd_CLR);
			Confirm_Pass();
			sum2 = Password_Data();
		}
	}
	LCD_vidSendCommand(lcd_CLR);
	Welcome();
	_delay_ms(2000);
	LCD_vidSendCommand(lcd_CLR);
}

void Call_Admin_Pass(void) {
	const uint8 Ent1[] = { "Call Admin" };
	const uint8 Ent2[] = { "Pass:" };
	LCD_vidWriteString(&Ent1[0], 10);
	LCD_vidGotoXY(2, 1);
	LCD_vidWriteString(&Ent2[0], 5);
	LCD_vidGotoXY(2, 6);
	_delay_ms(200);
}

uint8 Confirmation_Old_Pass(uint8 sum3, uint8 sum1) {
	uint8 f = 0;
	while (f < 2) {
		if (sum3 != sum1) {
			LCD_vidSendCommand(lcd_CLR);
			Enter_Your_Pass();
			sum3 = Password_Data();
			f++;
		} else {
			f = 4;
			LCD_vidSendCommand(lcd_CLR);
			Welcome();
		}
	}
	return f;
}



/*void LCD_vidWriteExtraChar(uint8 X, uint8 Y) {
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

void Clear(void) {
	uint8 key = KEYPAD_READ();
	if (key == 'C') {
		LCD_vidSendCommand(lcd_CLR);
	}
}
