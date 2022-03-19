/*
 * UART.h
 *
 *  Created on: Jan 21, 2022
 *      Author: Samaa Seif
 */

#ifndef UART_H_
#define UART_H_


extern void UART_INIT(uint16 baud);
extern void UART_Send_Char(uint8 data);
extern uint8 UART_Receive_Char(void);
extern uint8 UART_Receiver_With_Interrupt(void);
extern uint8 UART_Receive_String(void);
extern void UART_Send_String(uint8* data, uint8 Length);

#define  Uart0  0
#define  Uart1  1
#define  Uart2  2
#define  Uart3  3
#define  Uart4  4
#define  Uart5  5
#define  Uart6  6
#define  Uart7  7

#define  USART_RXC_vect  _VECTOR(13)

#endif /* UART_H_ */
