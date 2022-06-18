#include "timer.h"
#include <REGX52.H>

/**
	*	@brief	定时器初始化
						初始化后每1微秒触发一次中断
	*	@param	无
	*	@retval	无
*/


void Timer0_Init()
{
//	清0
	TMOD = TMOD & 0xF0;
//	置1
	TMOD = TMOD | 0x01;
//	标志位清0
	TF0 = 0;
//	开始计数
	TR0 = 1;
//	计数初值，这里初值是65535-1000，计数1000次是1微秒
	TL0 = 0x18;
	TH0 = 0xFC;
//	定时器中断配置
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}


/**
	*	@brief	定时器中断
	*	@param	无
	*	@retval	无
*/


//void Time0_Routine()interrupt 1
//{
//		static unsigned int count = 0;
////	赋初值否则只有一次是1微秒，其他为65微秒
//		TL0 = 0x18;
//		TH0 = 0xFC;
//		count++;
//		if(count == 1000)
//		{
//			P2_0 = ~P2_0;
//			count = 0;
//		}
//}
