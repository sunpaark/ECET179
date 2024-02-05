/*******************************

	ECET 17900 - Introduction to Digital Systems

	Serial functions required to send data through UART1 to the MP3 Player Module
	
	Name:	Jeffrey J. Richardson
	
	Date:	March 2015

	Description:
		(should be filled in by the students)



********************************/

void init_MP3_UART(void);
void putchar_MP3(char ch);
void putstring_MP3(char *str);


void init_MP3_UART(void)
{

	UCSR1A = 0x00;			
	UCSR1B = 0x18;			// enable UART TX and RX
	UCSR1C = 0x06;			// set the UART for N, 8, 1
	UBRR1L = 103;			// set BAUD Rate for 9600 with 16MHz clock
	UBRR1H = 0;

}


// the following function sends a single character out of the serial port
void putchar_MP3(char ch)
{

    while ( (UCSR1A & (1 << UDRE1)) == 0 )		// wait until there is room in the transmit buffer
	{
	}

    UDR1 = ch;									// load the character into the UART data register
}

void putstring_MP3(char *str)
{
	while(*str != 0)
	{
		putchar_MP3(*str++);
	}
}