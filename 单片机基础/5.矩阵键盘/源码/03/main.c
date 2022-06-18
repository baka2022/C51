#include <REGX51.H>
#include <intrins.h>
#include "delay.h"
#include "seg.h"
#include "LCD1602.h"
#include "key.h"

int num = 0;
int n = 0;
int pwd;
void main()
{
	LCD_Init();
	LCD_ShowNum(1,1,0000,4);
	while(1)
	{
			
		unsigned int key;

		key =  key_init();
		if(key)
		{
			n++;
			if(key <= 10)
			{
				num = key - 1;
				if(n == 1)
				{
					pwd = num * 1000;
				}
				if(n == 2)
				{
					pwd = pwd + num * 100;
				}
				if(n == 3)
				{
					pwd = pwd + num * 10;
				}
				if(n == 4)
				{
					pwd = pwd + num * 1;
				}
			}
			
			
			
			if(key == 11)
			{
				if(pwd ==1235)
				{
					LCD_ShowString(2,1,"ok");
				}
				else
				{
					LCD_ShowString(2,1,"err");
				}
			
			}
			
			
			if(key == 12)
			{
				pwd = 0;
				n = 0;
				LCD_ShowString(2,1,"    ");
			}
			LCD_ShowNum(1,1,pwd,4);
			
		}
		
	}
}


