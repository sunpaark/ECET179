/*
 * Procedure2.c
 *
 * Created: 10/11/2023 3:42:37 PM
 * Author : park1432
 */ 

#include <avr/io.h>
#include <stdio.h>
#define F_CPU 16000000L
#include <util/delay.h>		// gives us access to the delay library funcitons
#include "serial.c"
#include "serial_LCD.c"

int main(void)
{
	init_UART();		// initialize the UART
	
	printf("LCD Test Program - Sunny Park \n\r");		// need an initial message

	init_LCD_UART();

	put_command_LCD(0x41);		// this will turn on the LCD

	put_command_LCD(0x51);		// this will clear the LCD screen

	put_command_LCD(0x46);		// this will home the LCD

	putstring_LCD("This is my LCD");		// display a message
	
	put_cursor_LCD(0x40);
	
	putstring_LCD("Do not touch it");		// display a message

	while(1)
	{
	}
}