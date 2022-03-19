/*
 * LCD.h
 *
 *  Created on: Dec 25, 2021
 *      Author: Samaa Seif
 */

#ifndef LCD_H_
#define LCD_H_


#define lcd_CLR       0x01
#define lcd_HOME      0x02
#define lcd_ENT_MODE  0x06
#define lcd_DPY_OFF   0x08
#define lcd_DPY_ON    0x0C
#define lcd_RESET     0x30
#define lcd_SET       0x38
#define lcd_CURSER    0x80

extern void LCD_vidInit(void);
extern void LCD_vidSendCommand(uint8 Cmd);
extern void LCD_vidSendData(uint8 Data);
extern void LCD_vidWriteString(uint8* Stg, uint8 Ind);
extern void LCD_vidGotoXY(uint8 X, uint8 Y);
extern void LCD_vidWriteExtraChar(uint8 Row, uint8 Col);


#endif /* LCD_H_ */
