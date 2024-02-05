/*
 * Procedure3.c
 *
 * Created: 11/29/2023 4:10:44 PM
 * Author : park1432
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>		// gives us access to the delay library funcitons
#include "serial.c"
#include "serial_LCD.c"
#include "serial_MP3.c"

int main(void)
{
	init_UART();			// initialize the UART for 9600, N, 8, 1

	printf("MP3 Player Test Program\n\r");	// need an initial message
	
	init_LCD_UART();		// turn on and initial the UART for the LCD

	put_command_LCD(0x0E);		// turn on the LCD

	put_command_LCD(0x01);		// clear and home the LCD

	putstring_LCD("LCD Test Message!?");		// display a message

	init_MP3_UART();		// turn on and initial the UART for the MP3 Player

	putstring_MP3("MP3 Player Test Message?");	// display a test message

	while(1)
	{
		while(PINC == 0)
		{
		}
		
		switch(PINC)
		{
			case 1:
			{
				printf("Play\n\r");
				break;
			}
			
			case 2:
			{
				printf("Stop\n\r");
				break;
			}
			
			case 4:
			{
				printf("Next\n\r");
				break;
			}
			
			case 8:
			{
				printf("Repeat\n\r");
				break;
			}
		}
		
		while (PINC == 1)
		{
		}
	}
}