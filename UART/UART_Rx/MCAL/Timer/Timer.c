/*
 * Timer.c
 *
 *  Created on: Jan 8, 2022
 *      Author: Samaa Seif
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO_Confg.h"
#include "DIO.h"
#include "Timer.h"


void TIMER_Set_Prescaler(const TIMER_Prescaler PRESCALER) {
	TCCR0 |= PRESCALER;
}

void TIMER_MODE(const TIMER_Mode MODE) {
	switch (MODE) {
	case T_NORMAL:
		CLR_BIT(TCCR0, T3);
		CLR_BIT(TCCR0, T6);
		break;
	case T_PWM:
		CLR_BIT(TCCR0, T3);
		SET_BIT(TCCR0, T6);
		break;
	case T_CTC:
		SET_BIT(TCCR0, T3);
		CLR_BIT(TCCR0, T6);
		break;
	case T_FAST_PWM:
		SET_BIT(TCCR0, T3);
		SET_BIT(TCCR0, T6);
		break;
	}
}
void TIMER_INIT(void) {
	TCNT0 = 0;
	OCR0 = 0;
}
void TIMER_INT(const TIMER_EN_INT INT) {
	switch (INT) {
	case T_OV_INT_ENABLE:
		SET_BIT(TIMSK, 0);
		break;
	case T_OV_INT_DISABLE:
		CLR_BIT(TIMSK, 0);
		break;
	case T_OC_INT_ENABLE:
		SET_BIT(TIMSK, 1);
		break;
	case T_OC_INT_DISABLE:
		CLR_BIT(TIMSK, 1);
		break;
	}
}


