/*
 * KPD_program.c
 *
 *  Created on: Feb 7, 2021
 *      Author: Hesham Adel
 */

#include <util/delay.h>

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/PORT_interface.h"

#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"


void KPD_voidInit(void){

	PORT_enumSetPinDirection( KPD_PORT , KPD_R0 , DIO_INPUT );
	PORT_enumSetPinDirection( KPD_PORT , KPD_R1 , DIO_INPUT );
	PORT_enumSetPinDirection( KPD_PORT , KPD_R2 , DIO_INPUT );
	PORT_enumSetPinDirection( KPD_PORT , KPD_R3 , DIO_INPUT );

	DIO_enumSetPinValue    ( KPD_PORT , KPD_R0 , DIO_HIGH  );
	DIO_enumSetPinValue    ( KPD_PORT , KPD_R1 , DIO_HIGH  );
	DIO_enumSetPinValue    ( KPD_PORT , KPD_R2 , DIO_HIGH  );
	DIO_enumSetPinValue    ( KPD_PORT , KPD_R3 , DIO_HIGH  );

	PORT_enumSetPinDirection( KPD_PORT , KPD_C0 , DIO_OUTPUT );
	PORT_enumSetPinDirection( KPD_PORT , KPD_C1 , DIO_OUTPUT );
	PORT_enumSetPinDirection( KPD_PORT , KPD_C2 , DIO_OUTPUT );
	PORT_enumSetPinDirection( KPD_PORT , KPD_C3 , DIO_OUTPUT );


}

u8 KPD_u8GetKeyPressed(void){

	u8 LOC_u8ReturnData = 0 ;
	u8 LOC_u8GetPressed = 0 ;
	u8 LOC_u8Row        = 0 ;
	u8 LOC_u8Col        = 0 ;

	for( LOC_u8Col = 0 + KPD_COL_INIT ; LOC_u8Col < KPD_COL_END + 1 ; LOC_u8Col++ ){

		DIO_enumSetPinValue( KPD_PORT , LOC_u8Col , DIO_LOW  );

		for( LOC_u8Row = 0 + KPD_ROW_INIT ; LOC_u8Row < KPD_ROW_END + 1 ; LOC_u8Row++ ){

			DIO_enumGetPinValue( KPD_PORT , LOC_u8Row , &LOC_u8GetPressed );

			if( LOC_u8GetPressed == 0 ){

				_delay_ms(50);

				DIO_enumGetPinValue( KPD_PORT , LOC_u8Row , &LOC_u8GetPressed );

				if( LOC_u8GetPressed == 0 ){

					LOC_u8ReturnData = KPD_u8Buttons[ LOC_u8Row - KPD_ROW_INIT ][ LOC_u8Col - KPD_COL_INIT ];

					DIO_enumGetPinValue( KPD_PORT , LOC_u8Row , &LOC_u8GetPressed );

					while( LOC_u8GetPressed == 0 ){

						DIO_enumGetPinValue( KPD_PORT , LOC_u8Row , &LOC_u8GetPressed );

					}

					break;

				}

			}

		}

		DIO_enumSetPinValue( KPD_PORT , LOC_u8Col , DIO_HIGH );
	}

	return LOC_u8ReturnData ;

}
