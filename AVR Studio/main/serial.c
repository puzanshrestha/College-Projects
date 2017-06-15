int printCHAR(char character, FILE *stream)
{
	while(!(UCSRA&0x20));
	UDR=character;
	return 0;
}


void float_to_int(float f)
{
	
	int integer_part = floor(f);
	int fraction_part = (f - integer_part) * 100000;
	printf("%d.%d \r \n", integer_part, fraction_part);
	
	
	
	
}




unsigned char serial_read()
{
	while ((UCSRA & (1 << RXC)) == 0) {}; // Do nothing until data have been received and is ready to be read from UDR
	return UDR; // Fetch the received byte value into the variable "variable"
	
}

void serial_write(unsigned char data)
{
	while ((UCSRA & (1 << UDRE)) == 0) {}; // Do nothing until UDR is ready for more data to be written to it
	UDR=data; // Echo back the received byte back to the computer
	
}

int receive_coordinate()
{
	UDR="";
	int value=0;
	while(1)
	{
		
		int temp=serial_read();
		serial_write(temp);
		if(temp==13)
		{
			break;
			
		}
		if((temp>=48)&&(temp<=57))
		{
			
			temp=temp-48;
			value=value*10+temp;
			
			
		}
		else
		{
			printf("invalid number");
			break;
		}
	}
	return value;
	
}
