/*
 * Lab4_Step1.c
 *
 * Created: 9/13/2023 3:39:25 PM
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

	printf("Lab 4 - Sunny Park \n\r");

	while(1)		// run this part of the program over and over
	{
		if (PINA == 0x01)		// checks if toggle is activated
		{		// when the toggle is activated:
			PORTC = 0x01;		// turn on LED 0
			_delay_ms(500);		// delay for 500mS
			PORTC = 0x00;		// turn off LED 0
			_delay_ms(500);		// delay for 500mS
		}
		
		else
		{
			if (PINA == 0x02)
			{
				PORTC = 0x40;		// turn on LED 7
				_delay_ms(500);		// delay for 500mS
				PORTC = 0x00;		// turn off LED
				_delay_ms(500);		// delay for 500mS
				
			}
		}
	}
}
