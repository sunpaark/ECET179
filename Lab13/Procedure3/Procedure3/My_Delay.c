
void ms_Delay(uint16_t);
void Delay_1ms(void);

/******************************************************************************************************************************
*
*	Module:			ms_delay(void)
*
*	Description:		This function will make continous calls to the delay_1ms() function until the desired amount of time has elasped.
*
*	Parameters:		This function receives the total number of milliseconds to delay as a parameters and returns no values
*
*	Resources:		Requires the delay_1ms() function.
*
*	Author:			Jeffrey J. Richardson			Date:	October 28, 2011
*
*	Mofified by:		none					Date:	
*
*	Warnings:		The accuracy of this function depends on the accuracy of the base 1 millisecond delay function
*
*******************************************************************************************************************************/
void ms_Delay(uint16_t time)
{
	uint16_t counter;
	
	for (counter = 0; counter < time; counter++)
	{
		Delay_1ms();
	}
}


/******************************************************************************************************************************
*
*	Module:		Delay_1ms(void)
*
*	Description:	This function utilizes Timer 1 to create a 1 millisecond delay by preloading and counting timer ticks
*			until the appropriate amount of time has elapsed.
*
*	Parameters:		This function receives no parameters and returns no values
*
*	Resources:		Timer1
*
*	Author:			Jeffrey J. Richardson			Date:	October 28, 2011
*
*	Modified by:	(none)							Date:
*	
*
*	Warnings:		This function requires dedicated use of Timer 1.  Other functions like PWM may not use this resource!!
*
*******************************************************************************************************************************/
void Delay_1ms(void)
{
	TCCR1A = 0x00;					// set timer for "normal port operation"


	TCNT1 = 65286;						// preload the timer/counter to count enough ticks for 1mS to elapse
	TCCR1B = 3;					// select an appropriate clock source 

	while( (TIFR1 & 0x01) == 0)		// wait for the timer to overflow by monitoring the timer overflow flag - bit 0 in TIFR0
	{
	}
	
	TCCR1B = 0;						// stop counting by setting the clock select bit to a zero = no clock source selected

	TIFR1 = TIFR1 | 0x01;			// clear the timer overflow flag for next time.  Flag is cleared by writing a '1' to it.

}

void Delay_10us(void)
{
	TCCR1A = 0x00;					// set timer for "normal port operation"


	TCNT1 = 65516;						// preload the timer/counter to count enough ticks for 10uS to elapse
	TCCR1B = 2;					// select an appropriate clock source

	while( (TIFR1 & 0x01) == 0)		// wait for the timer to overflow by monitoring the timer overflow flag - bit 0 in TIFR0
	{
	}
	
	TCCR1B = 0;						// stop counting by setting the clock select bit to a zero = no clock source selected

	TIFR1 = TIFR1 | 0x01;			// clear the timer overflow flag for next time.  Flag is cleared by writing a '1' to it.

}

void us_Delay(uint16_t time)
{
	uint16_t counter;
	
	for (counter = 0; counter < time; counter++)
	{
		Delay_1s();
	}
}