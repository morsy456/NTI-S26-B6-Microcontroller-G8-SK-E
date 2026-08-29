/*
 * TIMER1_PROGRAM.c
 *
 *  Created on: Aug 29, 2026
 *      Author: hodam
 */

// liberary Directives
#include "../INCLUDE/LIB/BIT_MATH.h"
#include "../INCLUDE/LIB/STD_TYPES.h"

// DIO Directives
#include "../INCLUDE/MCAL/DIO/DIO_PRIVATE.h"
#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"
#include "../INCLUDE/MCAL/DIO/DIO_CFG.h"
#include<stdio.h>
#include<util/delay.h>
#include "../INCLUDE/MCAL/TIMER1/TIMER1_CFG.h"
#include "../INCLUDE/MCAL/TIMER1/TIMER1_PRIVATE.h"
#include "../INCLUDE/MCAL/TIMER1/TIMER1_INTERFACE.h"

#define NULL 0

void (*TIMER1_ICU_CallBack)(void)= NULL;


void MTIMERS_voidTimer1Init(void)
{
	/*Set prescaler*/
	CLR_BIT(TCCR1B,2);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,0);
}
void MTIMERS_voidSetTimer1Value(u16 A_u16Value)
{
	TCNT1=A_u16Value;
}

u16 MTIMERS_u16ReadTimer1Value(void)
{
	return TCNT1;
}
void MTIMERS_voidSetCR1AValue(u8 A_u8Value)
{
	OCR1A=A_u8Value;
}

void TIMER1_voidICUInit(void)
{
	// Set Trigger to Rising Initially
	SET_BIT(TCCR1B,6);
	// Enable ICU Interrupt
	SET_BIT(TIMSK,5);
}

void TIMER1_voidICUSetCallBack(void (*ptrToFunc) (void))
{
	if (ptrToFunc!= NULL)
		{
			TIMER1_ICU_CallBack=ptrToFunc;
		}
}

void TIMER1_voidICUSetTrigger(u8 A_u8Trigger)
{
	switch (A_u8Trigger)
	{
			case ICU_FALLING_EDGE : CLR_BIT(TCCR1B,6); break;
			case ICU_RISING_EDGE : SET_BIT(TCCR1B,6); break;

	}
}

u16 TIMER1_u16ReadICU(void)
{
	return ICR1;
}
void TIMER1_voidICUDisableINT(void)
{
	// Disable ICU Interrupt
		CLR_BIT(TIMSK,5);
}

void __vector_6(void)  __attribute__((signal));
void __vector_6(void)
{
	if (TIMER1_ICU_CallBack!= NULL)
	{
		TIMER1_ICU_CallBack();
	}
}
