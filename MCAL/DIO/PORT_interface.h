/*
 * PORT_interface.h
 *
 *  Created on: Feb 2, 2021
 *      Author: Hesham Adel
 */

#ifndef MCAL_DIO_PORT_INTERFACE_H_
#define MCAL_DIO_PORT_INTERFACE_H_

typedef enum{

	PORT_NOK,
	PORT_OK

}PORT_ErrorStatus ;

#define PORT_OUTPUT    1
#define PORT_INPUT     0

#define PORT_HIGH      1
#define PORT_LOW       0


#define PORT_PORTA     0
#define PORT_PORTB     1
#define PORT_PORTC     2
#define PORT_PORTD     3

#define PORT_PIN0      0
#define PORT_PIN1      1
#define PORT_PIN2      2
#define PORT_PIN3      3
#define PORT_PIN4      4
#define PORT_PIN5      5
#define PORT_PIN6      6
#define PORT_PIN7      7

PORT_ErrorStatus PORT_enumSetPortDirection( u8 Copy_u8PortNumber , u8 Copy_u8Direction );
PORT_ErrorStatus PORT_enumSetPinDirection ( u8 Copy_u8PortNumber , u8 Copy_u8PinNumber , u8 Copy_u8Direction );

void PORT_voidInit( void );


#endif /* MCAL_DIO_PORT_INTERFACE_H_ */
