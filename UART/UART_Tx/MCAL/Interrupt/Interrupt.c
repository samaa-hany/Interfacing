/*
 * Interrupt.c
 *
 *  Created on: Dec 31, 2021
 *      Author: Samaa Seif
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO_Confg.h"
#include "DIO.h"
#include "Interrupt.h"

void EXTI_INIT(const SRC_EXTI_INT EXINT_PIN) {
	switch (EXINT_PIN) {
	case INT0:
		SET_BIT(GICR_Register, INT0);
		break;
	case INT1:
		SET_BIT(GICR_Register, INT1);
		break;
	case INT2:
		SET_BIT(GICR_Register, INT2);
		break;
	}
}

void EXTI_deINIT(const SRC_EXTI_INT EXINT_PIN) {
	switch (EXINT_PIN) {
	case INT0:
		CLR_BIT(GICR_Register, INT0);
		break;
	case INT1:
		CLR_BIT(GICR_Register, INT1);
		break;
	case INT2:
		CLR_BIT(GICR_Register, INT2);
		break;
		CLR_BIT(MCUCR_Register, ISC00);
		CLR_BIT(MCUCR_Register, ISC01);
		CLR_BIT(MCUCR_Register, ISC10);
		CLR_BIT(MCUCR_Register, ISC11);
	}
}

void EXTI_TRIG(const SRC_EXTI_INT EXINT_Mode, const TRIG_EXTI_INT EDGE) {

	switch (EXINT_Mode) {
	case INT0:
		switch (EDGE) {
		case Low_Level:
			CLR_BIT(MCUCR_Register, ISC00);
			CLR_BIT(MCUCR_Register, ISC01);
			break;
		case Logical_Change:
			SET_BIT(MCUCR_Register, ISC00);
			CLR_BIT(MCUCR_Register, ISC01);
			break;
		case Falling_Edge:
			CLR_BIT(MCUCR_Register, ISC00);
			SET_BIT(MCUCR_Register, ISC01);
			break;
		case Rising_Edge:
			SET_BIT(MCUCR_Register, ISC00);
			SET_BIT(MCUCR_Register, ISC01);
			break;
		}
		break;
	case INT1:
		switch (EDGE) {
		case Low_Level:
			CLR_BIT(MCUCR_Register, ISC10);
			CLR_BIT(MCUCR_Register, ISC11);
			break;
		case Logical_Change:
			SET_BIT(MCUCR_Register, ISC10);
			CLR_BIT(MCUCR_Register, ISC11);
			break;
		case Falling_Edge:
			CLR_BIT(MCUCR_Register, ISC10);
			SET_BIT(MCUCR_Register, ISC11);
			break;
		case Rising_Edge:
			SET_BIT(MCUCR_Register, ISC10);
			SET_BIT(MCUCR_Register, ISC11);
			break;
		}
		break;
	case INT2:
		switch (EDGE) {
		case Falling_Edge:
			CLR_BIT(MCUCR_Register, ISC2);
			break;
		case Rising_Edge:
			SET_BIT(MCUCR_Register, ISC2);
			break;
		default:
			CLR_BIT(MCUCR_Register, ISC2);
		}
		break;
	}
}
