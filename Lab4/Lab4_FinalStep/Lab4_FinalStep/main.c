/*
 * Lab4_FinalStep.c
 *
 * Created: 9/13/2023 4:02:48 PM
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
	
	uint16_t counter = 0;
	
    while (1) 
    {
		while(PINA == 0)
		{
		}
		PORTC = 0xFF;
		
		counter = 600;
		
		while(counter > 0)
		{
			if (PINA > 0)
			{
				counter = 600;
			}
			
			else
			{
				_delay_ms(50);
				counter--;
				printf("%d", counter/20);
			}

		}
		PORTC = 0x00;
    }
}

