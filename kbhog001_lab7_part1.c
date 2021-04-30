/* Author: Karan Bhogal
 * Lab Section: 21
 * Assignment: Lab #7  Exercise #1
 * Exercise Description: [optional - include for your own benefit]
 *
 * I acknowledge all content contained herein, excluding template or example
 * code is my own original work.
 *
 *  Demo Link: https://drive.google.com/file/d/196kUmncpeS3A_l5hBPGcyoIA3uhwgE--/view?usp=sharing
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
	unsigned char my_char;

    while (1) {
	my_short = ADC;
	//my_char = (char)(my_short >> 4);
	//PORTB = my_char;
	PORTB = my_short;
	PORTD = my_short >> 8;
    }
    return 1;
}
