#include <REGX52.H>
#include "timer.h"
#include "key.h"
#include "INTRINS.h"
#include "LCD1602.h"


unsigned int keynum;
unsigned int LEDMODE = 0;
static unsigned int miao = 57;
static unsigned int fen = 59;
static unsigned int shi = 23;

void main()
{
	Timer0_Init();
	P2 = 0x01;
	LCD_Init();
	
	while(1)
	{
		if(miao == 60)
			{
				miao = 0;
				fen++;
				if(fen == 60)
				{
					fen = 0;
					shi++;
					if(shi == 24)
					{
						shi = 0;
					}
				}
			}
		LCD_ShowNum(1,1,shi,2);
		LCD_ShowString(1,3,":");
		LCD_ShowNum(1,4,fen,2);
		LCD_ShowString(1,6,":");
		LCD_ShowNum(1,7,miao,2);
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
			miao++;
						
		}
}


