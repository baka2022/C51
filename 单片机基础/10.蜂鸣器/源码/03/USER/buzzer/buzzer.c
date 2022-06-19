#include "buzzer.h"
#include "Delay.h"
#include <REGX52.H>
#include "INTRINS.h"

sbit SOUNDER = P2^1;

void sounder_Delay500us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 227;
	while (--i);
}


void sounder_time(unsigned int ms)
{
	unsigned int i;
	for(i = 0;i < ms;i++)
	{
		SOUNDER = ~SOUNDER;
		Delay(1);
	}
}

