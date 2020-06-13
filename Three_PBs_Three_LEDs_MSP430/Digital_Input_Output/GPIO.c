#include <msp430.h>
#include "GPIO.h"

//BTN0 -> P2.1
//BTN1 -> P1.5
//BTN2 -> P9.4

/*temp
 *LED0 -> P9.3
 *LED1 -> P1.4
 *LED2 -> P2.0
 */

void init_GPIO (void)
{
    P1DIR &= (~BIT5);
    P2DIR &= (~BIT1);
    P9DIR &= (~BIT4);//all digital input

    P1REN |= BIT5;
    P2REN |= BIT1;
    P9REN |= BIT4;//enable pull up/ pull down resistor

    P1OUT &= (~BIT5);
    P2OUT &= (~BIT1);
    P9OUT &= (~BIT4);//pull down

    P9DIR |= BIT3;
    P1DIR |= BIT4;
    P2DIR |= BIT0;
}
