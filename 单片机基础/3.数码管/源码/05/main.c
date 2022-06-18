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
//共阳极段选
const unsigned int REG1[16] = {0xc0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E};
//共阴极段选
const unsigned int REG2[16] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
//位选
const unsigned int REG3[8] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07};

//延时函数
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

/*
*无返回值
*x表示位选，y表示段选
*/
void display(int x,int y)
{
	P2 = REG3[x];
	P0 = REG2[y];
}


void main()
{

	while(1)
	{
		int i = 0;
		for(i;i<=7;i++)
		{
			display(i,i);
			Delay(1);
		}
	}
}


