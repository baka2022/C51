#include <REGX52.H>
#include "INTRINS.h"
#include "LCD1602.h"
#include "uart.h"
#include "delay.h"
#include "LED8_8.h"



void main()
{
	_74HC595_init();
	while(1)
	{
		LED8_8_show(0,0x9F);
		LED8_8_show(1,0x91);
		LED8_8_show(2,0x91);
		LED8_8_show(3,0x91);
		LED8_8_show(4,0x91);
		LED8_8_show(5,0x91);
		LED8_8_show(6,0x91);
		LED8_8_show(7,0xF1);

	}
}







