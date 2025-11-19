#include <Atmel/REGX52.H>
#include <MATH.H>
#include "include/Delay.h"
#include "include/MatrixKey.h"
#include "include/LCD1602.h"

unsigned char Key;
int res,num,temp,ctrl,pre_opt; //pre_opt来记录上一次的运算符

void main()
{
    LCD_Init();
    while(1)
    {
        Key = MatrixKey();
        if (Key){
            if (Key<=10){
                if (Key == 10) Key = 0; //key=10的时候判断为0，因为直接传0进不来if
                    LCD_ShowNum(1,++ctrl,Key,1);
                    num = num*10 + Key;
                }
            else if(Key == '+' || Key == '-' || Key == '*' || Key == '/'){
                if (pre_opt != 0){
                    if (pre_opt == '+') res += num;
                    if (pre_opt == '-') res -= num;
                    if (pre_opt == '*') res *= num;
                    if (pre_opt == '/') res /= num;
                }
                else res = num;
                num = 0;
                pre_opt = Key;
                LCD_ShowChar(1,++ctrl,Key);
            }
            else if (Key == '='){
                int cnt = 0;
                // 做最后一次计算
                if (pre_opt == '+') res += num;
                if (pre_opt == '-') res -= num;
                if (pre_opt == '*') res *= num;
                if (pre_opt == '/') res /= num;
                pre_opt = 0;
                LCD_ShowChar(2,1,'=');
                temp = abs(res);
                while (temp != 0){
                    cnt++;
                    temp = temp / 10;
                }
                if (res < 0){
                    LCD_ShowChar(2,2,'-');
                    LCD_ShowNum(2,3,-res,cnt);
                }
                else LCD_ShowNum(2,2,res,cnt);
            }
        }
    }
}