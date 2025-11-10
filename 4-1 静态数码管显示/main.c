#include <REGX52.H>

unsigned char NixieTable[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void Nixie(unsigned char Location,Num)
{
	switch(Location)
	{
		case 1:P2_4=1;P2_3=1;P2_2=1;break; //Led8
		case 2:P2_4=1;P2_3=1;P2_2=0;break; //Led7
		case 3:P2_4=1;P2_3=0;P2_2=1;break; //Led6
		case 4:P2_4=1;P2_3=0;P2_2=0;break; //Led5
		case 5:P2_4=0;P2_3=1;P2_2=1;break; //Led4
		case 6:P2_4=0;P2_3=1;P2_2=0;break; //Led3
		case 7:P2_4=0;P2_3=0;P2_2=1;break; //Led2
		case 8:P2_4=0;P2_3=0;P2_2=0;break; //Led1
	}
	P0 = NixieTable[Num];
}

void main()
{
	Nixie(2,5);
	while(1)
	{
		
	}
}