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



void Delay1ms(unsigned int xms)		//@12.000MHz
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
	int i = 0;
	int LEDnum = 0xF01;
	P2 = LEDnum;
	while(1)
	{
		if(key1 == 0)
		{
			Delay1ms(20);
			while(key1 == 0);
			Delay1ms(20);
			i++;
			if(i > 7)
			{
				i = 0;
			}
			P2 = LEDnum << i;
		}	

	}
}


