#include "DS1302.h"
#include <REGX52.H>


sbit DS1302_CE = P3^5;
sbit DS1302_SCLK = P3^6;
sbit DS1302_IO = P3^7;


/**
	*	@brief	DS1302初始化函数
	*	@param	无
	*	@retval	无
*/

void DS1302_init(void)
{
	DS1302_CE = 0;
	DS1302_SCLK = 0;
}



/**
	*	@brief	DS1302读数据
	*	@param	
	*	@retval
*/


unsigned char DS1302_readbyte(unsigned char command)
{
	unsigned char Data = 0x00,i;
	DS1302_CE = 1;
	for(i = 0;i < 8;i++)
	{
		DS1302_IO = command & (0x01 << i);
		DS1302_SCLK = 0;
		DS1302_SCLK = 1;
	}
	
	for(i = 0;i < 8;i++)
	{
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
		if(DS1302_IO)
		{
			Data = Data | (0x01 << i);
		}
	}
	
	DS1302_CE = 0;
	DS1302_IO = 0;
	return Data;
}




/**
	*	@brief	DS1302写数据
	*	@param
	*	@retval
*/



void DS1302_writebyte(unsigned char command,Data)
{	
	unsigned char i;
	DS1302_CE = 1;
	for(i = 0;i < 8;i++)
	{
		DS1302_IO = command & (0x01 << i);
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
	}
	for(i = 0;i < 8;i++)
	{
		DS1302_IO = Data & (0x01 << i);
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
	}
	DS1302_CE = 0;
}
