/*
 * LED_interface.h
 *
 *  Created on: Feb 2, 2021
 *      Author: Hesham Adel
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

#define LED_ACTIVE_HIGH  1
#define LED_ACTIVE_LOW   0

typedef struct{

	u8 LED_EnablePort    ;
	u8 LED_EnablePin     ;
	u8 LED_Active_State  ;

}LED_Type;


void LED_voidOn   ( LED_Type * Copy_pstructConfig );
void LED_voidOff  ( LED_Type * Copy_pstructConfig );

#endif /* HAL_LED_LED_INTERFACE_H_ */
