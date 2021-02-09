/*
 * SEVEN_SEG_program.h
 *
 *  Created on: Feb 2, 2021
 *      Author: Hesham Adel
 */

#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_

#define SSD_COMM_CATHODE  1
#define SSD_COMM_ANODE    0

typedef struct{

	u8 SSD_Type       ;
	u8 SSD_DataPort   ;
	u8 SSD_EnablePort ;
	u8 SSD_EnablePin  ;

}SSD_Type;

void SSD_voidSendNumber( SSD_Type * Copy_pstructConfig , u8 Copy_u8Number );
void SSD_voidEnable    ( SSD_Type * Copy_pstructConfig );
void SSD_voidDisable   ( SSD_Type * Copy_pstructConfig );

#endif /* HAL_SSD_SSD_INTERFACE_H_ */
