#include <msp430.h>
#include "UART.h"
#include "Digital_Input_Output/Debounce.h"

void init_UART (void)
{
    UCA0CTLW0 &= ~ (UCPEN | UCMSB | UC7BIT | UCSPB | UCSYNC);
    //No Parity, LSB, 8 bits, One Stop Bit, Ascyc.
    UCA0CTLW0 |= UCSSEL__SMCLK;
    UCA0CTLW0 &= ~UCSWRST;

    P4SEL0 |= (BIT2 | BIT3);
    P4SEL1 &= ~(BIT2 | BIT3);
}

void sendChar (enum Button x)
{
    switch(x)
    {
    case Button0:
        UART_TX_BUF = 'A';//'U';//'A';//0;//'A';
        break;
    case Button1:
        UART_TX_BUF = 'B';
        break;
    case Button2:
        UART_TX_BUF = 'C';
        break;
    default:
        break;
    }
}
