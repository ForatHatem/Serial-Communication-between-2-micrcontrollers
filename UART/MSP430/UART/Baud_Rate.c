#include <msp430.h>
#include "Baud_Rate.h"

void baud_rate_setup (void)
{
    //baud rate 9600 clock signal 32.768 KHz
    UCA0CTLW0 |= UCSWRST;
    UCA0BRW = 3;
    UCA0MCTLW = 0x9200;
}
