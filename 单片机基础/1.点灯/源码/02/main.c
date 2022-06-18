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


void Delay500ms();		//@12.000MHz
void flashing();
void RunningWaterLight();

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

	P2 = 0x00;
	while(1)
	{
		 P2 = 0x01;
		Delay1ms(500);	
		P2 = 0x02;
		Delay1ms(500);	
	}
}


void RunningWaterLight()
{
	P2 = 0x01;
	Delay500ms();	
	P2 = 0x02;
	Delay500ms();	
	P2 = 0x04;
	Delay500ms();	
	P2 = 0x08;
	Delay500ms();	
	P2 = 0x10;
	Delay500ms();	
	P2 = 0x20;
	Delay500ms();	
	P2 = 0x40;
	Delay500ms();	
	P2 = 0x80;
	Delay500ms();	
}


void flashing()
{
		P2 = 0x01;
		Delay500ms();	
		P2 = 0x00;
		Delay500ms();	
}


void Delay500ms()		//@12.000MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 4;
	j = 205;
	k = 187;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
