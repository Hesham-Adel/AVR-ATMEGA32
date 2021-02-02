/*
 * PORT_program.c
 *
 *  Created on: Feb 2, 2021
 *      Author: Hesham Adel
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "PORT_interface.h"
#include "PORT_config.h"
#include "PORT_private.h"

void PORT_voidInit( void ){

	DDRA_REG  = PORTA_DIR           ;
	DDRB_REG  = PORTB_DIR           ;
	DDRC_REG  = PORTC_DIR           ;
	DDRD_REG  = PORTD_DIR           ;

	PORTA_REG = PORTA_INITIAL_VALUE ;
	PORTB_REG = PORTB_INITIAL_VALUE ;
	PORTC_REG = PORTC_INITIAL_VALUE ;
	PORTD_REG = PORTD_INITIAL_VALUE ;

}

#ifdef PORT_DEFINE

PORT_ErrorStatus PORT_enumSetPortDirection( u8 Copy_u8PortNumber , u8 Copy_u8Direction ){

	PORT_ErrorStatus LOC_enumState = PORT_OK ;

	switch( Copy_u8PortNumber ){

	case PORT_PORTA: DDRA_REG = Copy_u8Direction ;  break;
	case PORT_PORTB: DDRB_REG = Copy_u8Direction ;  break;
	case PORT_PORTC: DDRC_REG = Copy_u8Direction ;  break;
	case PORT_PORTD: DDRD_REG = Copy_u8Direction ;  break;
	default        : LOC_enumState = PORT_NOK     ;  break;

	}

	return LOC_enumState ;

}

PORT_ErrorStatus PORT_enumSetPinDirection( u8 Copy_u8PortNumber , u8 Copy_u8PinNumber , u8 Copy_u8Direction ){

	PORT_ErrorStatus LOC_enumState = PORT_OK ;

	if( ( Copy_u8PinNumber >= PORT_PIN0 ) && ( Copy_u8PinNumber <= PORT_PIN7 ) ){

		switch( Copy_u8PortNumber ){

		case PORT_PORTA:

			if( Copy_u8Direction == PORT_OUTPUT ){ SET_BIT( DDRA_REG , Copy_u8PinNumber ) ; }
			else                                 { CLR_BIT( DDRA_REG , Copy_u8PinNumber ) ; }
			break;

		case PORT_PORTB:

			if( Copy_u8Direction == PORT_OUTPUT ){ SET_BIT( DDRB_REG , Copy_u8PinNumber ) ; }
			else                                 { CLR_BIT( DDRB_REG , Copy_u8PinNumber ) ; }
			break;

		case PORT_PORTC:

			if( Copy_u8Direction == PORT_OUTPUT ){ SET_BIT( DDRC_REG , Copy_u8PinNumber ) ; }
			else                                 { CLR_BIT( DDRC_REG , Copy_u8PinNumber ) ; }
			break;

		case PORT_PORTD:

			if( Copy_u8Direction == PORT_OUTPUT ){ SET_BIT( DDRD_REG , Copy_u8PinNumber ) ; }
			else                                 { CLR_BIT( DDRD_REG , Copy_u8PinNumber ) ; }
			break;

		default        : LOC_enumState = PORT_NOK     ;  break;

		}

	}else{ LOC_enumState = PORT_NOK ; }

	return LOC_enumState ;
}

#endif
