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
#include <avr/interrupt.h>
#include "serial.c"
#include "constants.c"
#include "manual.c"

#include "semimanual.c"
#include "automatic.c"

#define F_CPU 8000000UL
#define BAUD 9600
#define BAUDRATECALC  ((F_CPU/16/BAUD)-1)


unsigned char mode_select;



int main(void)
{
	FILE uart_str = FDEV_SETUP_STREAM(printCHAR, NULL, _FDEV_SETUP_RW);
	
	DDRC=0xff;
	PORTC=0x00;
	
	DDRB=0x00;
	PORTB=0xff;
	
	DDRA=0xff;;
	PORTA=0xff;
	
	DDRD=(0<<z_org)|(1<<PIND6);
	PORTD=(1<<z_org)|(0<<PIND6);
	
	UCSRA=0;
	UCSRB = (1 << RXEN) | (1 << TXEN)|(1<<RXCIE);;   // Turn on the transmission and reception circuitry
	UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1)|(0<<UMSEL)|(0<<USBS); // Use 8-bit character sizes

	UBRRH = (BAUDRATECALC >> 8); // Load upper 8-bits of the baud rate value into the high byte of the UBRR register
	UBRRL = BAUDRATECALC; // Load lower 8-bits of the baud rate value 
	
	stdout = &uart_str; 
	//sei();
    while(1)
    {
		
		
			printf("\n\r----------*****----------");
			printf("\n\rAutomatic PCB Drilling Machine \n \r");
			printf("Select Mode of Operation: \n \r a-Automatic Mode \n \r s-Semi Manual Mode \n\r m-Manual Mode");
			printf("\n\n \r\r");
			mode_select=serial_read();
				
		if(mode_select=='a')
		{
			initialize(3);
			initialize(1);
			initialize(2);
			
			int points_x[10];
			int points_y[10];
			printf("\n\rReady to Receive Coordinate.... \n\r");
			
			printf("\n \rTotal Number of coordinates =");
			int n=receive_coordinate();
			printf("\n\r\n\rSending X-Coordinates...\n\r");
			points_x[0]=0;
			points_y[0]=0;
			for(int i=1;i<=n;i++)
			{
				printf("x=");	
				points_x[i]=receive_coordinate();
				
				
				
			}
			
			
			printf("\n\r\n\rSending Y-Coordinates...\n\r");
			for(int i=1;i<=n;i++)
			{
				printf("y=");
				points_y[i]=receive_coordinate();
				
				
				
			}
			printf("\n \rDrilling Process has been started......");
			
			for(int i=0;i<n;i++)
			{
				printf("\n\r Currently Processing Point=(%d,%d)\n\r",points_x[i+1],points_y[i+1]);
				int diffx=points_x[i+1]-points_x[i];
				if(diffx>=0)
				forwardx(diffx);
				else
				reverse_x(-diffx);
				
				int diffy=(points_y[i+1]-points_y[i]);
				if(diffy>=0)
				forwardy(diffy);
				else
				reverse_y(-diffy);
				
				initialize(3);
				
				drill_z(35,1);
				
				initialize(3);
				
			}
			
			
			
			
		}
		
		else if(mode_select=='s')
		{
			initialize(3);
			initialize(1);
			initialize(2);
			
			printf("\n\rSemi Manual Mode\n \r");
			printf("enter the x coordinate: ");
			int x=receive_coordinate();
			printf("enter the y coordinate: ");
			int y=receive_coordinate();
			forwardx(x);
			forwardy(y);
			
			initialize(3);
			drill_z(35,1);
			initialize(3);
		
			
			
			
		}
		
		else if(mode_select=='m')
		{
			initialize(3);
			initialize(1);
			initialize(2);
			printf("Manual Mode: \n \r");
			
			
			manual();
			
		}
		
		else
		{
			printf("Invalid Mode");
		}
		
		
		
		 
    }
}














/*
ISR(USART_RXC_vect)
{
	
	unsigned char ret = UDR;
	
	if(ret=='k')
	{
		
	
		
		
		
	}
	else
	return UDR;
	

}


*/

