#include <REGX52.H>
#include "INTRINS.h"
#include "LCD1602.h"
#include "delay.h"

sbit BUZZER = P2^0;
sbit SOUNDER = P2^1;

void main()
{
	SOUNDER = 0;
	while(1)
	{
//		SOUNDER = 1;
//		Delay(1);
//		SOUNDER = 0;
//		Delay(1);
	}
}







