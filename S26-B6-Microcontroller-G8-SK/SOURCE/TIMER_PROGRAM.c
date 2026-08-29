/*
 * TIMER_PROGRAM.c
 *
 *  Created on: Aug 25, 2026
 *      Author: Mahmoud Morsy
 */
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

#include "../INCLUDE/MCAL/TIMER/TIMER_PRIVATE.h"
#include "../INCLUDE/MCAL/TIMER/TIMER_INTERFACE.h"
#include "../INCLUDE/MCAL/TIMER/TIMER_CFG.h"

#define NULL 0

void (*TIMER0_OVF_CALLBACK)(void) = NULL;
void (*TIMER0_CTC_CALLBACK)(void) = NULL;

void MTIMER0_voidInit (void)
{
#if TIMER0_MODE == NORMAL_MODE
	// Set Wave Generation Mode to Normal Mode
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);

	// Turn on Overflow Interrupt
	SET_BIT(TIMSK,0);
	CLR_BIT(TIMSK,1);

	// Start Timer by setting its clock
	TCCR0 &= 0b11111000;
	TCCR0 |= TIMER0_CLK_CONFIGURATION;
#elif TIMER0_MODE == PHASE_CORRECT_MODE

#elif TIMER0_MODE == CTC_MODE
	// Set Wave Generation Mode to CTC Mode
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);

	// Turn on CTC Interrupt
	SET_BIT(TIMSK,1);
	CLR_BIT(TIMSK,0);

	// Set Compare Match unit Value
	OCR0 = OCR0_VALUE;
	// Start Timer by setting its clock and configure OC0 Pin Action
	TCCR0 &= 0b11001000;
	TCCR0 |= (TIMER0_CLK_CONFIGURATION | (TIMER0_CTC_OC0_PIN_MODE << 4));
#elif TIMER0_MODE == FAST_PWM_MODE
	// Set Wave Generation Mode
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	// Disable all interrupts
	CLR_BIT(TIMSK,1);
	CLR_BIT(TIMSK,0);
	// set OCR0 value
	OCR0 = OCR0_VALUE;
	// Start Timer by setting its clock and configure OC0 Pin Action
	TCCR0 &= 0b11001000;
	TCCR0 |= (TIMER0_CLK_CONFIGURATION | (TIMER0_PWM_OC0_PIN_MODE << 4));
#endif
}

void MTIMER0_voidSetPreloadValue (u8 A_u8NoOfTicks)
{
	TCNT0 = A_u8NoOfTicks;
}

void MTIMER0_voidSetOCR0Value (u8 A_u8OCR0Value)
{
	OCR0 = A_u8OCR0Value;
}

void MTIMER0_voidStopTimer (void)
{
	TCCR0 &= 0b11111000;
}

void MTIMER0_voidSetOVFCallback (void (*A_PtrToFunc)(void))
{
	if (A_PtrToFunc != NULL)
	{
		TIMER0_OVF_CALLBACK = A_PtrToFunc;
	}
}

void MTIMER0_voidSetCTCCallback (void (*A_PtrToFunc)(void))
{
	if (A_PtrToFunc != NULL)
	{
		TIMER0_CTC_CALLBACK = A_PtrToFunc;
	}
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if (TIMER0_OVF_CALLBACK != NULL)
	{
		TIMER0_OVF_CALLBACK();
	}
}


void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if (TIMER0_CTC_CALLBACK != NULL)
	{
		TIMER0_CTC_CALLBACK();
	}
}

















