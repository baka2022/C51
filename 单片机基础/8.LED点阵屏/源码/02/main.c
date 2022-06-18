#include <REGX52.H>
#include "INTRINS.h"
#include "LCD1602.h"
#include "uart.h"
#include <delay.h>

sbit SH = P2^0;		//输入时钟
sbit DS = P2^1;		//输入数据
sbit ST = P2^2;		//输出锁存

void _74HC595_writeByte(unsigned char byte)
{
	unsigned int i = 0;
	for(i;i < 8;i++)
	{
		DS = byte&(0x80 >> i);
		SH = 1;
		SH = 0;
	}
	ST = 1;
	ST = 0;
}

void LED8_8_show(unsigned char col,Data)
{
		P1 = Data;
	_74HC595_writeByte(0x80>>col);
}

void main()
{
	SH = 0;
	ST = 0;
	P1 = 0;
	while(1)
	{
		unsigned int i = 0;
		for(i;i < 8;i++)
		{
			LED8_8_show(i,0xF0);
			Delay(500);
		}
	}
}







