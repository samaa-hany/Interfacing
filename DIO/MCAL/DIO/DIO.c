/*
 * DIO.c
 *
 *  Created on: Dec 18, 2021
 *      Author: Samaa Seif
 */
#include"STD_Types.h"
#include"MEMMAP.h"
#include"BIT_MATH.h"
#include"main.h"
#include"DIO.h"
#include"DIO_CONFIG.h"

void DIO_INIT_PORT_DIRECTION(uint8 PORT, uint8 DIRECTION) {
	if (DIRECTION == INPUT) {
		switch (PORT) {
		case PORT_A:
			DDRA_Register = 0x00;
			break;
		case PORT_B:
			DDRB_Register = 0x00;
			break;
		case PORT_C:
			DDRC_Register = 0x00;
			break;
		case PORT_D:
			DDRD_Register = 0x00;
			break;
		}
	} else if (DIRECTION == OUTPUT) {
		switch (PORT) {
		case PORT_A:
			DDRA_Register = 0xFF;
			break;
		case PORT_B:
			DDRB_Register = 0xFF;
			break;
		case PORT_C:
			DDRC_Register = 0xFF;
			break;
		case PORT_D:
			DDRD_Register = 0xFF;
			break;
		}
	}
}
void DIO_WRITE_PORT_VALUE(uint8 PORT, uint8 VALUE) {

	switch (PORT) {
	case PORT_A:
		PORTA_Register = VALUE;
		break;
	case PORT_B:
		PORTB_Register = VALUE;
		break;
	case PORT_C:
		PORTC_Register = VALUE;
		break;
	case PORT_D:
		PORTB_Register = VALUE;
		break;
	}
}

uint8 DIO_READ_PORT_VALUE(uint8 PORT) {
	uint8 val;
	switch (PORT) {
	case PORT_A:
		val = PINA_Register;
		break;
	case PORT_B:
		val = PINB_Register;
		break;
	case PORT_C:
		val = PINC_Register;
		break;
	case PORT_D:
		val = PIND_Register;
		break;
	}
	return val;
}
void DIO_INIT_PIN_DIRECTION(uint8 PORT, uint8 PINno, uint8 DIRECTION) {
	if (DIRECTION == INPUT) {
		switch (PORT) {
		case PORT_A:
			CLR_BIT(DDRA_Register, PINno);
			break;
		case PORT_B:
			CLR_BIT(DDRB_Register, PINno);
			break;
		case PORT_C:
			CLR_BIT(DDRC_Register, PINno);
			break;
		case PORT_D:
			CLR_BIT(DDRD_Register, PINno);
			break;
		}
	} else if (DIRECTION == OUTPUT) {
		switch (PORT) {
		case PORT_A:
			SET_BIT(DDRA_Register, PINno);
			break;
		case PORT_B:
			SET_BIT(DDRB_Register, PINno);
			break;
		case PORT_C:
			SET_BIT(DDRC_Register, PINno);
			break;
		case PORT_D:
			SET_BIT(DDRD_Register, PINno);
			break;
		}
	}
}
void DIO_WRITE_PIN_VALUE(uint8 PORT, uint8 PINno, uint8 VALUE) {
	if (VALUE == HIGH ) {
		switch (PORT) {
		case PORT_A:
			SET_BIT(PORTA_Register, PINno);
			break;
		case PORT_B:
			SET_BIT(PORTB_Register, PINno);
			break;
		case PORT_C:
			SET_BIT(PORTC_Register, PINno);
			break;
		case PORT_D:
			SET_BIT(PORTD_Register, PINno);
			break;
		}
	}
	if (VALUE == LOW) {
		switch (PORT) {
		case PORT_A:
			CLR_BIT(PORTA_Register, PINno);
			break;
		case PORT_B:
			CLR_BIT(PORTB_Register, PINno);
			break;
		case PORT_C:
			CLR_BIT(PORTC_Register, PINno);
			break;
		case PORT_D:
			CLR_BIT(PORTD_Register, PINno);
			break;
		}
	}
}
uint8 DIO_READ_PIN_VALUE(uint8 PORT, uint8 PINno) {
	uint8 val;
	switch (PORT) {
	case PORT_A:
		val=GET_BIT(PORTA_Register, PINno);
		break;
	case PORT_B:
		val=GET_BIT(PORTB_Register, PINno);
		break;
	case PORT_C:
		val=GET_BIT(PORTC_Register, PINno);
		break;
	case PORT_D:
		val=GET_BIT(PORTD_Register, PINno);
		break;
	}
	return val;
}


