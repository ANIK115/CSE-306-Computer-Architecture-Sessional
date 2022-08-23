/*
 * RegisterFile.cpp
 *
 * Created: 8/17/2022 1:41:24 PM
 * Author : HP
 */ 

#include <avr/io.h>
#define F_CPU 1000000 // Clock Frequency
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	DDRB = 0b00000000;	//read reg 1, read reg 2
	DDRD = 0b00000000;	//write address, write data	
	DDRA = 0b11111111; //read data 1, read data 2
	DDRC = 0b00000000; //lsb 3 bits for write reg, clock, reset
	unsigned char a,b,c,d, readAddress1, readAddress2, readData1, readData2, writeData, writeAddress, clk, reset, writeReg;
	unsigned char registers[8];
	//index 0--4 => t0 to t4, last reg indicates zero
	#define t0 0
	#define t1 1
	#define t2 2
	#define t3 3
	#define t4 4
	#define zero 7
	
	MCUCSR = (1<<JTD);
	MCUCSR = (1<<JTD);

	
	for(int i=0; i<8; i++)
	{
		registers[i] = 0;
	}
    while (1) 
    {
		a = PINB;	//read data 1 address, read data 2 address
		d = PIND;	//write data address, write data
		readAddress1 = a & 0b00001111;
		readAddress2 = a & 0b11110000;
		readAddress2 = readAddress2 >> 4;
		writeAddress = d & 0b00001111;
		readData1 = registers[(int) readAddress1];
		readData2 = registers[(int) readAddress2];
		PORTA = readData1 | (readData2 << 4);
		writeData = (d & 0b11110000) >> 4;
		
		c = PINC;
		clk = c & 0b00000001;
		writeReg = c & 0b00000010;
		reset = c & 0b00000100;
		if(clk && writeReg)
		{
			registers[(int)writeAddress] = writeData;
			_delay_ms(500);
			clk = 0;
		}
		if(reset && clk)
		{
			for(int i=0; i<8; i++)
			{
				registers[i] = 0;
			}
			reset = 0;
			clk = 0;
		}
    }
}

