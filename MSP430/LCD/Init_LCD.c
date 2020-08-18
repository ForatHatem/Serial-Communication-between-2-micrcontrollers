#include <msp430.h>
#include "Init_LCD.h"


void init_LCD (void)
{
    //config sx pins S19, S21, S11, S13,
    //S7, S9, S37, S39, S29, S31, S15, S17
    LCDCPCTL0 = LCD_SEG_A;
    LCDCPCTL1 = LCD_SEG_B;
    LCDCPCTL2 = LCD_SEG_C;

    //LCDCPCTL0 = 0xFFFF;
    //LCDCPCTL1 = 0xFC3F;
    //LCDCPCTL2 = 0x0FFF;//from TI


    //configuring: COM0 COM1 COM2 COM3
    //R23 R13/LCDREF R03
    P6SEL1 |= (BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6);
    P6SEL0 |= (BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6);

    LCDCCTL0 = (LCDPRE__16 | LCDDIV_3 | LCD4MUX | LCDLP);

    //LCDCCTL0 = LCDDIV__1 | LCDPRE__16 | LCD4MUX | LCDLP;//TI


    //LCDCVCTL = (LCDCPEN | LCDEXTBIAS | R03EXT | VLCDX);
    //LCDCVCTL = VLCD_1 | VLCDREF_0 | LCDCPEN;//TI

    //LCDCVCTL = VLCD_15 | VLCDREF_0 | R03EXT | LCDEXTBIAS | VLCDEXT | LCDCPEN;/

    //LCDCVCTL = 0x1E68;//external biasing
    //VLCD = 1111, LCDCPEN = 1, VLCDREF = 00, VLCD = 3.44V
    //R03EXT = 1, V5 sourced from R03 pin
    //LCDEXTBIAS = 1, V2 - V4 sourced externally, and internal bias generator is switched off
    //VLCDEXT = 0, VLCD (V1) is sourced internally from the Charge Pump
    //LCDPEN = 1, Charge Pump is enabled
    //LCD2B = 0, 1/3 Bias

    //LCDCVCTL = 0x1E28;

    //LCDCVCTL = 0x0228;


    LCDCVCTL = 0x1E08;

    LCDCCPCTL = LCDCPCLKSYNC;//TI

    CLEAR_LCD_MEM;

}

void init_OneSecond_Delay (void)
{
    TA1CTL |= (TASSEL__ACLK | TAIE);
    //TA1CCR0 = COUNT;
    TA1CCR0 = 32768;

    TA1CTL &= (~TAIFG);
}
