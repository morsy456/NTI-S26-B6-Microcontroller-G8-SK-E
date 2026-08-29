/*
 * DIO_INTERFACE.h
 *
 *  Created on: Apr 4, 2023
 *      Author: hodam
 */

#ifndef MCAL_DIO_INTERFACE_H_
#define MCAL_DIO_INTERFACE_H_

typedef enum{
	DIO_INPUT=0
	,DIO_OUTPUT
}PIN_DIRECTION;

typedef enum{
	DIO_LOW=0 //SET
	,DIO_HIGH //RESET
}PIN_STATUS;

typedef enum{
	DIO_FLOATING=0
	,DIO_PULLUP
}PIN_INPUT_MODE;

typedef enum{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}DIO_PINS;

typedef enum{
	PORTA=0,
	PORTB,
	PORTC,
	PORTD
}DIO_PORTS;


void MDIO_voidInti(void);
void MDIO_voidSetPinDirection(DIO_PORTS A_DIOPORT,DIO_PINS A_DIOPIN,PIN_DIRECTION A_PinDirection);
void MDIO_voidSetPinValue(DIO_PORTS A_DIOPORT,DIO_PINS A_DIOPIN,PIN_STATUS A_PinValue);

void MDIO_voidTogglePinValue(DIO_PORTS A_DIOPORT, DIO_PINS A_DIOPIN);

PIN_STATUS MDIO_PinstatusGetPinValue(DIO_PORTS A_DIOPORT, DIO_PINS A_DIOPIN);

void MDIO_voidSetPortDirection(DIO_PORTS A_DIOPORT, u8 A_u8PortDirection);
void MDIO_voidSetPortValue(DIO_PORTS A_DIOPORT, u8 A_u8PortValue);



#endif /* MCAL_DIO_INTERFACE_H_ */
