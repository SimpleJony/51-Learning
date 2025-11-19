#include <Atmel/REGX52.H>
#include "include/Delay.h"

/**
  * @brief 矩阵键盘读取按键键码
  * @param 无
  * @retval KeyNumber 按下按键的键码值
			如果按键按下不放就会停留在此处，松手及返回，没有即返回0
  *
  */
unsigned char MatrixKey()
{
	unsigned char KeyNumber = 0;
	P1 = 0xFF;
	P1_3 = 0;
	if (P1_7 == 0)
	{
		Delay(20);
		while(P1_7 == 0);
		Delay(20);
		KeyNumber = 1;
	}
	if (P1_6 == 0)
	{
		Delay(20);
		while(P1_6 == 0);
		Delay(20);
		KeyNumber = 4;
	}
	if (P1_5 == 0)
	{
		Delay(20);
		while(P1_5 == 0);
		Delay(20);
		KeyNumber = 7;
	}
	
	P1 = 0xFF;
	P1_2 = 0;
	if (P1_7 == 0)
	{
		Delay(20);
		while(P1_7 == 0);
		Delay(20);
		KeyNumber = 2;
	}
	if (P1_6 == 0)
	{
		Delay(20);
		while(P1_6 == 0);
		Delay(20);
		KeyNumber = 5;
	}
	if (P1_5 == 0)
	{
		Delay(20);
		while(P1_5 == 0);
		Delay(20);
		KeyNumber = 8;
	}
	if (P1_4 == 0){
		Delay(20);
		while(P1_4 == 0);
		Delay(20);
		KeyNumber = 10;
	}
	
	P1 = 0xFF;
	P1_1 = 0;
	if (P1_7 == 0)
	{
		Delay(20);
		while(P1_7 == 0);
		Delay(20);
		KeyNumber = 3;
	}
	if (P1_6 == 0)
	{
		Delay(20);
		while(P1_6 == 0);
		Delay(20);
		KeyNumber = 6;
	}
	if (P1_5 == 0)
	{
		Delay(20);
		while(P1_5 == 0);
		Delay(20);
		KeyNumber = 9;
	}
	if (P1_4 == 0){
		Delay(20);
		while(P1_4 == 0);
		Delay(20);
		KeyNumber = '=';
	}
	
	P1 = 0xFF;
	P1_0 = 0;
	if (P1_7 == 0)
	{
		Delay(20);
		while(P1_7 == 0);
		Delay(20);
		KeyNumber = '+';
	}
	if (P1_6 == 0)
	{
		Delay(20);
		while(P1_6 == 0);
		Delay(20);
		KeyNumber = '-';
	}
	if (P1_5 == 0)
	{
		Delay(20);
		while(P1_5 == 0);
		Delay(20);
		KeyNumber = '*';
	}
	if (P1_4 == 0)
	{
		Delay(20);
		while(P1_4 == 0);
		Delay(20);
		KeyNumber = '/';
	}
	
	return KeyNumber;
}