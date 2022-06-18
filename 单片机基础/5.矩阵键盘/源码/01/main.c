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
		int key = 0;
		
		
		P1 = 0x7F;
		if(P1 != 0x7F)
		{
			switch(P1)
			{
				case 0x77:key = 1;break;
				case 0x7B:key = 2;break;
				case 0x7D:key = 3;break;
				case 0x7E:key = 4;break;
			}
		}

		
		
		P1 = 0xBF;
		if(P1 != 0xBF)
		{
			switch(P1)
			{
				case 0xB7:key = 5;break;
				case 0xBB:key = 6;break;
				case 0xBD:key = 7;break;
				case 0xBE:key = 8;break;
			}
		}

		P1 = 0xDF;
		if(P1 != 0xDF)
		{
			switch(P1)
			{
				case 0xD7:key = 9;break;
				case 0xDB:key = 10;break;
				case 0xDD:key = 11;break;
				case 0xDE:key = 12;break;
			}
		}
		
		P1 = 0xEF;
		if(P1 != 0xEF)
		{
			switch(P1)
			{
				case 0xE7:key = 13;break;
				case 0xEB:key = 14;break;
				case 0xED:key = 15;break;
				case 0xEE:key = 16;break;
			}
		}

		
		
		
		
		
		
		
		
		
		
		
		
		

			 LCD_ShowNum(1,1,key,2);
	}
}


