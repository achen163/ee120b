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
	DDRB = 0xFF; //Configure port B's 8 pins as outputs
	PORTB = 0x00; // Initialize PORTB output to 0's  
	unsigned char tmpB = 0x00; 
	unsigned char tmpA = 0x00;
 /* Insert your solution below */
    while (1) {
		tmpA = PINA;
		if (tmpA == 0x01) {
			tmpB = (tmpB & 0xFC) | 0x01;
		}
		else {
			tmpB = (tmpB & 0xFC) | 0x00;
		}

		PORTB = tmpB;
    }
    return 1;
}
