/*
 * ADC_PRIVATE.h
 *
 *  Created on: Aug 29, 2026
 *      Author: hodam
 */

#ifndef INCLUDE_ADC_ADC_PRIVATE_H_
#define INCLUDE_ADC_ADC_PRIVATE_H_

#define ADMUX  (*(volatile u8 *)0x27)
#define ADCSRA (*(volatile u8 *)0x26)
#define ADCH   (*(volatile u8 *)0x25)
#define ADCL   (*(volatile u8 *)0x24)
#define ADCLH  (*(volatile u16 *)0x24)

#define ADC_CHANNEL_MASK 0b11100000

#endif /* INCLUDE_ADC_ADC_PRIVATE_H_ */
