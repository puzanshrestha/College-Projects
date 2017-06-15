/*
 * transmitter_section.c
 *
 * Created: 02-Jul-14 10:08:48 PM
 *  Author: Pujan
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <float.h>
#include "serial.c"
#include "constants.c"
#include "manual.c"
#include "semimanual.c"
#include "automatic.c"

#define F_CPU 8000000UL
#define BAUD 9600
#define BAUDRATECALC  ((F_CPU/16/BAUD)-1)




int main(void)
{
	FILE uart_str = FDEV_SETUP_STREAM(printCHAR, NULL, _FDEV_SETUP_RW);
	unsigned char variable;
	DDRC=0xff;
	PORTC=0x00;
	
	DDRB=0x00;
	PORTB=0xff;
	
	
	UCSRB = (1 << RXEN) | (1 << TXEN);   // Turn on the transmission and reception circuitry
	UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1)|(0<<UMSEL)|(0<<USBS); // Use 8-bit character sizes

	UBRRH = (BAUDRATECALC >> 8); // Load upper 8-bits of the baud rate value into the high byte of the UBRR register
	UBRRL = BAUDRATECALC; // Load lower 8-bits of the baud rate value 
	unsigned char mode_select;
	stdout = &uart_str; 
    while(1)
    {

		printf("\n\r----------*****----------");
		printf("\n\rAutomatic PCB Drilling Machine \n \r");
		_delay_ms(250);
		printf("Select Mode of Operation: ");
		printf("\n\n \r\r");
		_delay_ms(200);
		
		mode_select=serial_read();
		
		
		
		if(mode_select=='a')
		{
			initialize();
			printf("Automatic Mode Selected Currently This mode is Under Development Sorry \n\r");
		}
		
		else if(mode_select=='s')
		{
			initialize();
			printf("Semi Manual Mode\n \r");
			printf("enter the x coordinate: ");
			int x=receive_coordinate();
			printf("enter the y coordinate: ");
			int y=receive_coordinate();
			_delay_ms(4);
			semimanual(x,y);
			
			
		}
		
		else if(mode_select=='m')
		{
			initialize();
			printf("Manual Mode: \n \r");
			
			manual();
			
		}
		
		else
		{
			printf("Invalid Mode");
		}
		
		
		
		
		 
    }
}









