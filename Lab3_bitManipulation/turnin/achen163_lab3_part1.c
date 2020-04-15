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
	for (i = 0 ; i < 8; i++) {
		if ((tmpA & 0x01) == 0x01) {
			counter++;
		}
		else if(tmpA / 2 >= 1) {
			counter++;
		}
		tmpA = tmpA/2;
	}
	for (i =0; i < 8; i++) {
		if((tmpB & 0x01) == 0x01) {
			counter++;
		}	
		else if(tmpB / 2 >= 1) {
			counter++;
		}
		tmpB = tmpB / 2;
	}
	PORTC = counter;
    }
    return 1;
}
