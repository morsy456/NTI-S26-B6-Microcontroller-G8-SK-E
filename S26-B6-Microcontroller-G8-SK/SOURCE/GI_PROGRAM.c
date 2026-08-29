/*
 * GI_PROGRAM.c
 *
 *  Created on: Apr 30, 2023
 *      Author: Mahmoud Morsy
 */


//library Directives
#include <util/delay.h>
#include "../INCLUDE/LIB/BIT_MATH.h"
#include "../INCLUDE/LIB/STD_TYPES.h"

// DIO Directives
#include "../INCLUDE/MCAL/GI/GI_PRIVATE.h"
#include "../INCLUDE/MCAL/GI/GI_INTERFACE.h"
#include "../INCLUDE/MCAL/GI/GI_CFG.h"

void MGI_voidEnable(void)
{
	SET_BIT(SREG,GLOBAL_INTERRUPT_ENABLE_BIT);
}

void MGI_voidDisable(void)
{
	SET_BIT(SREG,GLOBAL_INTERRUPT_ENABLE_BIT);
}
