/*
 * WDT_PROGRAM.c
 *
 *  Created on: Aug 30, 2026
 *      Author: hodam
 */


#include <util/delay.h>
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

#include "../INCLUDE/MCAL/WDT/WDT_INTERFACE.h"
#include "../INCLUDE/MCAL/WDT/WDT_PRIVATE.h"
#include "../INCLUDE/MCAL/WDT/WDT_CFG.h"


void MWDT_voidEnable(void)
{
	//Enable WDT and Set reset time to 2.1 sec
	WDTCR = 0b00001111;
}

void MWDT_voidDisable (void)
{
	WDTCR |= ((1<<3)|(1<<4));
	WDTCR = 0x00;
}
