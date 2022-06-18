#include <REGX52.H>
#include "INTRINS.h"
#include "LCD1602.h"
#include "delay.h"


void main()
{
	LCD_Init();
	while(1)
	{
		LCD_ShowChar(1,1,'a');
	}
}







