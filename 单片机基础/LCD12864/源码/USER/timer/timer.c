#include "timer.h"
#include <REGX52.H>

/**
	*	@brief	��ʱ����ʼ��
						��ʼ����ÿ1΢�봥��һ���ж�
	*	@param	��
	*	@retval	��
*/


void Timer0_Init()
{
//	��0
	TMOD = TMOD & 0xF0;
//	��1
	TMOD = TMOD | 0x01;
//	��־λ��0
	TF0 = 0;
//	��ʼ����
	TR0 = 1;
//	������ֵ�������ֵ��65535-1000������1000����1΢��
	TL0 = 0x18;
	TH0 = 0xFC;
//	��ʱ���ж�����
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}


/**
	*	@brief	��ʱ���ж�
	*	@param	��
	*	@retval	��
*/


//void Time0_Routine()interrupt 1
//{
//		static unsigned int count = 0;
////	����ֵ����ֻ��һ����1΢�룬����Ϊ65΢��
//		TL0 = 0x18;
//		TH0 = 0xFC;
//		count++;
//		if(count == 1000)
//		{
//			P2_0 = ~P2_0;
//			count = 0;
//		}
//}
