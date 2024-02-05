/***********************************************************************************
	Analog to Digital.C
	
	(fill this in)
		
************************************************************************************/

void init_ADC(void);
uint8_t read_ADC(void);
uint8_t read_ADC_channel(uint8_t);

void init_ADC_for_10bits(void);
uint16_t read_10bit_ADC(void);
uint16_t read_10bit_ADC_channel(uint8_t);


void init_ADC(void)
{
                                // setup the Analog to Digital Converter
	ADMUX = 0x40;		// start by selecting the voltage reference - Avcc
	ADMUX = ADMUX | 0x00;   // Select the default ADC channel - channel 0 in this case
	ADMUX = ADMUX | 0x20;	// set for Left Justified - Only using 8 bit of resolution
	
	ADCSRA = 0x07;	// select the ADC clock frequency - Clock / 128
	ADCSRA = ADCSRA | 0x80;	// enable the ADC

}

	
uint8_t read_ADC(void)
{
	uint8_t value;			// 8-bit value to hold the result
	
	ADMUX = ADMUX & 0xE0;		// clear the channel data

	ADCSRA = ADCSRA | 0x40;	// start a conversion
	
	while( (ADCSRA & 0x10) == 0 )	// wait for conversion to be completed
	{
	}
	
	value = ADCH;		// get the upper 8-bits
	ADCSRA = ADCSRA | 0x80;	// clear the conversion flag
	
	return value;			// send back the 8-bit result
}


// uncomment this when ready to complete this portion of the lab
/*
// this version allows the user to select which channel on Port C to convert
//	
uint8_t read_ADC_channel(uint8_t channel)
{
	uint8_t value;			// 8-bit value to hold the result
	
	ADMUX = ADMUX & 0xE0;		// clear the channel data
	
	ADMUX = ADMUX | _______;	// add the channel data here!

	ADCSRA = ADCSRA | _____;	// start a conversion
	
	while( (ADCSRA & ______) == 0 )	// wait for conversion to be completed
	{
	}
	
	value = _______;		// get the upper 8-bits
	ADCSRA = ADCSRA | ______;	// clear the conversion flag
	
	return value;			// send back the 8-bit result
}
*/

/*
void init_ADC_for_10bits(void)
{
                                // setup the Analog to Digital Converter
	ADMUX = 0x40;		// start by selecting the voltage reference - Avcc
	ADMUX = ADMUX | 0x00;   // Select the default ADC channel - channel 0 in this case
	ADMUX = ADMUX & ____;	// set for Right Justified
	
	ADCSRA = ______;	// select the ADC clock frequency - Clock / 128
	ADCSRA = ADCSRA | _____;	// enable the ADC

}
*/

/*	
uint16_t read_10bit_ADC(void)
{
	uint8_t upper, lower;
	uint16_t value;			// 16-bit value to hold the result
	
	ADMUX = ADMUX & 0xE0;		// clear the channel data

	ADCSRA = ADCSRA | _____;	// start a conversion
	
	while( (ADCSRA & ______) == 0 )	// wait for conversion to be completed
	{
	}
	
	lower = ADCL;		// get the lower 8-bits of the conversion
	upper = ADCH;		// get the upper 2 bits
	
	value = _______;		// combine the upper and lower bits here to form a 10-bit number
	
	ADCSRA = ADCSRA | ______;	// clear the conversion flag
	
	return value;			// send back the 8-bit result
}
*/

// uncomment this when ready to complete this portion of the lab
/*
// this version allows the user to select which channel on Port C to convert
//	
uint16_t read_10bit_ADC_channel(uint8_t channel)
{
	uint8_t upper, lower;
	uint16_t value;			// 16-bit value to hold the result
	
	ADMUX = ADMUX & 0xE0;		// clear the channel data
	
	ADMUX = ADMUX | _______;	// add the channel data here!

	ADCSRA = ADCSRA | _____;	// start a conversion
	
	while( (ADCSRA & ______) == 0 )	// wait for conversion to be completed
	{
	}

	lower = ADCL;		// get the lower 8-bits of the conversion
	upper = ADCH;		// get the upper 2 bits
	
	value = _______;		// combine the upper and lower bits here to form a 10-bit number

	ADCSRA = ADCSRA | ______;	// clear the conversion flag
	
	return value;			// send back the 10-bit result
}
*/
