#define A1 PINC0
#define A1_ PINC1
#define B1 PINC2
#define B1_ PINC3

#define A2 PINC4
#define A2_ PINC5
#define B2 PINC6
#define B2_ PINC7


#define A3 PINA0
#define A3_ PINA1
#define B3 PINA2
#define B3_ PINA3

#define x_org PINB0
#define y_org PINB1

#define x_max PINB2
#define y_max PINB3

#define z_org PIND7



void initialize(int n)
{
	
	
		if(n==1)
		{
			printf("\n\rInitializing X....\n \r");	
			int delta=0;
			while(1)
			{
				
				if(bit_is_clear(PINB,0))
				break;
				
				PORTC=(0<<A1)|(0<<A1_)|(0<<B1)|(1<<B1_);
				_delay_ms(30);
				delta++;
				printf("x-axis reverse delta=-%d \n \r",delta);
				_delay_ms(100);
				if(bit_is_clear(PINB,0))
				break;
				
				PORTC=(0<<A1)|(1<<A1_)|(0<<B1)|(0<<B1_);
				_delay_ms(30);
				delta++;
				printf("x-axis reverse delta=-%d \n \r",delta);
				_delay_ms(100);
				if(bit_is_clear(PINB,0))
				break;
				
				PORTC=(0<<A1)|(0<<A1_)|(1<<B1)|(0<<B1_);
				_delay_ms(30);
				delta++;
				printf("x-axis reverse delta=-%d \n \r",delta);
				_delay_ms(100);
				if(bit_is_clear(PINB,0))
				break;
				
				PORTC=(1<<A1)|(0<<A1_)|(0<<B1)|(0<<B1_);
				_delay_ms(30);
				delta++;
				printf("x-axis reverse delta=-%d \n \r",delta);
				_delay_ms(100);
				if(bit_is_clear(PINB,0))
				break;
				
			}
			printf("X-Axis Initialization Completed\n \r\n");
		}
		
		
		if(n==2)
		{	
			printf("\n\rInitializing Y....\n \r");
			int delta=0;
			while(1)
			{
				if(bit_is_clear(PINB,1))
				break;
				
				PORTC=(0<<A2)|(0<<A2_)|(0<<B2)|(1<<B2_);
				_delay_ms(30);
				delta++;
				printf("Y-axis reverse delta=-%d \n \r",delta);
				_delay_ms(100);
				if(bit_is_clear(PINB,1))
				break;
				
				PORTC=(0<<A2)|(1<<A2_)|(0<<B2)|(0<<B2_);
				_delay_ms(30);
				delta++;
				printf("Y-axis reverse delta=-%d \n \r",delta);
				_delay_ms(100);
				if(bit_is_clear(PINB,1))
				break;
				
				PORTC=(0<<A2)|(0<<A2_)|(1<<B2)|(0<<B2_);
				_delay_ms(30);
				delta++;
				printf("Y-axis reverse delta=-%d \n \r",delta);
				_delay_ms(100);
				if(bit_is_clear(PINB,1))
				break;
				
				PORTC=(1<<A2)|(0<<A2_)|(0<<B2)|(0<<B2_);
				_delay_ms(30);
				delta++;
				printf("Y-axis reverse delta=-%d \n \r",delta);
				_delay_ms(100);
				if(bit_is_clear(PINB,1))
				break;
				
			}
			PORTC=0x00;
			printf("Y-Axis Initialization Completed...\n \r");
		}
		
		
	
	if(n==3)
	{
		int delta=0;
		while(1)
		{
			if(bit_is_clear(PIND,7))
			break;
			PORTA=(0<<A3)|(0<<A3_)|(0<<B3)|(1<<B3_);
			_delay_ms(30);
			delta++;
			printf("\n\rZ-axis reverse delta=-%d",delta);
			if(bit_is_clear(PIND,7))
			break;
			
			PORTA=(0<<A3)|(1<<A3_)|(0<<B3)|(0<<B3_);
			_delay_ms(30);
			delta++;
			printf("\n\rZ-axis reverse delta=-%d",delta);
			if(bit_is_clear(PIND,7))
			break;
			
			PORTA=(0<<A3)|(0<<A3_)|(1<<B3)|(0<<B3_);
			_delay_ms(30);
			delta++;
			printf("\n\rZ-axis reverse delta=-%d",delta);
			if(bit_is_clear(PIND,7))
			break;
			
			PORTA=(1<<A3)|(0<<A3_)|(0<<B3)|(0<<B3_);
			_delay_ms(30);
			delta++;
			printf("\n\rZ-axis reverse delta=-%d",delta);
			if(bit_is_clear(PIND,7))
			break;
		}
		PORTA=0x01010101;
		PORTD=(0<<PIND6);
		
		
	}
	
	
}



void forwardx(int coordinate)
{
	int delta=0;
	while(1)
	{
		
		if(delta>=coordinate)
		break;
		if(bit_is_clear(PINB,2))
		break;
		PORTC=(1<<A1)|(0<<A1_)|(0<<B1)|(0<<B1_);
		_delay_ms(20);
		delta++;
		printf("x-axis forward delta=%d \n \r",delta);
		_delay_ms(500);
		if(bit_is_clear(PINB,2))
		break;
		if(delta>=coordinate)
		break;
		
		PORTC=(0<<A1)|(0<<A1_)|(1<<B1)|(0<<B1_);
		_delay_ms(20);
		delta++;
		printf("x-axis forward delta=%d \n\r",delta);
		_delay_ms(500);
		if(bit_is_clear(PINB,2))
		break;
		if(delta>=coordinate)
		break;
		
		PORTC=(0<<A1)|(1<<A1_)|(0<<B1)|(0<<B1_);
		_delay_ms(20);
		delta++;
		printf("x-axis forward delta=%d\n \r",delta);
		_delay_ms(500);
		if(bit_is_clear(PINB,2))
		break;
		if(delta>=coordinate)
		break;
		
		PORTC=(0<<A1)|(0<<A1_)|(0<<B1)|(1<<B1_);
		_delay_ms(20);
		delta++;
		printf("x-axis forward delta=%d\n \r",delta);
		_delay_ms(500);
		if(bit_is_clear(PINB,2))
		break;
		if(delta>=coordinate)
		break;
		
	}
}



void forwardy(int coordinate)
{
	int delta=0;
	while(1)
	{
		if(delta>=coordinate)
		break;
		if(bit_is_clear(PINB,3))
		break;
		PORTC=(1<<A2)|(0<<A2_)|(0<<B2)|(0<<B2_);
		_delay_ms(20);
		delta++;
		printf("y axis forward delta=%d \n \r",delta);
		_delay_ms(500);
		if(bit_is_clear(PINB,3))
		break;
		if(delta>=coordinate)
		break;
		
		
		PORTC=(0<<A2)|(0<<A2_)|(1<<B2)|(0<<B2_);
		_delay_ms(20);
		delta++;
		printf("y axis forward delta=%d \n\r",delta);
		_delay_ms(500);
		if(bit_is_clear(PINB,3))
		break;
		if(delta>=coordinate)
		break;
		
		
		PORTC=(0<<A2)|(1<<A2_)|(0<<B2)|(0<<B2_);
		_delay_ms(20);
		delta++;
		printf("y axis forward delta=%d\n \r",delta);
		_delay_ms(500);
		if(bit_is_clear(PINB,3))
		break;
		if(delta>=coordinate)
		break;
		
		
		PORTC=(0<<A2)|(0<<A2_)|(0<<B2)|(1<<B2_);
		_delay_ms(20);
		delta++;
		printf("y axis forward delta=%d\n \r",delta);
		_delay_ms(500);
		if(bit_is_clear(PINB,3))
		break;
		if(delta>=coordinate)
		break;
	}
}


void reverse_x(int coordinate)
{
	
	int delta=0;
	while(1)
	{
		if(delta>=coordinate)
		break;
		PORTC=(0<<A1)|(0<<A1_)|(0<<B1)|(1<<B1_);
		_delay_ms(20);
		delta++;
		printf("y axis forward delta=-%d\n \r",delta);
		_delay_ms(500);
		if(bit_is_clear(PINB,3))
		break;
		if(delta>=coordinate)
		break;
		
		
		PORTC=(0<<A1)|(1<<A1_)|(0<<B1)|(0<<B1_);
		_delay_ms(20);
		delta++;
		printf("y axis forward delta=-%d\n \r",delta);
		_delay_ms(500);
		if(bit_is_clear(PINB,3))
		break;
		if(delta>=coordinate)
		break;
		
		PORTC=(0<<A1)|(0<<A1_)|(1<<B1)|(0<<B1_);
		_delay_ms(20);
		delta++;
		printf("y axis forward delta=-%d \n\r",delta);
		_delay_ms(500);
		if(bit_is_clear(PINB,3))
		break;
		if(delta>=coordinate)
		break;
		
		if(bit_is_clear(PINB,3))
		break;
		PORTC=(1<<A1)|(0<<A1_)|(0<<B1)|(0<<B1_);
		_delay_ms(20);
		delta++;
		printf("y axis forward delta=-%d \n \r",delta);
		_delay_ms(500);
		if(bit_is_clear(PINB,3))
		break;
		if(delta>=coordinate)
		break;
	}
}


void reverse_y(int coordinate)
{
	
		int delta=0;
		while(1)
		{	
			if(delta>=coordinate)
			break;
			PORTC=(0<<A2)|(0<<A2_)|(0<<B2)|(1<<B2_);
			_delay_ms(20);
			delta++;
			printf("y axis forward delta=-%d\n \r",delta);
			_delay_ms(500);
			if(bit_is_clear(PINB,3))
			break;
			if(delta>=coordinate)
			break;
			
		
			PORTC=(0<<A2)|(1<<A2_)|(0<<B2)|(0<<B2_);
			_delay_ms(20);
			delta++;
			printf("y axis forward delta=-%d\n \r",delta);
			_delay_ms(500);
			if(bit_is_clear(PINB,3))
			break;
			if(delta>=coordinate)
			break;	
			
			PORTC=(0<<A2)|(0<<A2_)|(1<<B2)|(0<<B2_);
			_delay_ms(20);
			delta++;
			printf("y axis forward delta=-%d \n\r",delta);
			_delay_ms(500);
			if(bit_is_clear(PINB,3))
			break;
			if(delta>=coordinate)
			break;	
			
			if(bit_is_clear(PINB,3))
			break;
			PORTC=(1<<A2)|(0<<A2_)|(0<<B2)|(0<<B2_);
			_delay_ms(20);
			delta++;
			printf("y axis forward delta=-%d \n \r",delta);
			_delay_ms(500);
			if(bit_is_clear(PINB,3))
			break;
			if(delta>=coordinate)
			break;	
		}
		PORTC=0x00;
}

void delaymili(int d)
{
	for(int i=0;i<d;i++)
	{
		_delay_ms(500);
	}
	
}

void drill_z(int coordinate,int delaysec)
{
	
	int delta=0;
	
	while(1)
	{
		PORTD=(1<<PIND6);
		
			
		if(delta>20)
		delaysec=25;
		
		if(delta>=coordinate)
		break;
		
		PORTA=(1<<A3)|(0<<A3_)|(0<<B3)|(0<<B3_);
		delaymili(delaysec);
		printf("\n\rZ-axis down delta=%d",delta);
		delta++;
		if(delta>=coordinate)
		break;
		
		PORTA=(0<<A3)|(0<<A3_)|(1<<B3)|(0<<B3_);
		delaymili(delaysec);
		printf("\n\rZ-axis down delta=%d",delta);
		delta++;
		if(delta>=coordinate)
		break;
		
		PORTA=(0<<A3)|(1<<A3_)|(0<<B3)|(0<<B3_);
		delaymili(delaysec);
		printf("\n\rZ-axis down delta=%d",delta);
		delta++;
		if(delta>=coordinate)
		break;
		
		PORTA=(0<<A3)|(0<<A3_)|(0<<B3)|(1<<B3_);
		delaymili(delaysec);
		printf("\n\rZ-axis down delta=%d",delta);
		delta++;
		if(delta>=coordinate)
		break;
		
		
	}
	PORTD=(1<<PIND7);
	PORTC=0x00;
	
}


