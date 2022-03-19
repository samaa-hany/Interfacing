/*
 * MEMMAP.h
 *
 *  Created on: Dec 17, 2021
 *      Author: Samaa Seif
 */

#ifndef MEMMAP_H_
#define MEMMAP_H_

#include"STD_Types.h"

#define PORTA_Register *((volatile uint8*)0x3B)
#define DDRA_Register  *((volatile uint8*)0x3A)
#define PINA_Register  *((volatile uint8*)0x39)

#define PORTB_Register *((volatile uint8*)0x38)
#define DDRB_Register  *((volatile uint8*)0x37)
#define PINB_Register  *((volatile uint8*)0x36)

#define PORTC_Register *((volatile uint8*)0x35)
#define DDRC_Register  *((volatile uint8*)0x34)
#define PINC_Register  *((volatile uint8*)0x33)

#define PORTD_Register *((volatile uint8*)0x32)
#define DDRD_Register  *((volatile uint8*)0x31)
#define PIND_Register  *((volatile uint8*)0x30)

#define PORTA_Address ((volatile uint8*)   0x3B )
#define DDRA_Address  ((volatile uint8*)   0x3A )
#define PINA_Address  ((volatile uint8*)   0x39 )

#define PORTB_Address ((volatile uint8*)   0x38 )
#define DDRB_Address  ((volatile uint8*)   0x37 )
#define PINB_Address  ((volatile uint8*)   0x36 )

#define PORTC_Address ((volatile uint8*)   0x35 )
#define DDRC_Address  ((volatile uint8*)   0x34 )
#define PINC_Address  ((volatile uint8*)   0x33 )

#define PORTD_Address (volatile uint8*)   0x32
#define DDRD_Address  (volatile uint8*)   0x31
#define PIND_Address  (volatile uint8*)   0x30

/*Timer registers (Selection/Control/Data)*/
#define TCCR0  *((volatile uint8*)0x53)
#define TIMSK  *((volatile uint8*)0x59)
#define TCNT0  *((volatile uint8*)0x52)
#define OCR0   *((volatile uint8*)0x5C)

/*External Interrupt registers (Selection/Control/Data)*/
#define GICR_Register  *((volatile uint8*)0x5B)
#define MCUCR_Register  *((volatile uint8*)0x55)

/*UART Control Registers*/
#define UBRRL  *((volatile uint8*)0x29)
#define UCSRA  *((volatile uint8*)0x2B)
#define UCSRB  *((volatile uint8*)0x2A)
#define UCSRC  *((volatile uint8*)0x40)
#define UDR    *((volatile uint8*)0x2C)

/*Enable Global Interrupt*/
#define SREG   *((volatile uint16*)0x5F)

#endif /* MEMMAP_H_ */
