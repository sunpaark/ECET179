/*
 * Procedure2.c
 *
 * Created: 9/20/2023 3:27:32 PM
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

	uint16_t count;

	printf("Top of the while(1) loop \n\r");

	while(1)		// run this part of the program over and over
	{
		while(PINA == 0)		// wait for pushbutton to be pressed
		{
			count = 0;			// clear counter
		}
		
		do 
		{
			_delay_ms(1);		// delay 1mS
			count++;			// increment counter
		} while (PINA != 0);		// wait for button to be deactivated
		printf("%u", count);			// display the result
	}
}
