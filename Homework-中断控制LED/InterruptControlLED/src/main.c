#include <Atmel/REGX52.H>
#include <MATH.H>
#include "include/Delay.h"
#include "include/Timer0.h"

unsigned int begin,end;
unsigned char state;

void main()
{
    Timer0_Init();
    while(1)
    {

    }
}

void Timer0_Routine() interrupt 1
{
    static unsigned int T0Count;
	TL0 = 0x18;
	TH0 = 0xFC;
    T0Count++;
    if (T0Count >= 20){ // 1ms * 1000 = 1s
        T0Count = 0;
        if (P3_1 == 0){
            Delay(20);
            while (P3_1 == 0);
            Delay(20);
            state = 0;
            P2 = 0xff;
            begin = 0;
            end = 7;
            while (begin <= 5 && end >= 4){
                Delay(1000);
                P2 = 0xff;
                state += pow(2,begin) + pow(2,end);
                P2 = ~(P2 & state);
                begin++;
                end--;
            }
        }
        if (P3_0 == 0){
            Delay(20);
            while (P3_0 == 0);
            Delay(20);
            state = 0;
            P2 = 0xff;
            begin = 4;
            end = 3;
            while (begin <= 8 && end >= 0){
                Delay(1000);
                P2 = 0xff;
                state += pow(2,begin) + pow(2,end);
                P2 = ~(P2 & state);
                begin++;
                end--;
            }
        }
        if (P3_2 == 0){
            Delay(20);
            while (P3_2 == 0);
            Delay(20);
            P2 = 0xff;
        }
    }
}