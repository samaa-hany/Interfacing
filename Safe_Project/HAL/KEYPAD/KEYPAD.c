/*
 * KEYPAD.c
 *
 *  Created on: Dec 24, 2021
 *      Author: Samaa Seif
 */
#include"STD_Types.h"
#include"DIO.h"
#include"DIO_Confg.h"
#include"BIT_MATH.h"
#include"KEYPAD.h"

void KEYPAD_INIT(void) {

	DIO_Write_Port(KEYPAD_PORT, 0xFF);
}

uint8 KEYPAD_READ(void) {
	uint8 Value = NO_PRESSED_VALUE;
	uint8 KEYPAD_ROW_INDEX, KEYPAD_COLUMN_INDEX, KEYPAD_Pin_State;
	uint8 KEYPAD_ARR[KEYOAD_COL_IND4][KEYOAD_ROW_IND4] = KEYPAD_KEYS_4x4;
	uint8 KEYPAD_ROW_PinArr[KEYOAD_ROW_IND4] = { KEYPAD_ROW0, KEYPAD_ROW1, KEYPAD_ROW2, KEYPAD_ROW3 };
	uint8 KEYPAD_COL_PinArr[KEYOAD_COL_IND4] = { KEYPAD_COLUMN0, KEYPAD_COLUMN1,
			KEYPAD_COLUMN2,KEYPAD_COLUMN3 };
	for (KEYPAD_COLUMN_INDEX = 0; KEYPAD_COLUMN_INDEX < KEYOAD_COL_IND4;
			KEYPAD_COLUMN_INDEX++) {
		DIO_Write_Channel(KEYPAD_COL_PinArr[KEYPAD_COLUMN_INDEX],LOW);
		for (KEYPAD_ROW_INDEX = 0; KEYPAD_ROW_INDEX < KEYOAD_ROW_IND4;
				KEYPAD_ROW_INDEX++) {
			KEYPAD_Pin_State = DIO_Read_Channel(KEYPAD_ROW_PinArr[KEYPAD_ROW_INDEX]);
			if (LOW == KEYPAD_Pin_State) {
				Value = KEYPAD_ARR[KEYPAD_COLUMN_INDEX][KEYPAD_ROW_INDEX];
				while (LOW == DIO_Read_Channel(KEYPAD_ROW_PinArr[KEYPAD_ROW_INDEX]))
					;
				//DIO_WRITE_PIN_VALUE(KEYPAD_PORT, KEYPAD_COL_PinArr[KEYPAD_COLUMN_INDEX],HIGH);
				//return Value;
			}
		}
		DIO_Write_Channel(KEYPAD_COL_PinArr[KEYPAD_COLUMN_INDEX],
				HIGH);
	}
	return Value;
}
