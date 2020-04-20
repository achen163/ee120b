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

enum States {Start, Locked, PPressed, PReleased, Unlocked, PPressed2, PReleased2} state;
unsigned char count = 0;
unsigned char tempA = 0x00;
//unsigned char tempC = 0x07;	

void Tick() {
	switch(state) {
		case Start:
			state = Locked;		
			break;
		case Locked:
			if (tempA == 0x04) {
				state = PPressed;
			}
			else {
				state = Locked;
			}
			break;
		case PPressed:
	                if (tempA  == 0x00) {
                                state = PReleased;
                        }
			else if (tempA == 0x04) {
				state = PPressed;
			}
			else {
				state = Locked;
			}
			break;
		case PReleased:
	                if (tempA == 0x02) {
                                state = Unlocked;
                        }
			else if (tempA == 0x00) {
				state = PReleased;
			}
			else {
				state = Locked;
			} 
			break;
                case Unlocked:
                        if (tempA == 0x80) {
				state = Locked;
			} 
			else if (tempA == 0x02 ) {
				state = Unlocked;
			}
			else if (tempA == 0x04) {
				state = PPressed2;
			}
			else {
				state = Locked;
			}
			break;
		case PPressed2: 
			if (tempA == 0x00) {
				state = PReleased2;
			}
			else {
				state = Unlocked;
			}
			break;
		case PReleased2:
			if (tempA == 0x02) {
				state = Locked;
			}
			else {
				state = Unlocked;
			}
		
		default:
			state = Start;
			break;
	}

	switch(state) {
		case Start:
			break;
		case Locked:	
			PORTB = 0x00;
			break;
		case PPressed:
			break;
		case PReleased:
			break;
		case Unlocked:
			PORTB = 0x01;
			break;
		case PPressed2:
			break;
		case PReleased2:
			break;
		default:
			break;
	}


}



int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;
	PORTA = 0xFF;
	DDRB = 0xFF;
	PORTB = 0x07;
	state = Start;
    /* Insert your solution below */
    while (1) {
	tempA = PINA;		
	Tick();	
	//PORTB = light;
    }
    return 1;
}