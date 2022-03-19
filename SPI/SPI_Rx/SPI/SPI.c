/*
 * SPI.c
 *
 *  Created on: Jan 22, 2022
 *      Author: Samaa Seif
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO_Confg.h"
#include "DIO.h"
#include "SPI.h"

void SPI_INIT_MODE(DATA_Order Bit, SPI_Mode Mode) {
	/* Enable SPI, Master with clock rate fosc/4 */
	SET_BIT(SPCR, SPE);
	switch (Bit) {
	case LSB:
		SET_BIT(SPCR, DORD);
		break;
	case MSB:
		CLR_BIT(SPCR, DORD);
		break;
	}
	switch (Mode) {
	case Master:
		SET_BIT(SPCR, MSTR);
		break;
	case Slave:
		CLR_BIT(SPCR, MSTR);
		break;
	}
}

void SPI_Interruprt(SPI_INT Int) {
	switch (Int) {
	case Enable:
		/*Enable SPI Interrupt*/
		SET_BIT(SPCR, SPIE);
		SET_BIT(SREG,7);
		break;
		/*Disable SPI Interrupt*/
	case Disable:
		CLR_BIT(SPCR, SPIE);
		CLR_BIT(SREG,7);
		break;
	}
}

void SPI_Send_Data(uint8 Data) {

	/* Start transmission */
	SPDR = Data;

	/* Wait for transmission complete */
	while (!(SPSR & (1 << SPIF)))
		;
}

uint8 SPI_Receive_Data(void) {
	/* Wait for reception complete */
	while (!(SPSR & (1 << SPIF)))
		;
	/* Return data register */
	return SPDR;
}


uint8 SPI_Receive_Data_With_Interrupt(void) {
	/* Return data register */
	return SPDR;
}
