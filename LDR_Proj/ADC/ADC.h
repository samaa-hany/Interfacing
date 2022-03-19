/*
 * ADC.h
 *
 *  Created on: Jan 7, 2022
 *      Author: Samaa Seif
 */

#ifndef ADC_H_
#define ADC_H_

void ADC_INIT(void);
void ADC_StartConversion(void);
uint16 ADC_Read(void);

#define CH0   0
#define CH1   1
#define CH2   2
#define CH3   3
#define CH4   4
#define CH5   5
#define CH6   6
#define CH7   7

#define LED1  PORT_B0
#define LED2  PORT_B1
#define LED3  PORT_B2
#define LED4  PORT_B3

#define Vref  5
#define V  5
#define R  1000

#endif /* ADC_H_ */
