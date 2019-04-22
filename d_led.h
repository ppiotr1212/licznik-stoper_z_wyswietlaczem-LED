/*
 * d_led.h
 *
 *  Created on: 8 kwi 2019
 *      Author: Piotr
 */

#ifndef D_LED_H_
#define D_LED_H_


#define LED_DATA PORTD
#define LED_DATA_DIR DDRD
#define ANODY_PORT PORTC
#define ANODY_DIR DDRC

#define CA1 (1<<PC0)
#define CA2 (1<<PC1)
#define CA3 (1<<PC2)
#define CA4 (1<<PC3)


extern volatile uint8_t cy1;
extern volatile uint8_t cy2;
extern volatile uint8_t cy3;
extern volatile uint8_t cy4;



void d_led_init(void);


#endif 
