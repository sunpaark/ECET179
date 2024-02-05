/*
 * Procedure3.c
 *
 * Created: 10/20/2023 5:00:08 PM
 * Author : park1432
 */ 

#include <avr/io.h>
#include <stdio.h>
#define F_CPU 16000000L
#include <util/delay.h>		// gives us access to the delay library funcitons
#include "serial.c"
#include "scanned_keypad.c"

#define KEYPAD_DRIVE PORTF
#define KEYPAD_INPUT (PINK & 0x0F)

int main(void)
{
	uint16_t value;
	
	DDRF = 0xFF;	// setting the keypad (column) as input
	PORTF = 0x00;	// turn on pull up resistors
	DDRK = 0x00;	// setting the keypad (row) as input
	PORTK = 0xFF;	// turn on pull up resistors
	DDRC = 0xFF;	// configure Port A for input
	PORTC = 0x00;


	init_UART();	// initialize the UART for 9600, N, 8, 1

	printf("Scanning Keypad Testing Program\r");

	while(1)
	{
		printf("Enter the password\n\r");
		 
		value = get_four_digit();
		
		if (value == 0000)
		{
			printf("Correct\n\r");
			PORTC = 0x01;
		}
		
		else
		{
			printf("Incorrect\n\r");
			PORTC = 0x02;
			_delay_ms(300);
			PORTC = 0x00;
		}

	}
}