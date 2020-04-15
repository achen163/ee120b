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
	DDRB = 0x00;
	PORTB = 0xFF;
	DDRC = 0xFF;
	PORTC = 0x00;
    /* Insert your solution below */
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char counter = 0x00;
	unsigned int i = 0;  
while (1) {
	tmpA = PINA;
	tmpB = PINB;
	counter = 0x00;
	for( i =0; i < 8; i++ ) {
		tmpA = GetBit(PINA, i);
		if(tmpA == 0x01) {
			counter++;
		}
		tmpB = GetBit(PINB, i);
		if (tmpB == 0x01) {
			counter++;
		}
	}
	
	PORTC = counter;
    }
    return 1;
}
