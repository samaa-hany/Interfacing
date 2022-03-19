/*
 * 7seg.h
 *
 *  Created on: Dec 18, 2021
 *      Author: Samaa Seif
 */

#ifndef SEV_SEG_H_
#define SEV_SEG_H_

#define Comm_Anode  1
#define Comm_Cathod 0

#define SEG_Type Comm_Cathod
#define SEG_PORT PORTA

#define RED_LED     PORTC0
#define YELLOW_LED  PORTC1
#define GREEN_LED   PORTC2
#define R_LED  1
#define G_LED  0

void SEV_SEG_INIT(void);
void SEV_Segment_Display(uint8 Num);

#endif /* 7SEG_H_ */
