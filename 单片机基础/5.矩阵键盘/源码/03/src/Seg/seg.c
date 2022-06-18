#include <REGX51.H>
#include "seg.h"
#include "delay.h"



sbit LED0 = P2^0;
sbit LED1 = P2^1;
sbit LED2 = P2^2;



sbit key1 = P3^0;


//const unsigned int LED[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
//��������ѡ
const unsigned int REG1[16] = {0xc0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E};
//��������ѡ
const unsigned int REG2[16] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
//λѡ
const unsigned int REG3[8] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07};





/**
	*	@brief	�������ʾ����
	*	@param	x���������ʾ��λ�ã�0��7��
						y:�������ʾ������
	*	@retval ��
*/

void display(int x,int y)
{
	switch(x)
	{
		case 0 :  LED0 = 0;LED1 = 0;LED2 = 0;break;
		case 1 :  LED0 = 1;LED1 = 0;LED2 = 0;break;
		case 2 :  LED0 = 0;LED1 = 1;LED2 = 0;break;
		case 3 :  LED0 = 1;LED1 = 1;LED2 = 0;break;
		case 4 :  LED0 = 0;LED1 = 0;LED2 = 1;break;
		case 5 :  LED0 = 1;LED1 = 0;LED2 = 1;break;
		case 6 :  LED0 = 0;LED1 = 1;LED2 = 1;break;
		case 7 :  LED0 = 1;LED1 = 1;LED2 = 1;break;
	}
	P0 = REG2[y];
	Delay(1);
//	��Ӱ
	P0 = 0x00;
}