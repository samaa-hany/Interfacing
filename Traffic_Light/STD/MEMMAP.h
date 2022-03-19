/*
 * MEMMAP.h
 *
 *  Created on: Dec 17, 2021
 *      Author: Samaa Seif
 */

#ifndef MEMMAP_H_
#define MEMMAP_H_


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

#define PORTA_Address (volatile uint8*)   0x3B
#define DDRA_Address  (volatile uint8*)   0x3A
#define PINA_Address  (volatile uint8*)   0x39

#define PORTB_Address (volatile uint8*)   0x38
#define DDRB_Address  (volatile uint8*)   0x37
#define PINB_Address  (volatile uint8*)   0x36

#define PORTC_Address (volatile uint8*)   0x35
#define DDRC_Address  (volatile uint8*)   0x34
#define PINC_Address  (volatile uint8*)   0x33

#define PORTD_Address (volatile uint8*)   0x32
#define DDRD_Address  (volatile uint8*)   0x31
#define PIND_Address  (volatile uint8*)   0x30


#endif /* MEMMAP_H_ */
