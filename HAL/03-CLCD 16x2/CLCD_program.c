/*
 * CLCD_program.c
 *
 *  Created on: Feb 3, 2021
 *      Author: Hesham Adel
 */

#include <util/delay.h>

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/PORT_interface.h"

#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"
#include "CLCD_ExtreChar.h"


void CLCD_voidInit( void ){

	u8 LOC_u8FunctionSet = CLCD_FUNCTION_SET_BIT_COMMEND ;
	u8 LOC_u8Display     = CLCD_DISPLAY_ON_OFF_COMMEND   ;
	u8 LOC_u8EntryMode   = CLCD_ENTRY_MODE_SET_COMMEND   ;

	PORT_enumSetPortDirection( CLCD_DATA_PORT     , 255 );
	PORT_enumSetPinDirection ( CLCD_CONTROL_PORT  , CLCD_RS_PIN , PORT_OUTPUT );
	PORT_enumSetPinDirection ( CLCD_CONTROL_PORT  , CLCD_RW_PIN , PORT_OUTPUT );
	PORT_enumSetPinDirection ( CLCD_CONTROL_PORT  , CLCD_EN_PIN , PORT_OUTPUT );

	_delay_ms( 50 );


	#if    CLCD_NUMBER_OF_DISPLAY == CLCD_2_LINE

		SET_BIT( LOC_u8FunctionSet , 3 );

	#elif  CLCD_NUMBER_OF_DISPLAY == CLCD_1_LINE

		CLR_BIT( LOC_u8FunctionSet , 3 );

	#endif

	#if    CLCD_FONT_SIZE == CLCD_5_7

		SET_BIT( LOC_u8FunctionSet , 2 );

	#elif  CLCD_FONT_SIZE == CLCD_5_8

		CLR_BIT( LOC_u8FunctionSet , 2 );

	#endif

	#if    CLCD_DISPLAY == CLCD_DISPLAY_ON

		SET_BIT( LOC_u8Display , 2 );

	#elif  CLCD_DISPLAY == CLCD_DISPLAY_OFF

		CLR_BIT( LOC_u8Display , 2 );

	#endif

	#if    CLCD_CURSOR == CLCD_CURSOR_ON

		SET_BIT( LOC_u8Display , 1 );

	#elif  CLCD_CURSOR == CLCD_CURSOR_OFF

		CLR_BIT( LOC_u8Display , 1 );

	#endif

	#if    CLCD_CURSOR_BLINK == CLCD_CURSOR_BLINK_ON

		SET_BIT( LOC_u8Display , 0 );

	#elif  CLCD_CURSOR_BLINK == CLCD_CURSOR_BLINK_OFF

		CLR_BIT( LOC_u8Display , 0 );

	#endif

	#if    CLCD_SHIFT_DIRECTION == CLCD_SHIFT_LEFT

		SET_BIT( LOC_u8EntryMode , 0 );
		SET_BIT( LOC_u8EntryMode , 1 );

	#elif  CLCD_SHIFT_DIRECTION == CLCD_SHIFT_RIGHT

		SET_BIT( LOC_u8EntryMode , 0 );
		CLR_BIT( LOC_u8EntryMode , 1 );

	#elif  CLCD_SHIFT_DIRECTION == CLCD_DISABLE_SHIFT

		CLR_BIT( LOC_u8EntryMode , 0 );
		SET_BIT( LOC_u8EntryMode , 1 );

	#endif


	#if CLCD_MODE == CLCD_8_BIT_MODE

		SET_BIT( LOC_u8FunctionSet , 4 );


	#elif CLCD_MODE == CLCD_4_BIT_MODE

		CLR_BIT( LOC_u8FunctionSet , 4 );
		CLCD_voidWriteCommend( LOC_u8FunctionSet >> 4 );

	#endif

	CLCD_voidWriteCommend( LOC_u8FunctionSet      );
	_delay_ms(1);
	CLCD_voidWriteCommend( LOC_u8Display      );
	_delay_ms(1);
	CLCD_voidWriteCommend( CLCD_DISPLAY_CLEAR );
	_delay_ms(1);
	CLCD_voidWriteCommend( LOC_u8EntryMode    );
	_delay_ms(1);

}

void CLCD_voidWriteCommend( u8 Copy_u8Commend ){

	DIO_enumSetPinValue ( CLCD_CONTROL_PORT , CLCD_RS_PIN    , DIO_LOW  );
	DIO_enumSetPinValue ( CLCD_CONTROL_PORT , CLCD_RW_PIN    , DIO_LOW  );

	#if CLCD_MODE == CLCD_8_BIT_MODE

		DIO_enumSetPortValue( CLCD_DATA_PORT    , Copy_u8Commend );

		DIO_enumSetPinValue ( CLCD_CONTROL_PORT , CLCD_EN_PIN    , DIO_HIGH );
		_delay_ms(1);
		DIO_enumSetPinValue ( CLCD_CONTROL_PORT , CLCD_EN_PIN    , DIO_LOW  );
		_delay_ms(1);


	#elif CLCD_MODE == CLCD_4_BIT_MODE

		DIO_enumSetPortValue( CLCD_DATA_PORT    , Copy_u8Commend & 0xF0 );

		DIO_enumSetPinValue ( CLCD_CONTROL_PORT , CLCD_EN_PIN    , DIO_HIGH  );
		_delay_ms(1);
		DIO_enumSetPinValue ( CLCD_CONTROL_PORT , CLCD_EN_PIN    , DIO_LOW   );
		_delay_ms(1);

		DIO_enumSetPortValue( CLCD_DATA_PORT    , Copy_u8Commend << 4 );

		DIO_enumSetPinValue ( CLCD_CONTROL_PORT , CLCD_EN_PIN    , DIO_HIGH  );
		_delay_ms(1);
		DIO_enumSetPinValue ( CLCD_CONTROL_PORT , CLCD_EN_PIN    , DIO_LOW   );
		_delay_ms(1);

	#endif


}

void CLCD_voidWriteData    ( u8 Copy_u8Data    ){

	DIO_enumSetPinValue ( CLCD_CONTROL_PORT , CLCD_RS_PIN    , DIO_HIGH  );
	DIO_enumSetPinValue ( CLCD_CONTROL_PORT , CLCD_RW_PIN    , DIO_LOW   );

	#if CLCD_MODE == CLCD_8_BIT_MODE

		DIO_enumSetPortValue( CLCD_DATA_PORT    , Copy_u8Data );

		DIO_enumSetPinValue ( CLCD_CONTROL_PORT , CLCD_EN_PIN    , DIO_HIGH  );
		_delay_ms(1);
		DIO_enumSetPinValue ( CLCD_CONTROL_PORT , CLCD_EN_PIN    , DIO_LOW   );
		_delay_ms(1);


	#elif CLCD_MODE == CLCD_4_BIT_MODE

		DIO_enumSetPortValue( CLCD_DATA_PORT    , Copy_u8Data & 0xF0 );

		DIO_enumSetPinValue ( CLCD_CONTROL_PORT , CLCD_EN_PIN    , DIO_HIGH  );
		_delay_ms(1);
		DIO_enumSetPinValue ( CLCD_CONTROL_PORT , CLCD_EN_PIN    , DIO_LOW   );
		_delay_ms(1);

		DIO_enumSetPortValue( CLCD_DATA_PORT    , Copy_u8Data << 4 );

		DIO_enumSetPinValue ( CLCD_CONTROL_PORT , CLCD_EN_PIN    , DIO_HIGH  );
		_delay_ms(1);
		DIO_enumSetPinValue ( CLCD_CONTROL_PORT , CLCD_EN_PIN    , DIO_LOW   );
		_delay_ms(1);

	#endif


}

void CLCD_voidWriteString  ( u8 * Copy_u8ptrString ){

	u8 LOC_u8Iterator = 0 ;

	while( Copy_u8ptrString[ LOC_u8Iterator ] != '\0' ){

		CLCD_voidWriteData( Copy_u8ptrString[ LOC_u8Iterator ] );
		LOC_u8Iterator++;

	}

}

void CLCD_voidSetPosition  ( u8 Copy_u8Row , u8 Copy_u8Col ){

	if( Copy_u8Row == CLCD_ROW_1 ){

		CLCD_voidWriteCommend( CLCD_SET_DDRAM_ADDRESS_COMMEDN + ( Copy_u8Col - 1 ) );

	}else if( Copy_u8Row  == CLCD_ROW_2 ){

		CLCD_voidWriteCommend( CLCD_SET_DDRAM_ADDRESS_COMMEDN + 64 + ( Copy_u8Col - 1 ) );

	}

}


void CLCD_voidWriteNumber  ( u64 Copy_u8Number ){

	u64 LOC_u64Reversed = 1 ;

	if( Copy_u8Number == 0 ){ CLCD_voidWriteData('0'); }

	while( Copy_u8Number != 0 ){

		LOC_u64Reversed = ( LOC_u64Reversed * 10 ) + ( Copy_u8Number % 10 ) ;
		Copy_u8Number  /= 10 ;

	}
	while( LOC_u64Reversed != 1 ){

		CLCD_voidWriteData( ( LOC_u64Reversed % 10 ) + 48 );
		LOC_u64Reversed  /= 10 ;

	}

}

void CLCD_voidWriteExtraChare ( u8 Copy_u8Row , u8 Copy_u8Col ){

	u8 LOC_u8Iterator = 0 ;

	CLCD_voidWriteCommend( CLCD_SET_CGRAM_ADDRESS_COMMEND );

	for( LOC_u8Iterator = 0 ; LOC_u8Iterator <= sizeof(CLCD_ExtraChar) / sizeof(CLCD_ExtraChar[0]) ; LOC_u8Iterator++ ){

		CLCD_voidWriteData( CLCD_ExtraChar[LOC_u8Iterator] );

	}

	CLCD_voidWriteCommend( CLCD_SET_DDRAM_ADDRESS_COMMEDN );

	CLCD_voidSetPosition( Copy_u8Row , Copy_u8Col );

	for( LOC_u8Iterator = 0 ; LOC_u8Iterator < 8 ; LOC_u8Iterator++ ){

		CLCD_voidWriteData( LOC_u8Iterator );

	}

}
