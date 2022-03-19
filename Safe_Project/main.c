/*
 * main.c
 *
 *  Created on: Dec 26, 2021
 *      Author: Samaa Seif
 */
#include"STD_Types.h"
#include"BIT_MATH.h"
#include"MEMMAP.h"
#include"DIO_Confg.h"
#include"DIO.h"
#include"LCD_Confg.h"
#include"LCD.h"
#include"KEYPAD.h"
#include"Safe_hdlr.h"
#include"Safe.h"
#include"util/delay.h"



uint8 main(void) {
	DIO_INIT();
	KEYPAD_INIT();
	LCD_vidInit();
	//Safe_Main();
	while(1){
	Safe_MainFunction();
	}
	return 0;
}

