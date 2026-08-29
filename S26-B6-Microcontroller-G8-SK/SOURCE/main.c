/*
 * main.c
 *
 *  Created on: Aug 18, 2026
 *      Author: Mahmoud Morsy
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

// KEYPAD Directives
#include "../INCLUDE/HAL/KEYPAD/KEYPAD_CFG.h"
#include "../INCLUDE/HAL/KEYPAD/KEYPAD_PRIVATE.h"
#include "../INCLUDE/HAL/KEYPAD/KEYPAD_INTERFACE.h"


#include "../INCLUDE/MCAL/TIMER/TIMER_INTERFACE.h"

#define F_CPU 8000000UL

void TIMER0_OVF_FUNC (void)
{
	static u16 LOCAL_u16counter =0;
	LOCAL_u16counter++;
	if (LOCAL_u16counter == 3907)
	{
		MTIMER0_voidSetPreloadValue(192);
		LOCAL_u16counter=0;
		//HLED_voidToggleLedStatus(PORTA, PIN0);
	}
}

void TIMER0_CTC_FUNC (void)
{
	static u16 LOCAL_u16counter =0;
	LOCAL_u16counter++;
	if (LOCAL_u16counter == 10000)
	{
		LOCAL_u16counter=0;
		//HLED_voidToggleLedStatus(PORTA, PIN0);
	}
}

// OVF Main
//int main (void)
//{
//	MDIO_voidInit();
//	MTIMER0_voidSetOVFCallback(TIMER0_OVF_FUNC);
//	MTIMER0_voidInit();
//	MTIMER0_voidSetPreloadValue(192);
//	MGI_voidEnable();
//	while(1)
//	{
//
//	}
//}


//// CTC Main
//int main (void)
//{
//	MDIO_voidInit();
//	MTIMER0_voidSetOVFCallback(TIMER0_CTC_FUNC);
//	MTIMER0_voidInit();
//	MGI_voidEnable();
//	while(1)
//	{
//
//	}
//}


// Fast PWM Main
int main (void)
{
	MDIO_voidInti();
	MTIMER0_voidInit();
	while(1)
	{
		for (u8 i=0; i<250; i+=10)
		{
			MTIMER0_voidSetOCR0Value(i);
			_delay_ms (300);
		}
		for (u8 i=250; i>0; i -=10)
		{
			MTIMER0_voidSetOCR0Value(i);
			_delay_ms (300);
		}
	}
}

