//DS1302是由美国DALLAS公司推出的具有涓细电流充电能力的低功耗实时时钟芯片。
//它可以对年、月、日、周、时、分、秒进行计时，且具有闰年补偿等多种功能。



#include <REGX52.H>
#include "INTRINS.h"
#include "LCD1602.h"
#include "delay.h"


sbit DS1302_CE = P3^5;
sbit DS1302_SCLK = P3^6;
sbit DS1302_IO = P3^7;

void DS1302_init(void)
{
	DS1302_CE = 0;
	DS1302_SCLK = 0;
}

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
	return Data;
}

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

void main()
{
	LCD_Init();
	DS1302_init();
	while(1)
	{
		unsigned char miao;
//		DS1302_writebyte(0x80,0x10);
		miao = DS1302_readbyte(0x81);
		LCD_ShowNum(1,1,miao,2);
	}
}







