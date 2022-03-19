/*
 * Safe.c
 *
 *  Created on: Dec 30, 2021
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
#include"Safe_hdlr.h"
#include"Safe.h"
#include"util/delay.h"

uint8 STATE = 0;

/*void SAFE_Init(void) {
	DIO_INIT();
	KEYPAD_INIT();
	LCD_vidInit();
	LCD_vidSendCommand(lcd_CLR);
	uint8 Extra_Char[8][8] = {
			{ 0X0E, 0X08, 0X1E, 0X00, 0X04, 0X04, 0X04, 0X04 }, { 0x06, 0x06,
					0x01, 0x01, 0x01, 0x01, 0x1F, 0x00 }, { 0x0A, 0x00, 0x11,
					0x11, 0x11, 0x11, 0x1F, 0x00 }, { 0x00, 0x18, 0x06, 0x01,
					0x1E, 0x00, 0x00, 0x00 }, { 0x00, 0x00, 0x00, 0x01, 0x01,
					0x02, 0x04, 0x18 }, { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
					0x01, 0x01 }, { 0x00, 0x00, 0x02, 0x05, 0x05, 0x1B, 0x00,
					0x00 }, { 0x00, 0x06, 0x05, 0x15, 0x15, 0x14, 0x08, 0x00 } };
	uint8 Idx;
	for (Idx = 0; Idx < 8; Idx++) {
		LCD_Write_CGRAM(Extra_Char[Idx], Idx);
	}
}*/
void Safe_MainFunction(void) {
	uint8 sum1, sum2, sum3, sum4, sum5, key_value, f1, flag = 1;

	switch (STATE) {
	case New_passward:
		LCD_vidSendCommand(lcd_CLR);
		Enter_New_Pass();
		sum1 = Password_Data();

		Confirm_Pass();
		sum2 = Password_Data();

		LCD_vidSendCommand(lcd_CLR);
		Confirmation(sum1, sum2);

		key_value = KEYPAD_READ();
		_delay_ms(200);
		if (key_value == 'C') {
			LCD_vidSendCommand(lcd_CLR);
			STATE = New_passward;
		} else if (key_value == 'R') {
			Close();
			STATE = Old_passward;
		} else if (key_value == 'L') {
			Close();
			STATE = Safe_closed;
		} else {
			STATE = Safe_opened;
		}

		break;

	case Safe_opened:

		LCD_vidSendCommand(lcd_CLR);
		Safe_Opened();
		key_value = KEYPAD_READ();
		_delay_ms(200);
		if (key_value == 'R') {
			Close();
			STATE = Old_passward;
		} else if (key_value == 'L') {
			Close();
			STATE = Safe_closed;
		}
		break;

	case Safe_closed:
		LCD_vidSendCommand(lcd_CLR);
		Safe_Closed();
		STATE = Your_passward;
		break;

	case Old_passward:
		LCD_vidSendCommand(lcd_CLR);
		Enter_Old_Pass();
		sum5 = Password_Data();
		if (sum5 == sum1)
			STATE = New_passward;
		else {
			STATE = HARAMY;
		}
		key_value = KEYPAD_READ();
		if (key_value == 'C') {
			LCD_vidSendCommand(lcd_CLR);
			STATE = Old_passward;
		} else if (key_value == 'L') {
			Close();
			STATE = Safe_closed;
		}
		break;

	case Your_passward:
		LCD_vidSendCommand(lcd_CLR);
		Enter_Your_Pass();
		sum3 = Password_Data();
		key_value = KEYPAD_READ();
		if (key_value == 'C') {
			LCD_vidSendCommand(lcd_CLR);
			STATE = Your_passward;
		} else if (key_value == 'R') {
			Close();
			STATE = Old_passward;
		} else if (key_value == 'L') {
			Close();
			STATE = Safe_closed;
		} else {
			f1 = Confirmation_Old_Pass(sum3, sum1);
		}
		if (f1 == 2) {

			STATE = HARAMY;
		}
		break;

	case HARAMY:
		LCD_vidSendCommand(lcd_CLR);
		//SAFE_Init();
		Haramy();
		STATE = ADMIN;
		break;

	case ADMIN:
		LCD_vidSendCommand(lcd_CLR);
		Call_Admin();
		sum4 = Password_Admin();

		while (flag) {
			if (sum4 != 5) {
				LCD_vidSendCommand(lcd_CLR);
				Call_Admin_Pass();
				sum4 = Password_Admin();
			} else {
				LCD_vidSendCommand(lcd_CLR);
				STATE = New_passward;
				flag = 0;
			}
		}
		break;

	}
}
