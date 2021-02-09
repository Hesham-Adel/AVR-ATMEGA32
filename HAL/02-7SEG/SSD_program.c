/*
 * SEVEN_SEG_program.c
 *
 *  Created on: Feb 2, 2021
 *      Author: Hesham Adel
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "../SSD/SSD_config.h"
#include "../SSD/SSD_interface.h"
#include "../SSD/SSD_private.h"

const u8 SSD_u8Numbers[10]={0b00111111, 0b00000110 ,0b01011011,0b01001111,0b01100110 ,0b01101101,0b01111101 ,0b00000111, 0b01111111,0b01101111 };

void SSD_voidSendNumber( SSD_Type * Copy_pstructConfig , u8 Copy_u8Number ){

	if( Copy_pstructConfig -> SSD_Type == SSD_COMM_CATHODE ){

		DIO_enumSetPortValue( Copy_pstructConfig -> SSD_DataPort , SSD_u8Numbers[ Copy_u8Number ] );
	}

	else{

		DIO_enumSetPortValue( Copy_pstructConfig -> SSD_DataPort , ~( SSD_u8Numbers[ Copy_u8Number ] ) );
	}

}

void SSD_voidEnable    ( SSD_Type * Copy_pstructConfig ){

	if( Copy_pstructConfig -> SSD_Type == SSD_COMM_CATHODE ){

		DIO_enumSetPinValue( Copy_pstructConfig -> SSD_EnablePort , Copy_pstructConfig -> SSD_EnablePin , DIO_LOW  );

	}else{

		DIO_enumSetPinValue( Copy_pstructConfig -> SSD_EnablePort , Copy_pstructConfig -> SSD_EnablePin , DIO_HIGH  );

	}

}

void SSD_voidDisable   ( SSD_Type * Copy_pstructConfig ){

	if( Copy_pstructConfig -> SSD_Type == SSD_COMM_CATHODE ){

		DIO_enumSetPinValue( Copy_pstructConfig -> SSD_EnablePort , Copy_pstructConfig -> SSD_EnablePin , DIO_HIGH  );

	}else{

		DIO_enumSetPinValue( Copy_pstructConfig -> SSD_EnablePort , Copy_pstructConfig -> SSD_EnablePin , DIO_LOW   );

	}

}
