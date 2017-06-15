

void serial_write(unsigned char data)
{
	while ((UCSRA & (1 << UDRE)) == 0) {}; // Do nothing until UDR is ready for more data to be written to it
	UDR=data; // Echo back the received byte back to the computer
	
}





unsigned char serial_read()
{
	while ((UCSRA & (1 << RXC)) == 0) {}; // Do nothing until data have been received and is ready to be read from UDR
	return UDR; // Fetch the received byte value into the variable "variable"
	
}

