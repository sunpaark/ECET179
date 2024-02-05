/*
 * Procedure5.c
 *
 * Created: 10/27/2023 4:24:26 PM
 * Author : park1432
 */ 

#include <avr/io.h>
#include <stdio.h>
#define F_CPU 16000000L
#include <util/delay.h>		// gives us access to the delay library funcitons
#include <stdlib.h>
#include "serial.c"
#include "scanned_keypad.c"
#include "serial_LCD.c"

#define KEYPAD_DRIVE PORTF
#define KEYPAD_INPUT (PINK & 0x0F)

int main(void)
{
	uint16_t value;
	uint16_t password;
	
	DDRF = 0xFF;	// setting the keypad (column) as input
	PORTF = 0x00;	// turn on pull up resistors
	DDRK = 0x00;	// setting the keypad (row) as input
	PORTK = 0xFF;	// turn on pull up resistors
	DDRC = 0xFF;	// configure Port A for input
	PORTC = 0x00;


	init_UART();	// initialize the UART for 9600, N, 8, 1
	init_LCD_UART();

	printf("Scanning Keypad Testing Program\r");

	while(1)
	{
		put_command_LCD(0x41);		// this will turn on the LCD
		put_command_LCD(0x51);		// this will clear the LCD screen
		put_command_LCD(0x46);
		
		password = (rand() % 100);
		printf("%d\n \r", password);
		
		while(key_press() == 0)
		{
			printf("Enter the password\n\r");
			
			value = get_four_digit();
			
			if (value > password)
			{
				printf("Too High!\n\r");
			}
			
			if (value < password)
			{
				printf("Too Low!\n\r");
			}
			if(value == password)
			{
				printf("Correct\n\r");
			}
		}
	}
}