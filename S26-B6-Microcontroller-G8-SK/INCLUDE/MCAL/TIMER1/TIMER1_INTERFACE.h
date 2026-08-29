/*
 * TIMER1_INTERFACE.h
 *
 *  Created on: Aug 29, 2026
 *      Author: hodam
 */

#ifndef INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_
#define INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_


#define ICU_FALLING_EDGE  0
#define ICU_RISING_EDGE   1

void MTIMERS_voidTimer1Init(void);

void MTIMERS_voidSetCR1AValue(u8 A_u8Value);

#endif /* INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_ */
