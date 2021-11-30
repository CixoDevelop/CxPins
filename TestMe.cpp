/*
 * This code is a simple example of using the CxPins
 * library to rewrite the negated value from one
 * pin (button) to another (led)
 *
 * Author: Cixo
 */

/* include CxPins */
#include <CxFramework/CxPins.h>

/* include avr lib */
#include <avr/io.h>

int main(){

	/* creating two pins */
	CxPin led(&DDRB, 0);	// PORTB, 0
	CxPin button(&DDRB, 1);	// PORTB, 1

	/* set up output pin */
	led = OUT;	// set to output
	led = LOW;	// write low state

	/* set up input pin */
	button = IN;	// set to input
	button = HIGH;	// and set up pullup

	/* rewriting negative value of input to output */
	while(1)
		led = !button;
}
