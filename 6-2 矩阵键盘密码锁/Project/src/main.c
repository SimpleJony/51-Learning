#include <Atmel/REGX52.H>
#include "../../Headers/LCD1602.h"
#include "../../Headers/Delay.h"
#include "../../Headers/MatrixKey.h"

unsigned char KeyNum;
unsigned int Password;
unsigned int cnt = 0;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	while(1)
	{
		KeyNum = MatrixKey();
		if (KeyNum && cnt<4) //判断是否输入4位密码
		{
			if (KeyNum<=10) // If s1-s10 pressed,insert password
			{
				Password *= 10; //数字左移
				Password += KeyNum%10; //获取数字
				cnt++;
			}
			LCD_ShowNum(2,1,Password,4); //update
		}
		if (KeyNum == 11) //if s11 pressed, confirm password
		{
			if(Password == 2345)
			{
				LCD_ShowString(1,14,"OK ");
				Delay(1000);
				Password = 0;
				cnt = 0;
				LCD_WriteCommand(0x01); //Reset LCD
				LCD_ShowString(1,1,"Password:");
				LCD_ShowNum(2,1,Password,4);
			}
			else
			{
				LCD_ShowString(1,14,"Err");
				Delay(1000);
				Password = 0;
				cnt = 0;
				LCD_WriteCommand(0x01); //Reset LCD
				LCD_ShowString(1,1,"Password:");
				LCD_ShowNum(2,1,Password,4);
			}
		}
		if (KeyNum == 12) //Cancel
		{
			Password = 0;
			cnt = 0;
			LCD_ShowNum(2,1,Password,4);
		}
	}
}