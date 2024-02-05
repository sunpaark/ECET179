/*
 * Procedure2.c
 *
 * Created: 10/4/2023 4:16:44 PM
 * Author : park1432
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "serial.c"
#define F_CPU 16000000L
#include <util/delay.h>

#define SET_BIT(x, y) x = x | (1<<y)
#define CLR_BIT(x, y) x = x & ~(1<<y)

int main(void)
{
	init_UART();		// turn on and setup the serial port connection
	DDRA = 0x00;	// configure Port A for input
	PORTA = 0xFF;	// turn on the Port A pull-up resistors
	DDRC = 0xFF;	// configure Port C as an output
	PORTC = 0x00;	// start with all of the Port C values off (zero)

	uint8_t state = 0;	// initialize the variable “state”
	uint8_t state2 = 0;

	while(1)
	{
		
		while ((PINA & 0x03) == 0x00)		// waiting for push button to be pressed
		{
		}
		
		
		
		if ((PINA & 0x01) != 0x00)
		{
			state++;
			if (state == 1)			// when the button is pressed initially
			{
				SET_BIT(PORTC, 0);
			}


			if (state == 2)			// when the button is pressed for the second time
			{
				SET_BIT(PORTC, 1);		// LED 2 is activated
			}
		

			if (state == 3)			// when the button is pressed for the third time
			{
				CLR_BIT(PORTC, 0);
			}

			if (state == 4)		// when the button is pressed for the fourth time
			{
				CLR_BIT(PORTC, 1);	// LED 2 is deactivated
				state = 0;
			}
		}
		
		if ((PINA & 0x02) != 0x00)
		{
			state2++;
			if (state2 == 1)			// when the button is pressed initially
			{
				SET_BIT(PORTC, 2);
			}


			if (state2 == 2)			// when the button is pressed for the second time
			{
				SET_BIT(PORTC, 3);		// LED 2 is activated
			}
			

			if (state2 == 3)			// when the button is pressed for the third time
			{
				CLR_BIT(PORTC, 2);
			}

			if (state2 == 4)		// when the button is pressed for the fourth time
			{
				CLR_BIT(PORTC, 3);	// LED 2 is deactivated
				state2 = 0;
			}
		}

		while((PINA & 0x03) != 0x00)		// waiting for the push button is released
		{
		}
	}
}