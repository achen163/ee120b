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
	DDRA = 0x00;
	PORTA = 0xFF;
	DDRC = 0xFF;
	PORTC = 0x00;
    /* Insert your solution below */
	unsigned char tmpA = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char counter = 0x00;
	unsigned int i = 0;  
while (1) {
	tmpA = PINA;
	tmpC = 0x00;
if (tmpA > 0) {	
	if ((tmpA <= 2)) {
		tmpC = 0x20;
	}
	else if (tmpA <=4) {
		tmpC = 0x30;
	}
	else if (tmpA <= 6) {
		tmpC = 0x38;
	}
	else if (tmpA <= 9) {
		tmpC = 0x3C;
	}
	else if (tmpA <= 12) {
		tmpC = 0x3E;
	}
	else if (tmpA <= 15) {
		tmpC = 0x3F;
	} 
}
	
	if (tmpA <=4) {
		tmpC = tmpC + 0x40;
	}
	PORTC = tmpC;
    }
    return 1;
}
