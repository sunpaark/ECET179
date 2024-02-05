/*********************************************************
ECET 17900 - Introduction to Digital Systems - Lab #3

Name: Sunny Park
Date: 09/06/2023
Lab day and Time: Wednesday, 3:30

Included file: <stdio.h> and “serial.c”

IO Connections: None for this procedure (Describe this)

Description: This is a simple serial test program that includes the required files to utilize standard input and output functions. The program will display an initial message and then do nothing.

Key Takes: This is the approach required to display information throughout the semester. (Explain each procedure)
*********************************************************/
// comment each line
#include <avr/io.h>
#include <stdio.h>
#include "serial.c"
#define F_CPU 16000000L
#include "util/delay.h"

int main(void)
{
	DDRA = 0x00;	// configure Port A for input
	PORTA = 0xFF;	// turn on the Port A pull-up resistors
	DDRC = 0xFF;	// configure Port C as an output
	PORTC = 0x00;	// start with all of the Port C values off (zero)

	init_UART();		// turn on and setup the serial port connection

	printf("Lab 3 - Procedure 4 - Sunny Park \n\r");

	while (1)
	{
		while(PINA > 0)
		{
			printf("Waiting for the push button to be released");
		}
		
		PORTC = 0x00;
		
		while(PINA == 0)	
		{
			printf("Waiting for the push button to be pressed");
		}
		
		PORTC = 0x18;
		_delay_ms(800);	// delay for 800mS
		PORTC = 0x24;
		_delay_ms(400);	// delay for 400mS
		PORTC = 0x42;
		_delay_ms(400);	// delay for 400mS
		PORTC = 0x81;
		_delay_ms(2000);	// delay for 2000mS
		
	}
}

