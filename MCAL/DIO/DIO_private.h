/*
 * DIO_private.h
 *
 *  Created on: Feb 2, 2021
 *      Author: Hesham Adel
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_

#define PORTA_REG *((volatile u8 *)0x3B)
#define PINA_REG  *((volatile u8 *)0x39)


#define PORTB_REG *((volatile u8 *)0x38)
#define PINB_REG  *((volatile u8 *)0x36)


#define PORTC_REG *((volatile u8 *)0x35)
#define PINC_REG  *((volatile u8 *)0x33)


#define PORTD_REG *((volatile u8 *)0x32)
#define PIND_REG  *((volatile u8 *)0x30)


#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
