#include <Atmel/REGX52.H>
#include "include/Delay.h"
#include "include/Key.h"
#include "include/Timer0.h"
#include "include/LCD1602.h"

unsigned char hour=12,min=0,sec=0;
unsigned char KeyNum;

void main()
{
    LCD_Init();
    Timer0_Init();
    while(1)
    {
        KeyNum = Key();
        if (KeyNum == 1){
            LCD_ShowString(1,1,"20251106");
        }
        if (KeyNum == 2){
            while(1){
                LCD_ShowNum(2,1,hour,2);
                LCD_ShowString(2,3,":");
                LCD_ShowNum(2,4,min,2);
                LCD_ShowString(2,6,":");
                LCD_ShowNum(2,7,sec,2);
            }
        }
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