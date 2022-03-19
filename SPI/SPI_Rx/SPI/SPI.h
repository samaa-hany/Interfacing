/*
 * SPI.h
 *
 *  Created on: Jan 22, 2022
 *      Author: Samaa Seif
 */

#ifndef SPI_H_
#define SPI_H_

#define SPE  6
#define DORD 5
#define MSTR 4

#define SPIF 7
#define SPIE 7

/*Data Order Options: 1-Master
 * 					  2-Slave*/
typedef enum{
	Master,
	Slave
}SPI_Mode;

/*Data Order Options: 1-LSB
 * 					  2-MSB*/
typedef enum {
	LSB,
	MSB
}DATA_Order;

/*SPI Interrupt Options: 1-Enable
 * 						 2-Disable*/
typedef enum {
	Enable,
	Disable
}SPI_INT;

extern void SPI_INIT_MODE(DATA_Order Bit, SPI_Mode Mode);
extern void SPI_Send_Data(uint8 Data);
extern uint8 SPI_Receive_Data(void);
extern uint8 SPI_Receive_Data_With_Interrupt(void);
extern void SPI_Interruprt(SPI_INT Int);

#endif /* SPI_H_ */
