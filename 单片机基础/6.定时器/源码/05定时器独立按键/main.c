#include <REGX52.H>
#include "timer.h"
#include "key.h"
#include "INTRINS.h"



unsigned int keynum;
unsigned int LEDMODE = 0;
void main()
{
	Timer0_Init();
	P2 = 0x01;
	
	while(1)
	{
		keynum = key();
		if(keynum)
		{
			if(keynum == 1)
			{
				LEDMODE = 1;
			}
			if(keynum == 2)
			{
				LEDMODE = 2;
			}
			if(keynum == 3)
			{
				
			}
			if(keynum == 4)
			{
				
			}
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
			if(LEDMODE == 1)
			{
				P2 = _cror_(P2,1);
			}
			
			if(LEDMODE == 2)
			{
				P2 = _crol_(P2,1);
			}
			
		}
}


