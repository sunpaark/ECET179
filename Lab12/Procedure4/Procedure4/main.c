/*
 * Procedure4.c
 *
 * Created: 11/10/2023 11:16:44 AM
 * Author : park1432
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>		// gives us access to the delay library funcitons
#include "serial.c"
#include "ADC_student.c"

void init_ADC_for_10bits(void)
{
	// setup the Analog to Digital Converter
	ADMUX = 0x40;		// start by selecting the voltage reference - Avcc
	ADMUX = ADMUX | 0x00;   // Select the default ADC channel - channel 0 in this case
	ADMUX = ADMUX & ~0x20;	// set for Right Justified
	
	ADCSRA = 0x07;	// select the ADC clock frequency - Clock / 128
	ADCSRA = ADCSRA | 0x80;	// enable the ADC

}

uint16_t read_10bit_ADC(void)
{
	uint8_t upper, lower;
	uint16_t value;			// 16-bit value to hold the result
	
	ADMUX = ADMUX & 0xE0;		// clear the channel data

	ADCSRA = ADCSRA | 0x40;	// start a conversion
	
	while( (ADCSRA & 0x10) == 0 )	// wait for conversion to be completed
	{
	}
	
	lower = ADCL;		// get the lower 8-bits of the conversion
	upper = ADCH;		// get the upper 2 bits
	
	value = (upper << 8) | lower;		// combine the upper and lower bits here to form a 10-bit number
	
	ADCSRA = ADCSRA | 0x10;	// clear the conversion flag
	
	return value;			// send back the 8-bit result
}


uint16_t read_10bit_ADC_channel(uint8_t channel)
{
	uint8_t upper, lower;
	uint16_t value;			// 16-bit value to hold the result
	
	ADMUX = ADMUX & 0xE0;		// clear the channel data
	
	ADMUX = ADMUX | channel;	// add the channel data here!

	ADCSRA = ADCSRA | 0x40;	// start a conversion
	
	while( (ADCSRA & 0x10) == 0 )	// wait for conversion to be completed
	{
	}

	lower = ADCL;		// get the lower 8-bits of the conversion
	upper = ADCH;		// get the upper 2 bits
	
	value = (upper << 8) | lower;;		// combine the upper and lower bits here to form a 10-bit number

	ADCSRA = ADCSRA | 0x10;	// clear the conversion flag
	
	return value;			// send back the 10-bit result
}

int main(void)
{
	DDRE = 0xFF;	// initialize OCR3A as output

	init_UART();		// initialize the UART for 9600, N, 8,
	init_ADC();
	uint16_t pulse_width = 0;
	uint16_t value;
	
	TCCR3A = 0x02;		// fast PWM
	TCCR3B = 0x18;		// fast PWM

	TCCR3A = TCCR3A | 0xA0;		// set on match
	TCCR3B = TCCR3B | 0x02;
	
	ICR3 = 40000;		// set frequency to 256 Hz from clock prescale

	OCR3A = 1500 * 2;		// Timer 3 is initialized to 1500 uSec

	while(1)
	{
		value = 4*read_ADC_channel(0);
	    value = value + 1000;
		OCR3A = value;
		printf("%u\n\r", OCR3A);
		
	}
}