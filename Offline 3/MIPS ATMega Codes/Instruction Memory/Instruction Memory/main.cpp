/*
 * GccApplication1.cpp
 *
 * Created: 8/17/2022 5:19:49 PM
 * Author : HP
 */ 

#include <avr/io.h>
#define F_CPU 1000000 // Clock Frequency
#include <util/delay.h>




int main(void)
{
	DDRB = 0b00000000;
	DDRD = 0b00000000;
	DDRA = 0b11111111;
	DDRC = 0b11111111;
	
	unsigned char memory[256][2];
	unsigned char PC_Address = 0, branch_address, jump_address; //PD0 for clk
	unsigned char jump_selection=0,branch_selection=0, bneq_selection=0; //PD1 for jump_selection
	unsigned char prev_clk=1,curr_clk=0,zero_flag=0; //PD1 for jump_selection , PD2 for branching,PD3 for zero_flag

	MCUCSR = (1<<JTD);
	MCUCSR = (1<<JTD);

	
	memory[0][0]=0xe7;
	memory[0][1]=0x13;
	
	memory[1][0]=0x97;
	memory[1][1]=0x2e;
	
	memory[2][0]=0x01;
	memory[2][1]=0x20;
	
	memory[3][0]=0x81;
	memory[3][1]=0x23;
	
	memory[4][0]=0x40;
	memory[4][1]=0x14;
	
	memory[5][0]=0xd2;
	memory[5][1]=0x13;
	
	memory[6][0]=0x12;
	memory[6][1]=0x21;
	
	memory[7][0]=0x72;
	memory[7][1]=0x31;
	
	memory[8][0]=0x51;
	memory[8][1]=0x80;
	
	memory[9][0]=0x33;
	memory[9][1]=0x31;
	
	memory[10][0]=0x62;
	memory[10][1]=0x24;
	
	
	memory[11][0]=0x07;
	memory[11][1]=0x77;
	
	memory[12][0]=0x07;
	memory[12][1]=0x77;
	
	memory[13][0]=0x51;
	memory[13][1]=0x50;
	
	memory[14][0]=0xc0;
	memory[14][1]=0x20;
	
	memory[15][0]=0xb4;
	memory[15][1]=0x21;
	
	memory[16][0]=0x21;
	memory[16][1]=0x15;
	
	memory[17][0]=0x07;
	memory[17][1]=0x77;
	
	memory[18][0]=0xa2;
	memory[18][1]=0x41;
	
	memory[19][0]=0x07;
	memory[19][1]=0x77;
	
	memory[20][0]=0x51;
	memory[20][1]=0x60;
	
	memory[21][0]=0xf0;
	memory[21][1]=0x28;
	
	
	
    /* Replace with your application code */
	//PC_Address = PINB;
	
    while (1) 
    {
		
		curr_clk = PIND;
		jump_selection=PIND;
		branch_selection = PIND;
		bneq_selection = PIND;
		zero_flag = PIND;
		
		 
		
		if(curr_clk & 0b00000001 )
		{
		   
		  PORTA  = memory[PC_Address][0];
		  PORTC  = memory[PC_Address][1];
		   
		   curr_clk=0;
		   
		   PC_Address++;
		   
		   if(jump_selection & 0b00000010)
		   {
			   jump_address = ((memory[PC_Address-1][0] & 0b00001111) << 4) | ((memory[PC_Address-1][1] & 0b11110000) >>4);
			   PC_Address = jump_address;
		   }else if((branch_selection & 0b00000100) && (zero_flag & 0b00010000))
		   {
			   char a = memory[PC_Address-1][1] & 0b00001111;
			   
			   int sign_bit = a & 0b00001000;
			   if(sign_bit)
			   {
				   a = 0b11110000 | a;
			   }
			   PC_Address += a;
		   }else if((bneq_selection & 0b00001000) && !(zero_flag & 0b00010000))
		   {
			   char a = memory[PC_Address-1][1] & 0b00001111;
			   int sign_bit = a & 0b00001000;
			   if(sign_bit)
			   {
				   a = 0b11110000 | a;
			   }
			   PC_Address += a;
		   }
		   
		   _delay_ms(5000);
		   
		}
		
		
		
    }
}

