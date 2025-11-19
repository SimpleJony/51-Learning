#include <Atmel/REGX52.H>
#include "include/Delay.h"
#include "include/LCD1602.h"

unsigned char cnt;

void main()
{
    LCD_Init();
    LCD_ShowString(1,1,"Click Number:");
    while(1)
    {
        if(P3_1 == 0){
            Delay(20);
            while(P3_1 == 0);
            Delay(20);
            cnt++;
        }
        if(P3_0 == 0){
            Delay(20);
            while(P3_0 == 0);
            Delay(20);
            if(cnt != 0) cnt--;
        }
        LCD_ShowNum(2,1,cnt,3);
    }
}