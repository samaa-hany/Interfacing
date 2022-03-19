/*
 * DIO.c
 *
 *  Created on: Dec 24, 2021
 *      Author: Samaa Seif
 */
#include"STD_Types.h"
#include"BIT_MATH.h"
#include"MEMMAP.h"
#include"DIO.h"
#include"DIO_Confg.h"

uint8 *REG_ARR[12] = { DDRA_Address, DDRB_Address, DDRC_Address, DDRD_Address,
		PORTA_Address, PORTB_Address, PORTC_Address, PORTD_Address,
		PINA_Address, PINB_Address, PINC_Address, PIND_Address };



void DIO_INIT(void) {
	uint8 PIN_STATE;
	uint8 PIN_VALUE, PORT_STATE;
	for (uint8 i = 0; i < PIN_Limit; i++) {
		PIN_STATE = DIO_PIN_CONFG[i];
		PIN_VALUE = i % 8;
		PORT_STATE = i / 8;
		switch (PIN_STATE) {
		case OUTPUT:
			SET_BIT(*REG_ARR[PORT_STATE], PIN_VALUE);
			break;
		case INPUT_PULLUP:
			CLR_BIT(*REG_ARR[PORT_STATE], PIN_VALUE);
			SET_BIT(*REG_ARR[PORT_STATE + 4], PIN_VALUE);
			break;
		case INPUT_FLOATING:
			CLR_BIT(*REG_ARR[PORT_STATE], PIN_VALUE);
			break;
		}
	}
}

/*void DIO_INIT_PIN(uint8 Channel, uint8 PIN_STATE) {
	uint8 PIN_VALUE = Channel % 8;
	uint8 PORT_STATE = Channel / 8;
	switch (PIN_STATE) {
	case OUTPUT:
		SET_BIT(*REG_ARR[PORT_STATE], PIN_VALUE);
		break;
	case INPUT_PULLUP:
		CLR_BIT(*REG_ARR[PORT_STATE], PIN_VALUE);
		SET_BIT(*REG_ARR[PORT_STATE + 4], PIN_VALUE);
		break;
	case INPUT_FLOATING:
		CLR_BIT(*REG_ARR[PORT_STATE], PIN_VALUE);
		CLR_BIT(*REG_ARR[PORT_STATE+4], PIN_VALUE);
		break;
	}
}*/

void DIO_Write_Channel(uint8 CHANNEL, uint8 LEVEL) {
	uint8 PIN_STATE = CHANNEL % 8;
	uint8 PORT_STATE = CHANNEL / 8;
	switch (LEVEL) {
	case HIGH:
		SET_BIT(*REG_ARR[PORT_STATE + 4], PIN_STATE);
		break;
	case LOW:
		CLR_BIT(*REG_ARR[PORT_STATE + 4], PIN_STATE);
		break;
	}
}

void DIO_Write_Port(uint8 PORT, uint8 VALUE) {

	*REG_ARR[PORT + 4] = VALUE;
}

uint8 DIO_Read_Channel(uint8 CHANNEL) {
	uint8 PIN_STATE, val;
	uint8 PORT_STATE;

	PIN_STATE = CHANNEL % 8;
	PORT_STATE = CHANNEL / 8;
	val = GET_BIT(*REG_ARR[PORT_STATE + 8], PIN_STATE);

	return val;
}

uint8 DIO_Read_Port(uint8 PORT) {
	uint8 val;
	val = *REG_ARR[PORT + 8];
	return val;
}
