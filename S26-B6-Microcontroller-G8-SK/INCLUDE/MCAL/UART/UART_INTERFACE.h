/*
 * UART_INTERFACE.h
 *
 *  Created on: Aug 29, 2026
 *      Author: hodam
 */

#ifndef INCLUDE_MCAL_UART_UART_INTERFACE_H_
#define INCLUDE_MCAL_UART_UART_INTERFACE_H_


typedef enum{
	UART_RX_INTERRUPT = 0,
	UART_UDRE_INTERRUPT ,
	UART_TX_INTERRUPT
}UART_INTERRUPTS;

void MUART_voidSetCallBack (UART_INTERRUPTS A_InterruptSource , void (*A_PtoFunc)(void));
u8 MUART_u8ReadByteSyncNonBlocking (void);
u8 MUART_u8ReadByteSyncBlocking (void);
void MUART_voidSendByteAsync (u8 A_u8DataByte);
void MUART_voidSendStringSyncNonBlocking (u8 *A_pu8String);
void MUART_voidSendByteSyncNonBlocking (u8 A_u8DataByte);
void MUART_voidSendByteSyncBlocking (u8 A_u8DataByte);
void MUART_voidInit(void);

#endif /* INCLUDE_MCAL_UART_UART_INTERFACE_H_ */
