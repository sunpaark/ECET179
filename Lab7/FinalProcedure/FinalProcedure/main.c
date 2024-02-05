/*
 * FinalProcedure.c
 *
 * Created: 10/4/2023 4:29:47 PM
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
		char key;
		
		printf("%d", PINA);
		scanf("%c", &key);
		
		/** if ((PINA & 0x01) != 0x00)
		{**/
			switch(key)
			{
				case 'A':
				SET_BIT(PORTC, 0);
				break;
				
				case 'B':
				SET_BIT(PORTC, 1);		// LED 2 is activated
				break;
				
				case 'C':
				SET_BIT(PORTC, 2);
				break;
				
				case 'D':
				SET_BIT(PORTC, 3);
				break;
				
				case 'E':
				SET_BIT(PORTC, 4);
				break;
				
				case 'F':
				SET_BIT(PORTC, 5);
				break;
				
				case 'a':
				CLR_BIT(PORTC, 0);
				break;
				
				case 'b':
				CLR_BIT(PORTC, 1);
				break;
				
				case 'c':
				CLR_BIT(PORTC, 2);
				break;
				
				case 'd':
				CLR_BIT(PORTC, 3);
				break;
				
				case 'e':
				CLR_BIT(PORTC, 4);
				break;
				
				case 'f':
				CLR_BIT(PORTC, 5);
				break;
			}
		// }

		/** while((PINA & 0x03) != 0x00)		// waiting for the push button is released
		{
		}**/
	}
}