#include <Atmel/REGX52.H>
#include "include/Delay.h"
#define LEDMatrix_Port P0

sbit RCK = P3^5; //RCLK
sbit SCK = P3^6; //SRCLK
sbit SER = P3^4; //SER

void _74HC595_WriteByte(unsigned char Byte);
void LEDMatrix_ShowColumn(unsigned char column,Data);

void main()
{
    SCK = 0;
    RCK = 0;
    while(1)
    {
        LEDMatrix_ShowColumn(0,0x3C);
        LEDMatrix_ShowColumn(1,0x42);
        LEDMatrix_ShowColumn(2,0xA9);
        LEDMatrix_ShowColumn(3,0x85);
        LEDMatrix_ShowColumn(4,0x85);
        LEDMatrix_ShowColumn(5,0xA9);
        LEDMatrix_ShowColumn(6,0x42);
        LEDMatrix_ShowColumn(7,0x3C) ;
    }
}

/**
 * @brief   74HC595写入一个字节
 * @param   Byte一个字节
 * @retval  无
 */
void _74HC595_WriteByte(unsigned char Byte){
    unsigned char i;
    for (i=0;i<8;i++){
        SER = Byte&(0x80>>i); //SER只有一位，非0即1，取出byte第i位(从高到低)赋给SER
        SCK = 1; //给高电平 使移位
        SCK = 0;
    }
    RCK = 1; //整体移位
    RCK = 0;
}

/**
 * @brief   LED点阵屏显示一列数据
 * @param   Column 要选择的列，范围0-7
 * @param   Data 要显示的数据，高位在上，1为亮，0为灭
 * @retval  无
 */
void LEDMatrix_ShowColumn(unsigned char column,Data){
    _74HC595_WriteByte(Data);
    LEDMatrix_Port = ~0x80>>column;
    Delay(1);
    LEDMatrix_Port = 0xFF;
}