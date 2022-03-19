/*
 * DIO.h
 *
 *  Created on: Dec 18, 2021
 *      Author: Samaa Seif
 */

#ifndef DIO_H_
#define DIO_H_


void DIO_INIT_PORT_DIRECTION (uint8 PORT,uint8 DIRECTION);
void DIO_WRITE_PORT_VALUE (uint8 PORT,uint8 VALUE);
uint8 DIO_READ_PORT_VALUE (uint8 PORT);


void DIO_INIT_PIN_DIRECTION (uint8 PORT,uint8 PINno,uint8 DIRECTION);
void DIO_WRITE_PIN_VALUE (uint8 PORT,uint8 PINno, uint8 VALUE);
uint8 DIO_READ_PIN_VALUE(uint8 PORT,uint8 PINno);



#endif /* DIO_H_ */
