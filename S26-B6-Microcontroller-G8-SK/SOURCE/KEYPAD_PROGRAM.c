/*
 * KEYPAD_PROGRAM.c
 *
 *  Created on: Aug 20, 2026
 *      Author: Mahmoud Morsy
 */
//library Directives
#include "../INCLUDE/LIB/BIT_MATH.h"
#include "../INCLUDE/LIB/STD_TYPES.h"

// DIO Directives
#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"
#include "../INCLUDE/MCAL/DIO/DIO_PRIVATE.h"
#include "../INCLUDE/MCAL/DIO/DIO_CFG.h"

// KEYPAD Directives

#include "../INCLUDE/HAL/KEYPAD/KEYPAD_PRIVATE.h"
#include "../INCLUDE/HAL/KEYPAD/KEYPAD_INTERFACE.h"
#include "../INCLUDE/HAL/KEYPAD/KEYPAD_CFG.h"
#include <util/delay.h>

static const u8 Global_u8ArrOfKeyValues[ROW_NO][COL_NO] = {
    {'1','2','3','+'},
    {'4','5','6','-'},
    {'7','8','9','*'},
    {'C','0','=','/'}
};

u8 static G_u8ArrofRows[ROW_NO]= KEYPAD_ROWS;
u8 static G_u8ArrofCols[COL_NO]= KEYPAD_COLS;

u8 HKEYPAD_u8GetPressedKey(void)
{

		u8 L_u8KeyValue= KEY_NOT_PRESSED;
		u8 L_u8RowCounter=0, L_u8ColCounter=0, L_u8PinValue=0, L_u8Flag= Flag_DOWN;

		for(L_u8RowCounter=0; L_u8RowCounter<ROW_NO ; L_u8RowCounter++ )
		{
			L_u8PinValue = MDIO_PinstatusGetPinValue(KEYPAD_PORT, G_u8ArrofRows[L_u8RowCounter]);

			for(L_u8ColCounter=0; L_u8ColCounter<COL_NO; L_u8ColCounter++)
			{
				L_u8PinValue = MDIO_PinstatusGetPinValue(KEYPAD_PORT, G_u8ArrofCols[L_u8ColCounter]);

				if(L_u8PinValue==KEYPAD_PRESSED)
				{
				   _delay_ms(KEYPAD_DEBOUNCE_DELAY);
				   L_u8PinValue = MDIO_PinstatusGetPinValue(KEYPAD_PORT, G_u8ArrofCols[L_u8ColCounter]);

				   if(L_u8PinValue==KEYPAD_PRESSED)
				   {
					   while(L_u8PinValue==KEYPAD_PRESSED)
					   {
						   L_u8PinValue= MDIO_PinstatusGetPinValue(KEYPAD_PORT, G_u8ArrofCols[L_u8ColCounter]);
					   }
					   L_u8KeyValue= Global_u8ArrOfKeyValues[L_u8RowCounter][L_u8ColCounter];
					   L_u8Flag=Flag_UP;
					   break;
				   }
				}
			} // loop with Columns
		MDIO_voidSetPinValue(KEYPAD_PORT, G_u8ArrofRows[L_u8RowCounter],DIO_HIGH);
		if(L_u8Flag==Flag_UP)
		{
			break;
		}



		}
	return L_u8KeyValue;
}





