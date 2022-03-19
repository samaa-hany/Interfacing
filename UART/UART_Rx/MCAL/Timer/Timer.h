/*
 * Timer.h
 *
 *  Created on: Jan 8, 2022
 *      Author: Samaa Seif
 */

#ifndef TIMER_H_
#define TIMER_H_

void Timer_INIT(void);

#define T0 0
#define T1 1
#define T2 2
#define T3 3
#define T4 4
#define T5 5
#define T6 6
#define T7 7

typedef enum{
	T_NO_CLK = 0,
	T_PRE_1,
	T_PRE_8,
	T_PRE_64,
	T_PRE_256,
	T_PRE_1024,
	T_Falling_Edge,
	T_Rising_Edge
}TIMER_Prescaler;

typedef enum{
	T_NORMAL = 0,
	T_PWM,
	T_CTC,
	T_FAST_PWM
}TIMER_Mode;

typedef enum{
	T_OV_INT_ENABLE = 0,
	T_OV_INT_DISABLE,
	T_OC_INT_ENABLE,
	T_OC_INT_DISABLE
}TIMER_EN_INT;

extern void TIMER_Set_Prescaler(const TIMER_Prescaler PRESCALER);
extern void TIMER_MODE(const TIMER_Mode MODE);
extern void TIMER_INIT(void);
extern void TIMER_INT(const TIMER_EN_INT INT);

#endif /* TIMER_H_ */
