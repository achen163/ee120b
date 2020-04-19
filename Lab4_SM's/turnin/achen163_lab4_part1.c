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

enum States {Start,LightOne, LightOneWait, LightTwo, LightTwoWait} state;

unsigned char tempA = 0x00;
unsigned char light = 0x00;	

void Tick() {
	tempA = PINA;
	switch(state) {
		case Start:
			state = LightOne;
			break;
		case LightOne:
			if (tempA) {
				state = LightOneWait;
			}
			else {
				state = LightOne;
			}
			break;
		case LightOneWait:
			state = tempA ? LightTwo : LightOneWait;
			break;
		case LightTwo:
			state = tempA ? LightTwo : LightTwoWait;
			break;
		case LightTwoWait:
			state = tempA ? LightOne : LightTwoWait;
			break;
		default:
			state = Start;
			break;
	}

	switch(state) {
		case Start:
			break;
		case LightOne:
			light = 0x01;
			break;
		case LightOneWait:
			light = 0x00;
			break;
		case LightTwo:
			light = 0x02;
			break;
		case LightTwoWait:
			light = 0x00;
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
    /* Insert your solution below */
    while (1) {
	light  = 0x00;	
	state = Start;
	Tick();	
    }
    return 1;
}
