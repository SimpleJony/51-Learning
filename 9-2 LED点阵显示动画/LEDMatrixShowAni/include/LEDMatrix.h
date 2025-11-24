#ifndef __LEDMATRIX_H__
#define __LEDMATRIX_H__

void LEDMatrix_Init();
void _74HC595_WriteByte(unsigned char Byte);
void LEDMatrix_ShowColumn(unsigned char column,Data);

#endif