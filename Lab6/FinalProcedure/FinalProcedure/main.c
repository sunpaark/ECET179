/*
 * FinalProcedure.c
 *
 * Created: 9/27/2023 5:18:19 PM
 * Author : park1432
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "serial.c"

#define F_CPU 16000000L
#include <util/delay.h>

#define SET_BIT(x, y) x = x | (1<<y)
#define CLR_BIT(x, y) x = x & ~(1<<y)

void send_stepper(uint16_t steps, uint8_t direction);
void home_stepper(void);

int main(void)
{
	uint16_t steps = 0;
	uint8_t direction = 0;
	uint16_t first = 0;
	uint16_t second = 0;
	uint16_t third = 0;
	uint16_t MAX = 48;

	DDRA = 0x00;		// configure Port A for input
	PORTA = 0xFF;		// turn on the Port A pull-up resistors
	DDRC = 0xFF;		// configure Port C as an output
	PORTC = 0x00;		// start with all of the Port C values off (zero)
	init_UART();		// turn on and setup the serial port connection

	// setup the data direction registers per your IO diagram
	// set up the serial port

	printf("Lab 6 - Controlling Stepper Motors - Sunny Park\n\r");

	while(1)
	{   
		
		home_stepper();
		printf("\n\n\rEnter the first number: ");		// asks for steps from user
		scanf("%u", &first);										// receive steps value
		
		printf("\n\n\rEnter the second number: ");		// asks for direction
		scanf("%u", &second);										// receive direction value
		
		printf("\n\n\rEnter the third number: ");		// asks for direction
		scanf("%u", &third);										// receive direction value

		printf("%u %u %u", first, second, third);

		send_stepper(steps, direction);								// send value
		
		send_stepper(48, 1);
		
		_delay_ms(2000);
		
		send_stepper((MAX - first), 1);
		
		_delay_ms(2000);
		send_stepper(48, 0);
		
		send_stepper((MAX - first), 0);
		
		send_stepper(second, 0);
		_delay_ms(2000);
		
		send_stepper((second-third), 1);
		_delay_ms(2000);
		
		
	}
}

void send_stepper (uint16_t steps, uint8_t direction)		// function for send_stepper
{

	for (int count = 0; count < steps; count++)
	{
		if (direction != 0)
		{
			SET_BIT(PORTC, 1);
		}
		else
		{
			CLR_BIT(PORTC, 1);
		}
		
		SET_BIT(PORTC, 0);			// activate bit 0 of PORTC
		_delay_ms(25);			// delay for 250mS
		CLR_BIT(PORTC, 0);		// deactivate bit 0 of PORTC
		_delay_ms(50);			// delay for 500mS
	}
}

void home_stepper(void)
{
	while((PINA & 0x01) == 0)
	{
		SET_BIT(PORTC, 0);
		_delay_ms(25);
		CLR_BIT(PORTC, 0);
		_delay_ms(75);
	}
}