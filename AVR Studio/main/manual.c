


void manual()
{
	printf("Press a s w d \n \r");
	
	
	for(;;)
	{
		
		unsigned char variable=serial_read();
		if(variable=='w')
		{
			
			PORTC=(0<<PINC0)|(0<<PINC1)|(0<<PINC2)|(1<<PINC3);
			_delay_ms(40);
			PORTC=(0<<PINC0)|(1<<PINC1)|(0<<PINC2)|(0<<PINC3);
			_delay_ms(40);
			PORTC=(0<<PINC0)|(0<<PINC1)|(1<<PINC2)|(0<<PINC3);
			_delay_ms(40);
			PORTC=(1<<PINC0)|(0<<PINC1)|(0<<PINC2)|(0<<PINC3);
			_delay_ms(40);
			
			
		}

		else if(variable=='s')
		{
			PORTC=(1<<PINC0)|(0<<PINC1)|(0<<PINC2)|(0<<PINC3);
			_delay_ms(40);
			PORTC=(0<<PINC0)|(0<<PINC1)|(1<<PINC2)|(0<<PINC3);
			_delay_ms(40);
			PORTC=(0<<PINC0)|(1<<PINC1)|(0<<PINC2)|(0<<PINC3);
			_delay_ms(40);
			PORTC=(0<<PINC0)|(0<<PINC1)|(0<<PINC2)|(1<<PINC3);
			_delay_ms(40);
			
		}


		else if(variable=='a')
		{
			
			PORTC=(0<<PINC4)|(0<<PINC5)|(0<<PINC6)|(1<<PINC7);
			_delay_ms(40);
			PORTC=(0<<PINC4)|(1<<PINC5)|(0<<PINC6)|(0<<PINC7);
			_delay_ms(40);
			PORTC=(0<<PINC4)|(0<<PINC5)|(1<<PINC6)|(0<<PINC7);
			_delay_ms(40);
			PORTC=(1<<PINC4)|(0<<PINC5)|(0<<PINC6)|(0<<PINC7);
			_delay_ms(40);
			
		}

		else if(variable=='d')
		{
			PORTC=(1<<PINC4)|(0<<PINC5)|(0<<PINC6)|(0<<PINC7);
			_delay_ms(40);
			PORTC=(0<<PINC4)|(0<<PINC5)|(1<<PINC6)|(0<<PINC7);
			_delay_ms(40);
			PORTC=(0<<PINC4)|(1<<PINC5)|(0<<PINC6)|(0<<PINC7);
			_delay_ms(40);
			PORTC=(0<<PINC4)|(0<<PINC5)|(0<<PINC6)|(1<<PINC7);
			_delay_ms(40);
			
		}


		else
		{
			PORTC=0x00;
			printf("\n\rDo you want to exit? press y to exit and n to cancel:  \n \r");
			variable = serial_read();
			if(variable=='y')
			break;
			else
			
			printf("Press a s w d \n \r");
		}
	}
}





