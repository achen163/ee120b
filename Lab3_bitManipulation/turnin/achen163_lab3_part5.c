/*	Author: achen163
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x &(0x01 << k)) !=0);
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRB = 0xFF;
	PORTB = 0x00;
	DDRD = 0x00;
	PORTD = 0xFF;
    /* Insert your solution below */
	unsigned char tmpB = 0x00;
	unsigned char tmpD = 0x00;
	unsigned char counter = 0x00; 
while (1) {
		
	tmpB = 0x00;
	counter = PIND;
	if (counter >= 35 ) {
		tmpB = 0x02;
	}
	else if (counter > 3 ) {
		tmpB = 0x04;
	} 
	else {
		tmpB = 0x00;
	}
	PORTB = tmpB;
    }
    return 1;
}
