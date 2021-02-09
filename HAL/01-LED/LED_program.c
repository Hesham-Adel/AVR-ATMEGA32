/*
 * LED_program.c
 *
 *  Created on: Feb 2, 2021
 *      Author: Hesham Adel
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"


void LED_voidOn  ( LED_Type * Copy_pstructConfig ){

	if( Copy_pstructConfig -> LED_Active_State == LED_ACTIVE_HIGH ){

		DIO_enumSetPinValue( Copy_pstructConfig -> LED_EnablePort , Copy_pstructConfig -> LED_EnablePin , DIO_HIGH );

	}
	else if( Copy_pstructConfig -> LED_Active_State == LED_ACTIVE_LOW ) {

		DIO_enumSetPinValue( Copy_pstructConfig -> LED_EnablePort , Copy_pstructConfig -> LED_EnablePin , DIO_LOW  );

	}

}

void LED_voidOff ( LED_Type * Copy_pstructConfig ){

	if( Copy_pstructConfig -> LED_Active_State == LED_ACTIVE_HIGH ){

		DIO_enumSetPinValue( Copy_pstructConfig -> LED_EnablePort , Copy_pstructConfig -> LED_EnablePin , DIO_LOW );

	}else if ( Copy_pstructConfig -> LED_Active_State == LED_ACTIVE_LOW ) {

		DIO_enumSetPinValue( Copy_pstructConfig -> LED_EnablePort , Copy_pstructConfig -> LED_EnablePin , DIO_HIGH );

	}

}


