/*
 * main.c
 *
 * Created: 11/15/2023 3:42:16 PM
 *  Author: park1432
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>		// gives us access to the delay library funcitons
#include "serial.c"
#include "My_Delay.c"

int main(void)
{
	DDRA = 0xFF;		// configure Port A for input
	
	while(1)
	{
		PORTA =~ PORTA;		// toggle the port
		Delay_1mS();			// call the delay
	}
}
