#include <REGX51.H>
#include <intrins.h>

sbit LED0 = P2^0;
sbit LED1 = P2^1;
sbit LED2 = P2^2;
sbit LED3 = P2^3;
sbit LED4 = P2^4;
sbit LED5 = P2^5;
sbit LED6 = P2^6;
sbit LED7 = P2^7;


sbit key1 = P3^0;


const unsigned int LED[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
const unsigned int REG[16] = {0xc0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x77,0x7c,0x39,0x5E,0x79,0x71};



void Delay(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;

	while(xms--)
	{
				i = 2;
				j = 239;
				do
				{
					while (--j);
				} while (--i);
	}
}




void main()
{

	while(1)
	{
		int i = 0;
		P2 = 0x80;
		for(i;i<=9;i++)
		{
			P0 = REG[i];
			Delay(500);
		}

	}
}


