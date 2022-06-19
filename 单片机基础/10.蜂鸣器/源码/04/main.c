#include <REGX52.H>
#include "INTRINS.h"
#include "delay.h"
#include "timer.h"


#define SPEED 500

sbit SOUNDER = P2^1;

unsigned int fre[] = {
	0,
	63577,
	63691,
	63792,
	63892,
	63981,
	64070,
	64152,
	64229,
	64303,
	64372,
	64442,
	64499,
	64557,
	64612,
	64664,
	64713,
	64759,
	64803,
	64844,
	64883,
	64919,
	64954,
	64987,
	65017,
	65047,
	65074,
	65100,
	65124,
	65148,
	65169,
	65190,
	65209,
	65228,
	65245,
	65261,
	65536,
};


unsigned char music[] = {
	13,4,
	13,4,
	20,4,
	20,4,
	22,4,
	22,4,
	20,4 + 4,
	18,4,
	18,4,
	17,4,
	17,4,
	15,4,
	15,4,
	13,4 + 4,
};

unsigned char fresel,msel;

void main()
{
	Timer0_Init();
	while(1)
	{

		fresel = music[msel];
		msel++;
		Delay(SPEED / 4 * music[msel]);
		msel++;
		TR0 = 0;
		Delay(5);
		TR0 = 1;
	
	}
}


void Time0_Routine()interrupt 1
{
		TL0 = fre[fresel]%256;
		TH0 = fre[fresel]/256;
		SOUNDER = !SOUNDER;
}




