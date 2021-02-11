/*
 * 28 BYJ_48
 * STEPPER_program.c
 *
 *  Created on: Feb 11, 2021
 *      Author: Hesham Adel
 */

#include <util/delay.h>

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/PORT_interface.h"

#include "STEPPER_interface.h"
#include "STEPPER_private.h"
#include "STEPPER_config.h"

void STEPPER_voidInit( void ){

	PORT_enumSetPinDirection( STEPPER_PORT , STEPPER_ORANGE_PIN , PORT_OUTPUT );
	PORT_enumSetPinDirection( STEPPER_PORT , STEPPER_YELLOW_PIN , PORT_OUTPUT );
	PORT_enumSetPinDirection( STEPPER_PORT , STEPPER_BLUE_PIN   , PORT_OUTPUT );
	PORT_enumSetPinDirection( STEPPER_PORT , STEPPER_PINK_PIN   , PORT_OUTPUT );

	DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW );
	DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW );
	DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW );
	DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW );

}

void STEPPER_voidOn  ( u8 Copy_u8StepType , u8 Copy_u8Direction , u8 Copy_u8Speed , u16 Copy_u16Degree ){

	u32 LOC_u16Iterator = 0 ;

	if( Copy_u8StepType == STEPPER_FULL_STEP ){

		if( Copy_u8Direction == STEPPER_CLOCK_WISE ){

			for( LOC_u16Iterator = 0 ; LOC_u16Iterator < ( ( (u32)Copy_u16Degree * 256 ) / 45 ) / 4 ; LOC_u16Iterator++  ){

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_HIGH );
				_delay_ms( Copy_u8Speed );


			}

		}else if( Copy_u8Direction == STEPPER_ANTI_CLOCK_WISE ){

			for( LOC_u16Iterator = 0 ; LOC_u16Iterator < ( ( (u32)Copy_u16Degree * 256 ) / 45 ) / 4 ; LOC_u16Iterator++  ){

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_HIGH );
				_delay_ms( Copy_u8Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW  );
				_delay_ms( Copy_u8Speed );


			}

		}

	}else if( Copy_u8StepType == STEPPER_HALF_STEP ){

		if( Copy_u8Direction == STEPPER_CLOCK_WISE ){

			for( LOC_u16Iterator = 0 ; LOC_u16Iterator < ( ( (u32)Copy_u16Degree * 512 ) / 45 ) / 8 ; LOC_u16Iterator++  ){

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_HIGH );
				_delay_ms( Copy_u8Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_HIGH );
				_delay_ms( Copy_u8Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_HIGH );
				_delay_ms( Copy_u8Speed );



			}

		}else if( Copy_u8Direction == STEPPER_ANTI_CLOCK_WISE ){


			for( LOC_u16Iterator = 0 ; LOC_u16Iterator < ( ( (u32)Copy_u16Degree * 512 ) / 45 ) / 8 ; LOC_u16Iterator++  ){
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_HIGH );
				_delay_ms( Copy_u8Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_HIGH );
				_delay_ms( Copy_u8Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_HIGH );
				_delay_ms( Copy_u8Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_HIGH );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW  );
				DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW  );
				_delay_ms( Copy_u8Speed );

			}

		}

	}

}
void STEPPER_voidOff ( void ){

	DIO_enumSetPinValue( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW );
	DIO_enumSetPinValue( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW );
	DIO_enumSetPinValue( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW );
	DIO_enumSetPinValue( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW );

}

