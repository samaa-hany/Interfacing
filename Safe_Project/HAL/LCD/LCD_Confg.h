/*
 * LCD_Confg.h
 *
 *  Created on: Dec 25, 2021
 *      Author: Samaa Seif
 */

#ifndef LCD_CONFG_H_
#define LCD_CONFG_H_

#define RS   PORTA0
#define RW   PORTA1
#define E    PORTA2

typedef enum{
	CGRAM_ROW1 = 0,
	CGRAM_ROW2,
	CGRAM_ROW3,
	CGRAM_ROW4,
	CGRAM_ROW5,
	CGRAM_ROW6,
	CGRAM_ROW7,
	CGRAM_ROW8,
	CGRAM_MAX_ROWS
}CGRAM_ROW_ID_t;

#define LCD_PORT   PORTB




#endif /* LCD_CONFG_H_ */
