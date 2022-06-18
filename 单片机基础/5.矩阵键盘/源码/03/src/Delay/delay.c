#include <REGX51.H>
#include <delay.h>



/**
	*	@brief	毫秒级延时函数
	*	@param	xms 延时的毫秒数
	*	@retval	无
*/

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