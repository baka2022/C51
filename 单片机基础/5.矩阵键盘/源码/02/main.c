#include <REGX51.H>
#include <intrins.h>
#include "delay.h"
#include "seg.h"
#include "LCD1602.h"
#include "key.h"



int num = 0;
void main()
{
	LCD_Init();
	while(1)
	{
			
		int key ;
		key =  key_init();
		if(key == 2)
		{
			num = key;
		}
		
		 LCD_ShowNum(1,1,num,2);
	}
}


