/*
 * DIO_Confg.h
 *
 *  Created on: Dec 24, 2021
 *      Author: Samaa Seif
 */

#ifndef DIO_CONFG_H_
#define DIO_CONFG_H_

typedef enum {
	OUTPUT=0, INPUT_PULLUP,INPUT_FLOATING
} DIO_ENU_PIN_STATE;

typedef enum {
	PORTA = 0, PORTB, PORTC, PORTD
} DIO_ENU_PORT_Name;

typedef enum {
	PORT_A0 = 0,       //PORT A pins
	PORT_A1,
	PORT_A2,
	PORT_A3,
	PORT_A4,
	PORT_A5,
	PORT_A6,
	PORT_A7,

	PORT_B0,          //PORT B pins
	PORT_B1,
	PORT_B2,
	PORT_B3,
	PORT_B4,
	PORT_B5,
	PORT_B6,
	PORT_B7,

	PORT_C0,
	PORT_C1,
	PORT_C2,
	PORT_C3,
	PORT_C4,
	PORT_C5,
	PORT_C6,
	PORT_C7,

	PORT_D0,
	PORT_D1,
	PORT_D2,
	PORT_D3,
	PORT_D4,
	PORT_D5,
	PORT_D6,
	PORT_D7,
	PIN_Limit
} DIO_ENU_PIN_Name;

#define HIGH 1
#define LOW  0

#define PINS_NO  32

extern DIO_ENU_PIN_STATE DIO_PIN_CONFG[PINS_NO];

#endif /* DIO_CONFG_H_ */
