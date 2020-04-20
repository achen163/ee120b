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

enum States {Start, NonePressed, PA0Pressed, Wait, PA1Pressed, BothPressed} state;

unsigned char tempA = 0x00;
unsigned char tempC = 0x07;	

void Tick() {

	switch(state) {
		case Start:
			state = NonePressed;		
			break;
		case NonePressed:
			if ((tempA & 0x03) == 0x03) {
				state = BothPressed;
			}
			else if ((tempA & 0x01) == 0x01) {
				state = PA0Pressed;
			}
			else if ((tempA & 0x02) == 0x02) {
				state = PA1Pressed;
			}   
			else {
				state = NonePressed;
			}
			break;
		case PA0Pressed:
	                if ((tempA & 0x03) == 0x03) {
                                state = BothPressed;
                        }
                        else if ((tempA & 0x01) == 0x01) {
                                state = Wait;
                        }
                        else if ((tempA & 0x02) == 0x02) {
                                state = PA1Pressed;
                        }
			else {
				state = NonePressed;
			}
			break;
		case Wait:
	                if ((tempA & 0x03) == 0x03) {
                                state = BothPressed;
                        }
                      
			else if ((tempA & 0x00) == 0x00){
				state = NonePressed;
			}
			break;
		case PA1Pressed:
	                if ((tempA & 0x03) == 0x03) {
                                state = BothPressed;
                        }
                        else if ((tempA & 0x01)  == 0x01) {
                                state = PA0Pressed;
                        }
                        else if ((tempA & 0x02) == 0x02) {
                                state = Wait;
                        }
			else {
				state = NonePressed;
			}
			break;

		case BothPressed:
	                if ((tempA & 0x03) == 0x03) {
                                state = Wait;
                        }
                        else if ((tempA & 0x01) == 0x01) {
                                state = PA0Pressed;
                        }
                        else if ((tempA & 0x02) == 0x02) {
                                state = PA1Pressed;
                        }
			else {
				state = NonePressed;
			}
			break;
		default:
			state = Start;
			break;
	}

	switch(state) {
		case Start:
			PORTC = 0x07;
			break;
		case NonePressed:	
			break;
		case PA0Pressed:
			tempC = PORTC;
			if (PORTC < 9 ) {
				PORTC = tempC + 1;
			}
			break;
		case Wait:
			break;
		case PA1Pressed:
			if (PORTC > 0) {
				PORTC  = PORTC - 0x01;
			}
			break;
		case BothPressed:
			PORTC = 0x00;
			break; 
		default:
			break;
	}


}



int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;
	PORTA = 0xFF;
	DDRC = 0xFF;
	PORTC = 0x07;
	state = Start;
    /* Insert your solution below */
    while (1) {
	tempA = PINA;		
	Tick();	
	//PORTB = light;
    }
    return 1;
}
