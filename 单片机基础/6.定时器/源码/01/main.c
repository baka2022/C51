#include <REGX52.H>




void Timer0_Init()
{
	TMOD = TMOD & 0xF0;
	TMOD = TMOD | 0x01;
	TF0 = 0;
	TR0 = 1;
	TL0 = 0x17;
	TH0 = 0xFC;
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}



void main()
{
	Timer0_Init();

	while(1)
	{
		
	}
}


unsigned int count;
void Time0_Routine()interrupt 1
{
		TL0 = 0x17;
		TH0 = 0xFC;
		count++;
		if(count == 1000)
		{
			P2 = ~P2;
			count = 0;
		}
}
