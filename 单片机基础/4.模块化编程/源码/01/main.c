#include <REGX51.H>
#include <intrins.h>
#include "delay.h"
#include "seg.h"

void main()
{

	while(1)
	{
		int i = 0;
		for(i;i<=7;i++)
		{
			display(i,i);
		}
	}
}


