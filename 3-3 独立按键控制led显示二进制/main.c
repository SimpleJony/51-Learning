#include <REGX52.H>

void Delay(unsigned int x)		//@12.000MHz
{
	unsigned char i, j;
	while(x--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}


void main()
{
	unsigned char LEDNum = 0;
	while(1)
	{
		if (P3_1 == 0)
		{
			Delay(20);
			while(P3_1 == 0);
			Delay(20);
			
			LEDNum++;
			P2 = ~LEDNum;
		}
	}
}