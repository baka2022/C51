#include <REGX51.H>
#include <delay.h>




//ÑÓÊ±º¯Êý
void Delay(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;

	while(xms--)
	{
				i = 2;
				j = 239;
				do
				{
					while (--j);
				} while (--i);
	}
}