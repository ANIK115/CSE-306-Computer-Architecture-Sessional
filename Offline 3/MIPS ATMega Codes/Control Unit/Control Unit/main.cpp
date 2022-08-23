/*
 * GccApplication2.cpp
 *
 * Created: 8/16/2022 1:36:49 PM
 * Author : HP
 */ 

#include <avr/io.h>



int main(void)
{
	DDRB = 0b00000000; //PB0-PB3
	DDRC = 0b11111111; //PC0-PC3
	DDRA = 0b11111111; // full
	
	unsigned char opcode;
    /* Replace with your application code */
	
	
	MCUCSR = (1<<JTD);
	MCUCSR = (1<<JTD);
	
	
	while(1)
	{
		opcode = PINB;
		if(opcode == 0)
		{
			PORTA = 0x80;
			PORTC = 0x01;
		}
		else if(opcode == 1)
		{
			PORTA = 0xD8;
			PORTC = 0x00;
		}
		else if(opcode == 2)
		{
			PORTA = 0xCC;
			PORTC = 0x00;
		}
		else if(opcode == 3)
		{
			PORTA = 0xD4;
			PORTC = 0x00;
		}
		else if(opcode == 4)
		{
			PORTA = 0x90;
			PORTC = 0x01;
		}
		else if(opcode == 5)
		{
			PORTA = 0x00;
			PORTC = 0x02;
		}
		else if(opcode == 6)
		{
			PORTA = 0xC3;
			PORTC = 0x00;
		}
		else if(opcode == 7)
		{
			PORTA = 0x04;
			PORTC = 0x04;
		}
		else if(opcode == 8)
		{
			PORTA = 0x84;
			PORTC = 0x01;
		}
		else if(opcode == 9)
		{
			PORTA = 0xC4;
			PORTC = 0x00;
		}
		else if(opcode == 10)
		{
			PORTA = 0x88;
			PORTC = 0x01;
		}
		else if(opcode == 11)
		{
			PORTA = 0xC8;
			PORTC = 0x00;
		}
		else if(opcode == 12)
		{
			PORTA = 0x8C;
			PORTC = 0x01;
		}
		else if(opcode == 13)
		{
			PORTA = 0x60;
			PORTC = 0x00;
		}
		else if(opcode == 14)
		{
			PORTA = 0xC0;
			PORTC = 0x00;
		}
		else if(opcode == 15)
		{
			PORTA = 0x04;
			PORTC = 0x08;
		}
		
	}
    
}

