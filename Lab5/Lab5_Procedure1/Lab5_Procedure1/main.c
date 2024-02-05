/*
 * Lab5_Procedure1.c
 *
 * Created: 9/20/2023 3:20:56 PM
 * Author : park1432
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "serial.c"
#define F_CPU 16000000L
#include <util/delay.h>

int main(void)
{
	init_UART();		// turn on and setup the serial port connection
	DDRA = 0x00;	// configure Port A for input
	PORTA = 0xFF;	// turn on the Port A pull-up resistors
	DDRC = 0xFF;	// configure Port C as an output
	PORTC = 0x00;	// start with all of the Port C values off (zero)

	uint16_t value;

	printf("Top of the while(1) loop \n\r");

	while(1)		// run this part of the program over and over
	{
		value = 1;		// set the output value to 1
		while (value > 0)		// checks if the value is greater than zero
		{		// when the output value is smaller than zero:
			PORTC = value;		// output the value to the PORTC
			_delay_ms(750);		// delay for 750mS
			value = value << 1;		// shifting 1 to the left for value
		}
	}
}
