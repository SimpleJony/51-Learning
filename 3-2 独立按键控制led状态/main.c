#include <REGX51.H>

void Delay(unsigned int x)		//@12.000MHz
{
	unsigned char i, j;
	
	while(x)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		x--;
	}
}


void main()
{
	while(1)
	{
		if(P3_1 == 0) //button xiaodou
		{
			Delay(20);
			while(P3_1 == 0);
			Delay(20);
			P2_0 = ~P2_0;
		}
	}
}