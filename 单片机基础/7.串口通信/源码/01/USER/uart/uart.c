#include"uart.h"
#include <REGX52.H>

void uart_init()
{
	SCON = 0x40;
	PCON = PCON & 0x80;
	TMOD = TMOD & 0x0F;
	TMOD = TMOD | 0x20;
	TF1 = 0;
	TR1 = 1;
//	≤®Ãÿ¬ 9600°¢ ±÷”11.05926MHz
	TL1 = 0xFD;
	TH1 = 0xFD;
	ET1 = 0;
}


void uart_sendbyte(unsigned char byte)
{
	SBUF = byte;
	while(TI == 0);
	TI = 0;
}


