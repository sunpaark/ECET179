/*
 * Procedure2.c
 *
 * Created: 10/25/2023 3:36:52 PM
 * Author : park1432
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>		// gives us access to the delay library funcitons
#include "serial.c"
#include "ADC_student.c"
#define F_CPU 16000000L

int main(void)
{
	uint8_t ADC_result;
	init_UART();		// initialize the UART for 9600, N, 8, 1
	init_ADC();		// initialize ADC
	
	printf("ADC Test Program\n\r");

	while(1)
	{
		ADC_result = read_ADC_channel(1);		// reads the latest ADC channel
		printf("%u \r\n", ADC_result);	// displays the latest ADC result
		_delay_ms(100);			// delay for 100ms
	}
}
