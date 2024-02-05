/*
 * Procedure4.c
 *
 * Created: 11/17/2023 12:00:00 PM
 * Author : park1432
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>		// gives us access to the delay library funcitons
#include "serial.c"
#include "My_Delay.c"

int main(void)
{
	//DDRA = 0xFF;		// configure Port A for input
	//PORTA = 0x00;
	DDRC = 0x00;
	PORTC = 0xFF;
	
	uint16_t value;
	char ch;
	
	init_UART();		// initialize the UART for 9600, N, 8,
	
	while(1)
	{
		printf("Hit the space bar to make a measurement\n\r");
		scanf("%c", &ch);
		
		while((PINC & 0x01) == 1)
		{
		}
		
		while((PINC & 0x01) == 0)
		{
		}
		
		TCNT1 = 0;
		TCCR1B = 2;
		
		while((PINC & 0x01) == 1)
		{
		}

		
		TCCR1B = 0;
		value = TCNT1 / 2;
		
		printf("%u", value);
		ms_Delay(1000);
	}
}