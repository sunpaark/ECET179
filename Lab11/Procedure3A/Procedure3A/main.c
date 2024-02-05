/*
 * Procedure3A.c
 *
 * Created: 11/3/2023 4:18:55 PM
 * Author : park1432
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>		// gives us access to the delay library funcitons
#include "serial.c"
#include "ADC_student.c"

int main(void)
{
	DDRE = 0xFF;	// initialize OCR0A as output
	
	DDRC = 0x00;	// start with the port low
	PORTC = 0xFF;	// setup Port C for input

	init_UART();		// initialize the UART for 9600, N, 8, 1
	init_ADC();

	TCCR3A = 0x01;		// fast PWM
	TCCR3B = 0x08;		// fast PWM

	TCCR3A = TCCR3A | 0x80;		// set on match
	TCCR3B = TCCR3B | 0x04;		// set frequency to 256 Hz from clock prescale

	OCR3A = 128;		// Set 50% duty cycle

	while(1)
	{
		OCR3A = read_ADC();		// reads the latest ADC channel
		printf("Latest ADC value is = %u \r\n", OCR3A);	// displays the latest ADC result
		_delay_ms(100);			// delay for 100ms
	
	}
}
