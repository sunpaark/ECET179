/*
 * Procedure1.c
 *
 * Created: 10/18/2023 3:44:12 PM
 * Author : park1432
 */ 

#include <avr/io.h>
#include <stdio.h>
#define F_CPU 16000000L
#include <util/delay.h>		// gives us access to the delay library funcitons

#include "serial.c"
#include "scanned_keypad.c"


int main(void)
{
	uint8_t value;
	
	DDRF = 0xFF;	// setting the keypad (column) as input
	PORTF = 0x00;	// turn on pull up resistors
	DDRK = 0x00;	// setting the keypad (row) as input
	PORTK = 0xFF;	// turn on pull up resistors

	init_UART();	// initialize the UART for 9600, N, 8, 1

	printf("Scanning Keypad Testing Program\r");

	while(1)
	{
		if (key_press() != 0)		// is a key being pressed?
		{
			printf("A key is being pressed!\n");
		}
		
		// once the above works, comment out the if construct and uncomment these
		 value = read_scanned_keypad();
		 printf("The value is %", value);

	
}
}
