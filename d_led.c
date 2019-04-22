/*
 * d_led.c
 *
 *  Created on: 8 kwi 2019
 *      Author: Piotr
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "d_led.h"
#include <util/delay.h>

volatile uint8_t cy1;
volatile uint8_t cy2;
volatile uint8_t cy3;
volatile uint8_t cy4;

#define SEG_A (1<<0)
#define SEG_B (1<<1)
#define SEG_C (1<<2)
#define SEG_D (1<<3)
#define SEG_E (1<<4)
#define SEG_F (1<<5)
#define SEG_G (1<<6)
#define SEG_DP (1<<7)




void d_led_init(void)
		{

	LED_DATA_DIR=0xFF;  
	LED_DATA = 0xFF;    

	ANODY_DIR |=CA1|CA2|CA3|CA4; 
	ANODY_PORT |=CA1|CA2|CA3|CA4;
	
			TCCR0A |= (1<<WGM01);            
			TCCR0B |= (1<<CS02)|(1<<CS00);   
			OCR0A = 28; 
			TIMSK0 |= (1<<OCIE0A);
		}


ISR(TIMER0_COMPA_vect)
{

	uint8_t cyfry[10]  = {
					~(SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F),
					~(SEG_B|SEG_C),
					~(SEG_A|SEG_B|SEG_D|SEG_E|SEG_G),
					~(SEG_A|SEG_B|SEG_C|SEG_D|SEG_G),
					~(SEG_B|SEG_C|SEG_F|SEG_G),
					~(SEG_A|SEG_C|SEG_D|SEG_F|SEG_G),
					~(SEG_A|SEG_C|SEG_D|SEG_E|SEG_F|SEG_G),
					~(SEG_A|SEG_B|SEG_C|SEG_F),
					~(SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F|SEG_G),
					~(SEG_A|SEG_B|SEG_C|SEG_D|SEG_F|SEG_G),
					
			};

	static uint8_t licznik=1;

	ANODY_PORT =(ANODY_PORT & 0xF0)|(~licznik & 0x0F);

	if(licznik ==1) LED_DATA=cyfry[cy1];
	else if(licznik==2) LED_DATA=cyfry[cy2];
	else if(licznik==4) LED_DATA=cyfry[cy3];
	else if(licznik==8) LED_DATA=cyfry[cy4];

	licznik <<= 1;

	if(licznik>8)licznik=1;

}


