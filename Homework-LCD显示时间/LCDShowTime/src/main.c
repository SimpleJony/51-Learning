#include <Atmel/REGX52.H>
#include "include/Delay.h"
#include "include/LCD1602.h"
#include "include/Timer0.h"

unsigned int hour,min,sec;
void main()
{
    LCD_Init();
    Timer0_Init();
    LCD_ShowString(1,1,"Running Time:");
    while(1)
    {
        LCD_ShowNum(2,1,hour,2);
        LCD_ShowChar(2,3,':');
        LCD_ShowNum(2,4,min,2);
        LCD_ShowChar(2,6,':');
        LCD_ShowNum(2,7,sec,2);                                                                                                  
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
        if (sec >= 60){
            sec = 0;
            min++;
            if (min >= 60){
                min = 0;
                hour++;
                if (hour >= 24) hour = 0;
            }
        }
    }
}