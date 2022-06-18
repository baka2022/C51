#include <REGX51.H>
#include <intrins.h>
#include "delay.h"
#include "seg.h"
#include "LCD1602.h"

void main()
{
	LCD_Init();
	while(1)
	{
		 LCD_ShowString(1,1,"hello");
	}
}


