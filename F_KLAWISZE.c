/*
 * F_KLAWISZE.c
 *
 *  Created on: 14 kwi 2019
 *      Author: Piotr
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "F_KLAWISZE.h"
#include <util/delay.h>

uint8_t klawisz_1_wcisniety(void){
			DDRC &= ~KEY_PIN1; 
			PORTC |= KEY_PIN1; 

			if(KEY_DOWN1)
				{
					_delay_ms (80);
					if(KEY_DOWN1) return 1;
				}
				return 0;
}
uint8_t klawisz_2_wcisniety(void){
			DDRB &= ~KEY_PIN2; 
			PORTB |= KEY_PIN2; 

			if(KEY_DOWN2)
				{
					_delay_ms (80);
					if(KEY_DOWN2) return 1;
				}
				return 0;
}
uint8_t klawisz_3_wcisniety(void){
			DDRB &= ~KEY_PIN3; 
			PORTB |= KEY_PIN3; 

			if(KEY_DOWN3)
				{
					_delay_ms (80);
					if(KEY_DOWN3) return 1;
				}
				return 0;
}
uint8_t klawisz_4_wcisniety(void){
			DDRB &= ~KEY_PIN4; 
			PORTB |= KEY_PIN4; 

			if(KEY_DOWN4)
				{
					_delay_ms (80);
					if(KEY_DOWN4) return 1;
				}
				return 0;
}

