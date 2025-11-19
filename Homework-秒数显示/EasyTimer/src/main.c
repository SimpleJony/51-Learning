#include <Atmel/REGX52.H>
#include "include/Delay.h"
#include "include/Timer0.h"
#include "include/LCD1602.h"

unsigned char sec;

void main()
{
    Timer0_Init();
    LCD_Init();
    LCD_ShowString(1,1,"Now Time:");
    while(1)
    {
        LCD_ShowNum(2,1,sec,3);
    }
}

void Timer0_Routine() interrupt 1
{
    static unsigned int T0Count;
	TL0 = 0x18;
	TH0 = 0xFC;
    T0Count++;
    if (T0Count >= 1000){ // 1ms * 1000 = 1s
        T0Count = 0;
        sec++;
    }
}