/*********************************************************
ECET 17900 - Introduction to Digital Systems - Lab #3

Name: Sunny Park
Date: 09/06/2023
Lab day and Time: Wednesday, 3:30

Included file: <stdio.h> and “serial.c”

IO Connections: None for this procedure

Description: This is a simple serial test program that includes the required files to utilize standard input and output functions. The program will display an initial message and then do nothing.

Key Takes: This is the approach required to display information throughout the semester.
*********************************************************/

#include <avr/io.h>
#include <stdio.h>
#include "serial.c"

int main(void)
{
	DDRA = 0x00;	// configure Port A for input
	PORTA = 0xFF;	// turn on the Port A pull-up resistors
	DDRC = 0xFF;	// configure Port C as an output
	PORTC = 0x00;	// start with all of the Port C values off (zero)

	init_UART();		// turn on and setup the serial port connection

	printf("Lab 3 - Procedure 3 ECHO - Sunny Park \n\r");

	while (1)
	{
		PORTC = PINA;	// read the value from PORTA and echo it to PORTC
	}
}

