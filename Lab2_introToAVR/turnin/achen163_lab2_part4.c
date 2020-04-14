/*	Author: achen163
 *  Partner(s) Name: none
 *	Lab Section:22
 *	Assignment: Lab #2  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;
	PORTA = 0xFF;	
	DDRB = 0x00; //Configure port B's 8 pins as outputs
	PORTB = 0xFF; // Initialize PORTB output to 0's  
	DDRC = 0x00;
	PORTC = 0xFF;
	DDRD = 0xFF;
	PORTD = 0x00;
	unsigned char tmpB = 0x00; 
	unsigned char tmpA = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char tmpD = 0x00;
	unsigned char countweight = 0x00;
 /* Insert your solution below */
    while (1) {
		countweight = 0x00;
		tmpA = PINA;
		tmpB = PINB;
		tmpC = PINC;	
		tmpD = 0x00;
		countweight = tmpA + tmpB + tmpC;
		if (countweight > 0x8C) {
			tmpD = 0x01;		
	
		}

		if (tmpA -tmpC > 0x50) {
				tmpD = tmpD & 0xFD;
			}
		PORTD = countweight + tmpD; 
	}   
    return 1;
}
