/*
 * Data_Memory.cpp
 *
 * Created: 8/17/2022 6:47:26 PM
 * Author : HP
 */ 

#include <avr/io.h>
#define F_CPU 1000000 // Clock Frequency
#include <util/delay.h>




int main(void)
{
	DDRB = 0b00000000;//address
	DDRD = 0b00000000; //write_data
	
	DDRA = 0b11111111; //read_data
	DDRC = 0b11111000; //PC0 for memory read,PC1 for memory write,PC2 for clk pulse
	
	unsigned char memory[16],clk = 0, memory_read=0, memory_write=0, mem_address, write_data;

	MCUCSR = (1<<JTD);
	MCUCSR = (1<<JTD);

	
    /* Replace with your application code */
    while (1) 
    {
		memory_read = PINC;
		memory_write = PINC;
		clk = PINC;
		
		mem_address = PINB;
		write_data = PIND;
		
		
		
		
		if(memory_read & 0b00000001)
		{
			PORTA = memory[(int)mem_address];
		}
		
		if((memory_write & 0b00000010) && (clk &  0b00000100))
		{
			memory[(int)mem_address] = write_data;
			_delay_ms(500);
			clk = 0;
			
		}
    }
}

