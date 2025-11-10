#include <Atmel/REGX52.H>
#include "include/Delay.h"
#include "include/Nixie.h"
#include "include/Timer0.h"
#include "include/Key.h"

unsigned char hour=12,min=0,sec=0;
unsigned char KeyNum,mode; //引入mode来管理

void main()
{
    Timer0_Init();
    while(1)
    {
        KeyNum = Key();
        if (KeyNum == 1) mode = 1;
        if (KeyNum == 2) mode = 2;

        if (mode == 1){
            Nixie(1,2);
            Nixie(2,0);
            Nixie(3,2);
            Nixie(4,5);
            Nixie(5,1);
            Nixie(6,1);
            Nixie(7,0);
            Nixie(8,6);
        }
        if (mode == 2){
            Nixie(1,hour/10);
            Nixie(2,hour%10);
            Nixie(3,min/10);
            Nixie(4,min%10);
            Nixie(5,sec/10);
            Nixie(6,sec%10);
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