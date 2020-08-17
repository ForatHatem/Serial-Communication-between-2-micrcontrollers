#include <msp430.h>
#include "Clock_Initialization.h"

void clock_initialization (void)
{
    //smclk and mclk = 8Mhz DCO
    //is it possible to disable ACLK

    CSCTL0 = CSKEY;//password in order to modify clock signal
    CSCTL1 = DCOFSEL_3;//DCO 4Mhz
    CSCTL2 = SELA__LFXTCLK | SELS__DCOCLK | SELM__DCOCLK;//ACLK -> LFXTCLK (32.768KHz) SMCLK & MCLK -> DCOCLK
    CSCTL3 = 0x0000;//DIVS DIVM DIVA are 0

    //enable the LFXIN and LFXOUT pins PJ.4 and PJ.5 P84 and P85
    PJSEL0 |= BIT4;//PJSEL0.4 = 1
    PJSEL1 &= ~BIT4;//PJSEL1.4 = 0
}
