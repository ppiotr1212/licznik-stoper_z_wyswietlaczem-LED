/*
 * F_KLAWISZE.h
 *
 *  Created on: 14 kwi 2019
 *      Author: Piotr
 */

#ifndef F_KLAWISZE_H_
#define F_KLAWISZE_H_


#define KEY_PIN1 (1<<PC4)
#define KEY_PIN2 (1<<PB0)
#define KEY_PIN3 (1<<PB1)
#define KEY_PIN4 (1<<PB2)
#define KEY_DOWN1 !(PINC & KEY_PIN1)
#define KEY_DOWN2 !(PINB & KEY_PIN2)
#define KEY_DOWN3 !(PINB & KEY_PIN3)
#define KEY_DOWN4 !(PINB & KEY_PIN4)
uint8_t klawisz_1_wcisniety(void);
uint8_t klawisz_2_wcisniety(void);
uint8_t klawisz_3_wcisniety(void);
uint8_t klawisz_4_wcisniety(void);

#endif 
