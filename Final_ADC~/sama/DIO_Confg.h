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
	PORTA0 = 0,       //PORT A pins
	PORTA1,
	PORTA2,
	PORTA3,
	PORTA4,
	PORTA5,
	PORTA6,
	PORTA7,

	PORTB0,          //PORT B pins
	PORTB1,
	PORTB2,
	PORTB3,
	PORTB4,
	PORTB5,
	PORTB6,
	PORTB7,

	PORTC0,
	PORTC1,
	PORTC2,
	PORTC3,
	PORTC4,
	PORTC5,
	PORTC6,
	PORTC7,

	PORTD0,
	PORTD1,
	PORTD2,
	PORTD3,
	PORTD4,
	PORTD5,
	PORTD6,
	PORTD7,
	PIN_Limit
} DIO_ENU_PIN_Name;

#define HIGH 1
#define LOW  0

#define PINS_NO  32

extern DIO_ENU_PIN_STATE DIO_PIN_CONFG[PINS_NO];

#endif /* DIO_CONFG_H_ */
