#include <REGX52.H>
#include "INTRINS.h"
#include "LCD1602.h"
#include "uart.h"
#include <delay.h>


unsigned int num;


void main()
{
	P2 = 0x00;
	uart_init();
	while(1)
	{
		Delay(1000);
	}
}


void uart_routine(void) interrupt 4
{
	if(RI == 1)
	{
		P2 = SBUF;
		num = SBUF;
		uart_sendbyte(num);
		RI = 0;
	}
}





