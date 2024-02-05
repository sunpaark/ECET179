/*
 * Procedure5.c
 *
 * Created: 11/29/2023 4:50:38 PM
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
	DDRA = 0x00;
	PORTA = 0xFF;
	
	init_UART();			// initialize the UART for 9600, N, 8, 1

	printf("MP3 Player Test Program\n\r");	// need an initial message
	
	init_LCD_UART();		// turn on and initial the UART for the LCD

	put_command_LCD(0x0E);		// turn on the LCD

	put_command_LCD(0x01);		// clear and home the LCD

	putstring_LCD("LCD Test Message!?");		// display a message

	init_MP3_UART();		// turn on and initial the UART for the MP3 Player

	putstring_MP3("MP3 Player Test Message?");	// display a test message
	
	unsigned char buffer[25];

	while(1)
	{
		while(PINA == 0)
		{
		}
		
		switch(PINA)
		{
			case 1:
			{
				putstring_MP3("PC P\r\n");
				putstring_LCD("Play\r\n");		// display a message
				break;
			}
			
			case 2:
			{
				putstring_MP3("PC S\r\n");
				putstring_LCD("Stop\r\n");		// display a message
				break;
			}
			
			case 4:
			{
				sprintf(buffer, "PC F/Track0001.mp3\r");
				putstring_MP3(buffer);
				break;
			}
			
			case 8:
			{
				sprintf(buffer, "PC F/Track0002.mp3\r");
				putstring_MP3(buffer);
				break;
			}
		}
		
		while (PINA == 1)
		{
		}
	}
}