#include "uart.h"
#include <REGX52.H>



/**
	*	@brief	���ڳ�ʼ��
	*	@param	��
	*	@retval	��
*/


void uart_init()
{
	SCON = 0x50;
	PCON = PCON & 0x80;
	TMOD = TMOD & 0x0F;
	TMOD = TMOD | 0x20;
	TF1 = 0;
	TR1 = 1;
//	������9600��ʱ��11.05926MHz
	TL1 = 0xFD;
	TH1 = 0xFD;
	ET1 = 0;
	ES = 1;
	EA = 1;
}


/**
	*	@brief	�򴮿ڷ���һ���ֽ�����
	*	@param	byte�����͵�����
	*	@retval	��
*/


void uart_sendbyte(unsigned char byte)
{
	SBUF = byte;
	while(TI == 0);
	TI = 0;
}


/**
	*	@brief	�����жϺ���ģ��
	*	@param	��
	*	@retval	��
*/


//void uart_routine(void) interrupt 4
//{
//	if(RI == 1)
//	{
//		
////		�����־λ
//		RI = 0;
//	}
//}

