/*
 * Procedure4.c
 *
 * Created: 10/11/2023 4:02:42 PM
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
	DDRA = 0x00;	// configure Port A for input
	PORTA = 0xFF;	// turn on the Port A pull-up resistors
	
	init_LCD_UART();
	
	printf("LCD Test Program - Sunny Park \n\r");		// need an initial message

	while(1)
	{
		int num;
		
		while(PINA == 0)		// wait for pushbutton to be pressed
		{
			// printf("waiting for button\n\r");
		}
		
		put_command_LCD(0x41);		// this will turn on the LCD
		put_command_LCD(0x51);		// this will clear the LCD screen
		put_command_LCD(0x46);
		
		num = (rand() % 4);
		
		switch(num)
		{
			case 0:
			putstring_LCD("hello ");
			// put_command_LCD(0x01);		// this will clear the LCD screen
			break;
			
			case 1:
			putstring_LCD("hi ");
			// put_command_LCD(0x01);		// this will clear the LCD screen
			break;
			
			case 2:
			putstring_LCD("sup ");
			// put_command_LCD(0x01);		// this will clear the LCD screen
			break;
			
			case 3:
			putstring_LCD("yeah ");
			// put_command_LCD(0x01);		// this will clear the LCD screen
			break;
		}
		
		while (PINA != 0)
		{
		}
		
		// printf("%d", num);
	}
}