/*******************************

	ECET 17900 - Introduction to Digital Systems

	Name:	Jeffrey J. Richardson
	Date:	October 5, 2023

	
	Special UART routines to communicate with the LCD


********************************/

void init_LCD_UART(void);
void putchar_LCD(char);
void put_command_LCD(unsigned char);
void put_cursor_LCD(unsigned char);
void putstring_LCD(unsigned char *str);


void init_LCD_UART(void)
{

	UCSR3A = 0x00;			
	UCSR3B = 0x18;			// enable UART TX and RX
	UCSR3C = 0x06;			// set the UART for N, 8, 1
	UBRR3L = 103;			// set BAUD Rate for 9600 with 16MHz clock
	UBRR3H = 0;

}


// the following function sends a single character out of the serial port - to the LCD
void putchar_LCD(char ch)
{

    while ( (UCSR3A & (1 << UDRE3)) == 0 )		// wait until there is room in the transmit buffer
	{
	}

    UDR3 = ch;									// load the character into the UART data register

}


void put_command_LCD(unsigned char cmd)
{
	putchar_LCD(0xFE);
	putchar_LCD(cmd);
	
	_delay_ms(5);
}

void put_cursor_LCD(unsigned char cmd)
{
	putchar_LCD(0xFE);
	putchar_LCD(0x45);
	putchar_LCD(cmd);
	
	_delay_ms(5);
}

void putstring_LCD(unsigned char *str)
{
	while( *str != 0)
	{
		putchar_LCD(*str++);
	}
}

/*** void send_address_LCD(unsigned char cmd)
{
	putchar(0xFE);		// indicate the next character is a command
	putchar(0x45);		// send the command to move the cursor
	
	putchar(0x40);		// send the Cursor to middle of line 1
	
	_delay_ms(5);		// give the LCD time to execute the command
} ***/