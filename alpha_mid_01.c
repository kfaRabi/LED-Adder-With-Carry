/*
 * alpha_mid_01.c
 *
 *  Created on: Oct 26, 2016
 *      Author: rabi
 */

#include <avr/io.h>
#include <util/delay.h>

#define delay 170

int main(){
	DDRD = 0x1F; // Result
	DDRB = 0x0F; // num1
	DDRC = 0x0F; // num2

	PORTD = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;

	uint8_t num1, num2;
	uint16_t res = 0;
	num1 = num2 = 0;


	while(1){
		if(bit_is_set(PINB,PB5)){
			_delay_ms(delay);
			if(bit_is_set(PINB,PB5)){
				++num1;
				if(num1>15){
					num1 = 0;
				}
				PORTB = num1;
			}
		}
		else if(bit_is_set(PINC,PC5)){
			_delay_ms(delay);
			if(bit_is_set(PINC,PC5)){
				++num2;
				if(num2>15){
					num2 = 0;
				}
				PORTC = num2;
			}
		}
		else if(bit_is_set(PIND,PD5)){
			_delay_ms(delay);
			if(bit_is_set(PIND,PD5)){
				res = num1 + num2;
				PORTD = res;
				PORTB = num1 = 0;
				PORTC = num2 = 0;
			}
		}
	}
}
