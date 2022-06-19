#include <REGX52.H>
#include "INTRINS.h"
#include "LCD1602.h"
#include "delay.h"
#include "uart.h"
#include "key.h"
#include "timer.h"
#include "buzzer.h"





unsigned int keynum;

void main()
{
	uart_init();
	Timer0_Init();
	while(1)
	{
			keynum = key();
			if(keynum == 1)
			{
				uart_sendbyte(0x01);
				sounder_time(1000);
			}
			if(keynum == 2)
			{
				uart_sendbyte(0x02);
				sounder_time(500);
			}
			if(keynum == 3)
			{
				uart_sendbyte(0x03);

			}
			if(keynum == 4)
			{
				uart_sendbyte(0x04);

			}

	}
}


void Time0_Routine()interrupt 1
{
		static unsigned int count = 0;
//	赋初值否则只有一次是1微秒，其他为65微秒
		TL0 = 0x18;
		TH0 = 0xFC;
		count++;
		if(count == 1000)
		{
			
			count = 0;
		}
}




