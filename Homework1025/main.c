#include <REGX52.H>
unsigned char state = 0xFF;
/*
	Don't use "unsigned" to define i and j
	when i=0,it'll make i-- = 65535, make program stucked
*/
int i,j;
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
		state = 0xFF; //reset state when done
		for (i=7;i>=0;i--)
		{
			for (j=0;j<=i;j++)
			{
				P2 = ~(1<<j)&state;
				Delay(100);
			}
			state &= ~(1<<i);
		}
	}
}