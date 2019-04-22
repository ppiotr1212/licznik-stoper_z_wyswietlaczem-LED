/*
 * main.c
 *
 *  Created on: 8 kwi 2019
 *      Author: Piotr
 */

#include <avr/io.h> 
#include <avr/interrupt.h> 
#include "d_led.h" 
#include <util/delay.h>
#include "F_KLAWISZE.h" 


int main(void)
{

	d_led_init(); 

		cy1=0;
		cy2=0;
		cy3=0;
		cy4=0;


	sei(); 
	while(1){
		int a;

		if(klawisz_1_wcisniety()){

						cy4+=1;
						_delay_ms(4);

				if(cy4>9){
					cy3+=1;
					cy4=0;}
				if(cy3==10){
					cy2+=1;
					cy3=0;}
				if(cy2==10){
					cy1+=1;
					cy2=0;}
		}
		else if(klawisz_2_wcisniety()){

						cy4-=1;
						_delay_ms(4);

						if((cy3==0)&&(cy1==0)&&(cy2==0)
								&&(cy4!=0)&&(cy4!=1)&&(cy4!=2)&&(cy4!=3)
								&&(cy4!=4)&&(cy4!=5)&&(cy4!=6)
								&&(cy4!=7)&&(cy4!=8)&&(cy4!=9))
							{cy4=0;cy3=0;cy2=0;cy1=0;}


						if((cy4!=0)&&(cy4!=1)&&(cy4!=2)&&(cy4!=3)&&(cy4!=4)
								&&(cy4!=5)&&(cy4!=6)&&(cy4!=7)&&(cy4!=8)&&(cy4!=9)
								&&(cy3>0))
							{cy4=9;cy3-=1;}

						if((cy4!=0)&&(cy4!=1)&&(cy4!=2)&&(cy4!=3)&&(cy4!=4)
								&&(cy4!=5)&&(cy4!=6)&&(cy4!=7)&&(cy4!=8)&&(cy4!=9)
								&&(cy3==0)&&(cy2>0))
							{cy2-=1;cy4=9;cy3=9;}

						if((cy4!=0)&&(cy4!=1)&&(cy4!=2)&&(cy4!=3)&&(cy4!=4)&&(cy4!=5)
								&&(cy4!=6)&&(cy4!=7)&&(cy4!=8)&&(cy4!=9)
								&&(cy3==0)&&(cy2==0)&&(cy1>0))
							{cy1-=1;cy4=9;cy3=9;cy2=9;}
		}

		else if(klawisz_3_wcisniety()){
			cy1=0;cy2=0;cy3=0;cy4=0;
			_delay_ms(10);
		}
		else if(klawisz_4_wcisniety()){
			a=1;

			int b=0;
			static int i=0;
			


				while(a==1){
					if(i==0 && a==1){
						for(;i<10;i++){
							if(klawisz_1_wcisniety()){a=0;}
							if (a==1){
							cy4=i;

							 if (( cy4==0)&&(b!=0)){cy3+=1;}
							 if(cy3==10){cy3=0;}
							 if (( cy4==0)&&(b!=0)&&(cy3==0)){cy2+=1;}
							 if(cy2==10){cy2=0;}
							 if (( cy4==0)&&(b!=0)&&(cy3==0)&&(cy2==0)){cy1+=1;}
							 if(cy1==10){cy1=9;cy2=9;cy3=9;cy4=9;a=0;}
							 _delay_ms(75);
							}
						}
					}
					if(i==10){i=0;b=1;}
				}
		}
	}
}
