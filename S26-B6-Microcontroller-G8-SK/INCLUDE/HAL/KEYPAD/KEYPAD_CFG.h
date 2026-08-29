/*
 * KEYPAD_PRIVATE.h
 *
 *  Created on: Aug 20, 2026
 *      Author: hodam
 */
#ifndef INCLUDE_HAL_KEYPAD_KEYPAD_CFG_H_
#define INCLUDE_HAL_KEYPAD_KEYPAD_CFG_H_

#define KEYPAD_PRESSED  0
#define KEY_NOT_PRESSED 1  // (255) ---> analog

#define ROW_NO  4
#define COL_NO  4

#define Flag_DOWN  0
#define Flag_UP    1


//u8 Global_u8ArrOfKeyValues[ROW_NO][COL_NO] = {
//    {'1','2','3','+'},
//    {'4','5','6','-'},
//    {'7','8','9','*'},
//    {'C','0','=','/'}
//};



#define KEYPAD_PORT PORTB

#define ROW0 PIN0
#define ROW1 PIN1
#define ROW2 PIN2
#define ROW3 PIN3

#define COL0 PIN4
#define COL1 PIN5
#define COL2 PIN6
#define COL3 PIN7

#define KEYPAD_ROWS {ROW0,ROW1,ROW2,ROW3}
#define KEYPAD_COLS {COL0,COL1,COL2,COL3}

// debounce !!
#define KEYPAD_DEBOUNCE_DELAY 30 // ms

#endif /* INCLUDE_HAL_KEYPAD_KEYPAD_CFG_H_ */
