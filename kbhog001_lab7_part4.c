/* Author: Karan Bhogal
 * Lab Section:21
 * Assignment: Lab #7  Exercise #4
 * Exercise Description: [optional - include for your own benefit]
 *
 * I acknowledge all content contained herein, excluding template or example
 * code is my own original work.
 *
 *  Demo Link: Youtube URL>
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
	ADC_init();
	unsigned short my_short;

    while (1) {
	my_short = ADC;
	//my_char = (char)(my_short >> 4);
	//PORTB = my_char;
	

	if (my_short == 0){
		PORTB = 0x00;
	}
	else if ( my_short < 49){
		PORTB = 0x01;
	}
	else if (my_short < 96){
		PORTB = 0x03;
	}
	else if (my_short < 145){
		PORTB = 0x07;
	}
	else if (my_short < 192){
		PORTB = 0x0F;
	}
	else if (my_short < 240){
		PORTB = 0x1F;
	}
	else if (my_short < 288){
		PORTB = 0x3F;
	}
	else if (my_short < 336){
		PORTB = 0x07F;
	}
	else if (my_short > 336){
		PORTB = 0xFF;
	}
	//PORTB = my_short;
	//PORTD = my_short >> 8;
    }
    return 1;
}
