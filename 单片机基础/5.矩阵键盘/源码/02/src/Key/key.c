#include <REGX51.H>
#include "key.h"
#include "delay.h"


//ÖðÐÐÉ¨Ãè
unsigned int key_init()
{

	int key = 0;
		
		P1 = 0x7F;

	
		if(P1 != 0x7F)
		{
			Delay(20);
			
			switch(P1)
			{
				case 0x77:while(P1 == 0x77); Delay(20);key = 1;break;
				case 0x7B:while(P1 == 0x7B); Delay(20);key = 2;break;
				case 0x7D:while(P1 == 0x7D); Delay(20);key = 3;break;
				case 0x7E:while(P1 == 0x7E); Delay(20);key = 4;break;
			}
		}

		
		
		P1 = 0xBF;
		if(P1 != 0xBF)
		{
			switch(P1)
			{
				case 0xB7:while(P1 == 0xB7); Delay(20);key = 5;break;
				case 0xBB:while(P1 == 0xBB); Delay(20);key = 6;break;
				case 0xBD:while(P1 == 0xBD); Delay(20);key = 7;break;
				case 0xBE:while(P1 == 0xBE); Delay(20);key = 8;break;
			}
		}

		P1 = 0xDF;
		if(P1 != 0xDF)
		{
			switch(P1)
			{
				case 0xD7:while(P1 == 0xD7); Delay(20);key = 9;break;
				case 0xDB:while(P1 == 0xDB); Delay(20);key = 10;break;
				case 0xDD:while(P1 == 0xDD); Delay(20);key = 11;break;
				case 0xDE:while(P1 == 0xDE); Delay(20);key = 12;break;
			}
		}
		
		P1 = 0xEF;
		if(P1 != 0xEF)
		{
			switch(P1)
			{
				case 0xE7:while(P1 == 0xE7); Delay(20);key = 13;break;
				case 0xEB:while(P1 == 0xEB); Delay(20);key = 14;break;
				case 0xED:while(P1 == 0xED); Delay(20);key = 15;break;
				case 0xEE:while(P1 == 0xEE); Delay(20);key = 16;break;
			}
		}
		
				return key;
		
}
