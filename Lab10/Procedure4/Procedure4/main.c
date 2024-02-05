/*
 * Procedure4.c
 *
 * Created: 10/25/2023 4:33:11 PM
 * Author : park1432
 */ 

#include <avr/io.h>
#include <stdio.h>
#define F_CPU 16000000L
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
	uint16_t ADC_result0;
	
	init_UART();		// initialize the UART for 9600, N, 8, 1
	init_ADC();		// initialize ADC
	init_ADC_for_10bits();
	
	printf("ADC Test Program\n\r");

	while(1)
	{
		ADC_result0 = read_10bit_ADC_channel(0);		// reads the latest ADC channel
		printf("Latest ADC value is = %u \r\n", ADC_result0);	// displays the latest ADC result
		// _delay_ms(100);			// delay for 100ms

	}
}