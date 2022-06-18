#include <REGX52.H>
#include "timer.h"
#include "key.h"




unsigned int keynum;
void main()
{
	Timer0_Init();
	
	while(1)
	{
		keynum = key();
		if(keynum)
		{
			if(keynum == 1)
			{
				P2_0 = ~P2_0;
			}
			if(keynum == 2)
			{
				P2_1 = ~P2_1;
			}
			if(keynum == 3)
			{
				P2_2 = ~P2_2;
			}
			if(keynum == 4)
			{
				P2_3 = ~P2_3;
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
		}
}


