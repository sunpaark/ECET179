// scanned_keypad.c file

#define KEYPAD_DRIVE PORTF
#define KEYPAD_INPUT (PINK & 0x0F)

uint8_t key_press(void);
uint8_t read_scanned_keypad(void);
uint8_t get_BCD_key(void);
uint16_t get_four_digit(void);
/*********************************************************
This function determines whether a key is pressed on the keypad. However, it's important to note that it only indicates if a key is activated and does not specifically identify which key is pressed. 
If the input from each row is not activated (high), it returns a true value (1) indicating that a key is pressed. However, if a key is pressed, it outputs a 0, indicating that a key is not pressed.
*********************************************************/

uint8_t key_press(void)
{
	KEYPAD_DRIVE = 0x00;		// output a low to each column
	
	if (KEYPAD_INPUT != 0x0F)	// is a key pressed?
	{
		key_press() != 0;		// return a true value indicating that a key is pressed
	}

	else
	{
		key_press() == 0;		// return a 0 indicating that a key is not pressed
	}
}


/*********************************************************
This function identifies which key is pressed on the keypad. It first checks the activated column and then outputs the appropriate value based on the pressed key.
*********************************************************/

uint8_t read_scanned_keypad(void)
{
	uint8_t value;
	value = 0xFF;			// start with a return value of 0xFF
	
	while(key_press() == 0)	// wait until a key is pressed
	{
	}
	_delay_ms(25);		// insert a delay to deal with bounce

	KEYPAD_DRIVE = 0xFE;			// activate first column
	if (KEYPAD_INPUT != 0x0F)		// is it in this column?
	{
		if (KEYPAD_INPUT == 0x0E)	// 1st row
		{
			value = 1;
		}

		if (KEYPAD_INPUT == 0x0D)	// 2nd row
		{
			value = 4;
		}

		if (KEYPAD_INPUT == 0x0B)	// 3rd row
		{
			value = 7;
		}

		if (KEYPAD_INPUT == 0x07)	// 4th row
		{
			value = 14;			// represents ‘*’
		}

		KEYPAD_DRIVE = 0xFD;			// activate second column
		if (KEYPAD_INPUT != 0x0F)		// is it in this column?
		{
			if (KEYPAD_INPUT == 0x0E)	// 1st row
			{
				value = 2;
			}

			if (KEYPAD_INPUT == 0x0D)	// 2nd row
			{
				value = 5;
			}

			if (KEYPAD_INPUT == 0x0B)	// 3rd row
			{
				value = 8;
			}

			if (KEYPAD_INPUT == 0x07)	// 4th row
			{
				value = 0;
			}
		}

		KEYPAD_DRIVE = 0xFB;			// activate third column
		if (KEYPAD_INPUT != 0x0F)		// is it in this column?
		{
			if (KEYPAD_INPUT == 0x0E)	// 1st row
			{
				value = 3;
			}

			if (KEYPAD_INPUT == 0x0D)	// 2nd row
			{
				value = 6;
			}

			if (KEYPAD_INPUT == 0x0B)	// 3rd row
			{
				value = 9;
			}

			if (KEYPAD_INPUT == 0x07)	// 4th row
			{
				value = 15;			// represent ‘#’
			}
		}

		KEYPAD_DRIVE = 0xF7;			// activate last column
		if (KEYPAD_INPUT != 0x0F)		// is it in this column?
		{
			if (KEYPAD_INPUT == 0x0E)	// 1st row
			{
				value = 0x0A;			// represent ‘A’
			}

			if (KEYPAD_INPUT == 0x0D)	// 2nd row
			{
				value = 0x0B;			// represent ‘B’
			}

			if (KEYPAD_INPUT == 0x0B)	// 3rd row
			{
				value = 0x0C;			// represent ‘C’
			}

			if (KEYPAD_INPUT == 0x07)	// 4th row
			{
				value = 0x0D;			// represent ‘D’
			}
		}

		return value;
	}


/*************************************************************************
This function will read values from the keypad and only return a value if it is a BCD number.  
If the value is not BCD, then it will be ignored 	and the user must enter another value.  
This will be repeated until a valid BCD value is entered.
**************************************************************************/
uint8_t get_BCD_keypad(void)
{
	uint8_t key;
	
	do
	{
		key = read_scanned_keypad();
	} while (key < 9);		// continue to run the loop until a valid BCD

	return key;
}

/***************************************************************************
This function will get four BDC values and combine them into a single value
****************************************************************************/
uint16_t get_four_digit(void)
{
	uint8_t ones, tens, hundreds, thousands;
	uint16_t value;
	
	
	return value;

}
