#include <msp430.h>
#include "GPIO.h"

//BTN0 -> P1.5
//BTN1 -> P1.6
//BTN2 -> P1.7

/*temp
 *LED0 -> P9.3
 *LED1 -> P1.4
 *LED2 -> P2.0
 */

void init_GPIO (void)
{
    P1DIR &= ~(BIT5 | BIT6 | BIT7);

    P1REN |= (BIT5 | BIT6 | BIT7);

    P1OUT &= ~(BIT5 | BIT6 | BIT7);//pulldown

    P9DIR |= BIT3;
    P1DIR |= BIT4;
    P2DIR |= BIT0;
}
