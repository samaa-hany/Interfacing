/*
 * DIO.h
 *
 *  Created on: Dec 24, 2021
 *      Author: Samaa Seif
 */

#ifndef DIO_H_
#define DIO_H_

void DIO_INIT(void);
void DIO_Write_Channel(uint8 CHANNEL,uint8 LEVEL);
void DIO_Write_Port(uint8 PORT,uint8 VALUE);
uint8 DIO_Read_Channel(uint8 CHANNEL);
uint8 DIO_Read_Port(uint8 PORT);


#endif /* DIO_H_ */
