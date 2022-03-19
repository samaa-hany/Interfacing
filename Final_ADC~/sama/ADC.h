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

#define LED1  8
#define LED2  9
#define LED3  10

#define Vref  5

#endif /* ADC_H_ */
