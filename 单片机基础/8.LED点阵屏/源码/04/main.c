#include <REGX52.H>
#include "INTRINS.h"
#include "LCD1602.h"
#include "uart.h"
#include "delay.h"
#include "LED8_8.h"



unsigned char Data[40] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xFF,0x08,0x08,0x08,0xFF,0x00,0xFF,0x89,0x89,0x89,0x00,0xFF,0x01,0x01,0x01,0x00,
0xFF,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};


void hello(unsigned int offset)
{
	unsigned int i = 0;
	for(i;i < 8;i++)
	{
		LED8_8_show(i,Data[i + offset]);
	}
}


void _2()
{
	LED8_8_show(0,0x9F);
	LED8_8_show(1,0x91);
	LED8_8_show(2,0x91);
	LED8_8_show(3,0x91);
	LED8_8_show(4,0x91);
	LED8_8_show(5,0x91);
	LED8_8_show(6,0x91);
	LED8_8_show(7,0xF1);
}



void _1()
{
	LED8_8_show(0,0x00);
	LED8_8_show(1,0x00);
	LED8_8_show(2,0x00);
	LED8_8_show(3,0x00);
	LED8_8_show(4,0x00);
	LED8_8_show(5,0x00);
	LED8_8_show(6,0x00);
	LED8_8_show(7,0xFF);
}



void main()
{
	unsigned int offset = 0;
	_74HC595_init();
	while(1)
	{
		hello(offset);
		offset++;
		Delay(75);
		if(offset > 40)
			offset = 0;
	}
}







