/*
 * Procedure1.c
 *
 * Created: 11/1/2023 3:21:19 PM
 * Author : park1432
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>		// gives us access to the delay library funcitons
#include "serial.c"
//#include "ADC_student.c"


int main(void)
{
	DDRE = 0xFF;	// initialize OCR0A as output
	
	/*DDRC = 0x00;	// start with the port low
	PORTC = 0xFF;	// setup Port C for input*/

	init_UART();		// initialize the UART for 9600, N, 8, 1
	//init_ADC();

	TCCR3A = 0x01;		// fast PWM
	TCCR3B = 0x08;		// fast PWM

	TCCR3A = TCCR3A | 0x80;		// set on match
	TCCR3B = TCCR3B | 0x04;		// set frequency to 256 Hz from clock prescale

	OCR3A = 128;		// Set 50% duty cycle

	while(1)
	{
		printf("%u\n\r", OCR3A);		// display PWM output signal
	}
}
