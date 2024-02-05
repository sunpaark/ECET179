/*
 * Lab1IDEIntro.c
 *
 * Created: 8/30/2023 4:19:32 PM
 * Author : park1432
 */ 

#include <avr/io.h>
#include <stdio.h>  // includes standard IO library
#include "serial.c"  // includes local serial.c file

int main(void)
{	DDRA = 0xFF; // configure PORTA as outputs
    init_UART(); // setups up serial communication
	PORTA = 0x55;  // test program for PORTA
	
	while (1) 
    {
    }
}

