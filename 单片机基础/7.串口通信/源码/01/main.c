#include <REGX52.H>
#include "INTRINS.h"
#include "LCD1602.h"
#include "uart.h"
#include <delay.h>

unsigned int num = 0;

void main()
{
	uart_init();
	while(1)
	{
		uart_sendbyte(23);
		num++;
		Delay(1000);

	}
}




