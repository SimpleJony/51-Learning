#include <Atmel/REGX52.H>
#include "include/Delay.h"

/**
 * @brief 获取独立按键返回值
 * @param 无
 * @retval 按下按键键码，范围0-4，无按下返回0
 */
unsigned char Key()
{
    unsigned char KeyNum = 0;
    if (P3_1 == 0){
        Delay(20);
        while (P3_1 == 0);
        Delay(20);
        KeyNum = 1;
    }
    if (P3_0 == 0){
        Delay(20);
        while (P3_0 == 0);
        Delay(20);
        KeyNum = 2;
    }
    if (P3_2 == 0){
        Delay(20);
        while (P3_2 == 0);
        Delay(20);
        KeyNum = 3;
    }
    if (P3_3 == 0){
        Delay(20);
        while (P3_3 == 0);
        Delay(20);
        KeyNum = 4;
    }

    return KeyNum;
}