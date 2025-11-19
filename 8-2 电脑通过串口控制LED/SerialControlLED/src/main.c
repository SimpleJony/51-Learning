#include <Atmel/REGX52.H>
#include "include/Delay.h"
#include "include/UART.h"

void main()
{
    Uart_Init();
    while(1)
    {
        
    }
}

void UART_Routine() interrupt 4{
    if(RI==1){
        P2 = ~SBUF;
        Uart_SendByte(SBUF);
        RI = 0;
    }
}