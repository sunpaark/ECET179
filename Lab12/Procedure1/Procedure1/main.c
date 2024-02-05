/*
 * Procedure1.c
 *
 * Created: 11/10/2023 9:42:05 AM
 * Author : park1432
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>		// gives us access to the delay library funcitons
#include "serial.c"
//#include "ADC_student.c"

int main(void)
{
	DDRE = 0xFF;	// initialize OCR3A as output

	init_UART();		// initialize the UART for 9600, N, 8, 1
	uint16_t pulse_width = 0;

	TCCR3A = 0x02;		// fast PWM
	TCCR3B = 0x18;		// fast PWM

	TCCR3A = TCCR3A | 0xfc;		// set on match
	TCCR3B = TCCR3B | 0x02;
	
	ICR3 = 40000;		// set frequency to 256 Hz from clock prescale

	OCR3A = 1500 * 2;		// Timer 3 is initialized to 1500 uSec
	OCR3B = 1500 * 2; 		// Timer 3 is initialized to to 1500 uSec

	while(1)
	{
		printf("%u\n\r", OCR3A);		// display PWM output signal
	}
}
