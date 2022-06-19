//DS1302��������DALLAS��˾�Ƴ��ľ����ϸ������������ĵ͹���ʵʱʱ��оƬ��
//�����Զ��ꡢ�¡��ա��ܡ�ʱ���֡�����м�ʱ���Ҿ������겹���ȶ��ֹ��ܡ�



#include <REGX52.H>
#include "INTRINS.h"
#include "LCD1602.h"
#include "delay.h"
#include "DS1302.h"


void main()
{
	LCD_Init();
	DS1302_init();
	while(1)
	{
		unsigned char miao,fen,shi,nian,yue,ri;
		miao = DS1302_readbyte(0x81);
		miao = miao/16*10 + miao%16;
		fen = DS1302_readbyte(0x83);
		fen = fen/16*10 + fen%16;
		shi = DS1302_readbyte(0x85);
		shi = shi/16*10 + shi%16;
		nian = DS1302_readbyte(0x8D);
		nian = nian/16*10 + nian%16;
		yue = DS1302_readbyte(0x89);
		yue = yue/16*10 + yue%16;
		ri = DS1302_readbyte(0x87);
		ri = ri/16*10 + ri%16;
		LCD_ShowString(1,1,"Time:");
		LCD_ShowNum(1,7,shi,2);
		LCD_ShowString(1,9,":");
		LCD_ShowNum(1,10,fen,2);
		LCD_ShowString(1,12,":");
		LCD_ShowNum(1,13,miao,2);
		LCD_ShowString(2,1,"Date:");
		LCD_ShowNum(2,7,nian,2);
		LCD_ShowString(2,9,"-");
		LCD_ShowNum(2,10,yue,2);
		LCD_ShowString(2,12,"-");
		LCD_ShowNum(2,13,ri,2);

	}
}







