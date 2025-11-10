#include <REGX52.H>

void Delay1ms(unsigned int x)		//@12.000MHz
{
	unsigned char i, j;
	while(x)
	{ //run this function for x times
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
		P2 = 0xFE;
		Delay1ms(500);
		P2 = 0xFD;
		Delay1ms(500);
		P2 = 0xFB;
		Delay1ms(500);
		P2 = 0xF7;
		Delay1ms(500);
		P2 = 0xEF;
		Delay1ms(500);
		P2 = 0xDF;
		Delay1ms(500);
		P2 = 0xBF;
		Delay1ms(500);
		P2 = 0x7F;
		Delay1ms(500);
	}
}