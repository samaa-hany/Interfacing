/*
 * Interrupt.h
 *
 *  Created on: Dec 31, 2021
 *      Author: Samaa Seif
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_


typedef enum{
	INT2=5,
	INT0=6,
	INT1=7
}SRC_EXTI_INT;

typedef enum {
	Low_Level,
	Logical_Change,
	Falling_Edge,
	Rising_Edge
}TRIG_EXTI_INT;

#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define ISC2  6


extern void EXTI_INIT(const SRC_EXTI_INT EXINT_PIN);
extern void EXTI_deINIT(const SRC_EXTI_INT EXINT_PIN);
extern void EXTI_TRIG(const SRC_EXTI_INT EXINT_Mode, const TRIG_EXTI_INT EDGE);


#endif /* INTERRUPT_H_ */
