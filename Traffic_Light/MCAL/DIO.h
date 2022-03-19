/*
 * DIO.h
 *
 *  Created on: Dec 24, 2021
 *      Author: Samaa Seif
 */

#ifndef DIO_H_
#define DIO_H_

extern void DIO_INIT(void);
extern void DIO_Write_Channel(uint8 CHANNEL,uint8 LEVEL);
extern void DIO_Write_Port(uint8 PORT,uint8 VALUE);
extern uint8 DIO_Read_Channel(uint8 CHANNEL);
extern uint8 DIO_Read_Port(uint8 PORT);
extern void DIO_INIT_PIN(void);


#endif /* DIO_H_ */
