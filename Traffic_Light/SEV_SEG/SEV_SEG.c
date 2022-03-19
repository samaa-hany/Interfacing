/*
 * 7seg.c
 *
 *  Created on: Dec 18, 2021
 *      Author: Samaa Seif
 */
#include"STD_Types.h"
#include"MEMMAP.h"
#include"BIT_MATH.h"
#include"DIO.h"
#include"DIO_Confg.h"
#include"SEV_SEG.h"
#include"util/delay.h"

void SEV_SEG_INIT(void) {
	DIO_Write_Port(SEG_PORT,OUTPUT);
}

uint8 Dpy_Cathod[10] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F,
		0x6F };
uint8 Dpy_Anade[10] = { 0x80, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00,
		0x10 };
void SEV_Segment_Display(uint8 Num) {
#if SEG_Type == Comm_Anode
	DIO_Write_Port(SEG_PORT, Dpy_Anade[Num]);
#elif (SEG_Type == Comm_Cathod)
	DIO_Write_Port(SEG_PORT, Dpy_Cathod[Num]);
#endif
}
