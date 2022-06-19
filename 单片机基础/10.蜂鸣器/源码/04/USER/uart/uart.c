#include "uart.h"
#include <REGX52.H>



/**
	*	@brief	串口初始化
	*	@param	无
	*	@retval	无
*/


void uart_init()
{
	SCON = 0x50;
	PCON = PCON & 0x80;
	TMOD = TMOD & 0x0F;
	TMOD = TMOD | 0x20;
	TF1 = 0;
	TR1 = 1;
//	波特率9600、时钟11.05926MHz
	TL1 = 0xFD;
	TH1 = 0xFD;
	ET1 = 0;
	ES = 1;
	EA = 1;
}


/**
	*	@brief	向串口发送一个字节数据
	*	@param	byte：发送的数据
	*	@retval	无
*/


void uart_sendbyte(unsigned char byte)
{
	SBUF = byte;
	while(TI == 0);
	TI = 0;
}


/**
	*	@brief	串口中断函数模板
	*	@param	无
	*	@retval	无
*/


//void uart_routine(void) interrupt 4
//{
//	if(RI == 1)
//	{
//		
////		清除标志位
//		RI = 0;
//	}
//}

