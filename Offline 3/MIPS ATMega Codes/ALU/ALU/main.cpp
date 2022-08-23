/*
 * GccApplication1.cpp
 *
 * Created: 8/16/2022 11:49:46 AM
 * Author : HP
 */ 

#include <avr/io.h>



int main(void)
{
    /* Replace with your application code */
	DDRA = 0b00000000;	//input 1
	DDRB = 0b00000000;	//input 2
	DDRC = 0b00000000;	//op code
	DDRD = 0b11111111;	//output
	char a, b, aluOp, out;
	MCUCSR = (1<<JTD);
	MCUCSR = (1<<JTD);
	
	
    while (1) 
    {
		a = PINA;
		b = PINB;
		aluOp = PINC;
		
		//a &= 00001111;
		//sb &= 00001111;
		//aluOp &= 00000111;
		
		//PORTD = b;
		if(aluOp == 0)
		{
			PORTD = a+b;
		}
		else if(aluOp == 1)
		{
			char res = a-b;
			if(a-b == 0)
			{
				res = res | 0b00010000;
			}
			PORTD = res;
		}
		else if(aluOp == 2)
		{
			PORTD = a & b;
		}
		else if(aluOp == 3)
		{
			PORTD = a | b;
		}
		else if(aluOp == 4)
		{
			PORTD = ~(a | b);
		}
		else if(aluOp == 5)
		{
			PORTD = a << b;
		}
		else if(aluOp == 6)
		{
			if(a & (0b00001000))
			{
				for(int i=0; i< (int)b; i++)
				{
					a = (a >> 1) | 8;
				}
				PORTD = a;
			}else
			{
				PORTD = a >> b;
			}
		}
		else if(aluOp == 7)
		{
			
		}
			
    }
}

