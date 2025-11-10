#include <Atmel/REGX52.H>
#include "include/Delay.h"

void main()
{
    P2 = 0xFF;
    while(1)
    {
        if (P3_1 == 0){
            Delay(20);
            while (P3_1 == 0);
            Delay(20);
            P2_0 = ~P2_0;
        }
        if (P3_0 == 0){
            Delay(20);
            while (P3_0 == 0){
                P2_1 = ~P2_1;
                break;
            }
            Delay(20);
            while (P3_0 == 0);
        }
    }
}