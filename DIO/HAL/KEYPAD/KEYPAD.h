/*
 * KEYPAD.h
 *
 *  Created on: Dec 23, 2021
 *      Author: Samaa Seif
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#define NO_PRESSED_VALUE	0xFF
#define KEYPAD_SIZE_3x3      HIGH
#define KEYPAD_SIZE_4x4      LOW
#define KEYOAD_COL_IND3      3
#define KEYOAD_ROW_IND3      3
#define KEYOAD_ROW_IND4      4
#define KEYOAD_COL_IND4      4

#define KEYPAD_PORT      PORT_C
/*
#ifdef  KEYPAD_SIZE_3x3==HIGH*/

#define KEYPAD_ROW0	     0
#define KEYPAD_ROW1	     1
#define KEYPAD_ROW2	     2

#define KEYPAD_COLUMN0	 4
#define KEYPAD_COLUMN1	 5
#define KEYPAD_COLUMN2	 6

#define KEYPAD_KEYS_3x3 {{1,2,3},{4,5,6},{7,8,9}}
/*
#ifdef KEYPAD_SIZE_4x4==HIGH

#define KEYPAD_ROW0	     PIN0
#define KEYPAD_ROW1	     PIN1
#define KEYPAD_ROW2	     PIN2
#define KEYPAD_ROW3	     PIN3

#define KEYPAD_COLUMN0	 PIN4
#define KEYPAD_COLUMN1	 PIN5
#define KEYPAD_COLUMN2	 PIN6
#define KEYPAD_COLUMN3	 PIN7
#define KEYPAD_KEYS_3x3 {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}
#endif*/

uint8 KEYPAD_READ(void);
void KEYPAD_INIT(void);

#endif /* KEYPAD_H_ */
