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

enum States {Start, LightOneRelease, LightTwoPress, LightTwoRelease, LightOnePress} state;

unsigned char tempA = 0x00;
unsigned char light = 0x00;	

void Tick() {
	tempA = PINA;
	switch(state) {
		case Start:
			state = LightOneRelease;
			break;
		case LightOneRelease:
			if (tempA) {
				state = LightTwoPress;
			}
			else {
				state = LightOneRelease;
			}
			break;
		case LightTwoPress:
			state = tempA ? LightTwoPress : LightTwoRelease;
			break;
		case LightTwoRelease:
			state = tempA ? LightOnePress : LightTwoRelease;
			break;
		case LightOnePress:
			state = tempA ? LightOnePress : LightOneRelease;
			break;
		default:
			state = Start;
			break;
	}

	switch(state) {
		case Start:
			break;
		case LightOneRelease:
			light = 0x01;
			break;
		case LightTwoPress:
			light = 0x02;
			break;
		case LightTwoRelease:
			light = 0x02;
			break;
		case LightOnePress:
			light = 0x01;
			break;
		default:
			break;
	}

PORTB = light;
}



int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;
	PORTA = 0xFF;
	DDRB = 0xFF;
	PORTB = 0x00;
	state = Start;
	light = 0x00;
    /* Insert your solution below */
    while (1) {
	
	Tick();	
	//PORTB = light;
    }
    return 1;
}
