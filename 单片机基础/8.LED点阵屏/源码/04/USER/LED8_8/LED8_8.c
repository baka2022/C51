#include "LED8_8.h"
#include <REGX52.H>
#include "delay.h"

sbit SH = P2^0;		//输入时钟
sbit DS = P2^1;		//输入数据
sbit ST = P2^2;		//输出锁存


/**
	*	@brief	使用75HC595写入数据
	*	@param
	*	@retval
*/

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



/**
	*	@brief	LED8*8矩阵显示
	*	@param
	*	@retval
*/

void LED8_8_show(unsigned char col,Data)
{
	P1 = ~Data;
	_74HC595_writeByte(0x80>>col);
	Delay(1);
	_74HC595_writeByte(0x00);
}



/**
	*	@brief	74HC595初始化
	*	@param
	*	@retval
*/

void _74HC595_init()
{
	SH = 0;
	ST = 0;
	P1 = 0;
}