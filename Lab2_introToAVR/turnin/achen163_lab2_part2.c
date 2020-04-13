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
	DDRC = 0xFF;
	PORTC = 0x00;
	unsigned char tmpB = 0x00; 
	unsigned char tmpA = 0x00;
	unsigned char tmpC = 0x01;
	unsigned char cntavail = 0x00;
 /* Insert your solution below */
    while (1) {
		tmpA = PINA;
		cntavail = 0x04;
		if ((tmpA & 0x01) == 0x01) {
			cntavail = cntavail -0x01;
		}
		if((tmpA & 0x02) == 0x02) {
			cntavail = cntavail - 0x01;
		}
		if((tmpA & 0x04) == 0x04) {
			cntavail = cntavail - 0x01;
		}
		if ((tmpA & 0x08) == 0x08) {
			cntavail = cntavail - 0x01;
		}
		PORTC = cntavail;
    }
    return 1;
}
