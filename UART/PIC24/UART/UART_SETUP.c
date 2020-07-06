#include "xc.h"
#include "UART_SETUP.h"

void setup_UART (void)
{
    U1BRG = BRG_PERIOD;
    
    U1MODE = 0;
    U1MODEbits.UEN = 0;//only U1RX and U1TX
    U1MODEbits.BRGH = 0;
    U1MODEbits.PDSEL = 0;//8-bits, No Parity
    U1MODEbits.STSEL = 0;//One-Stop bit
    
    U1STAbits.UTXISEL0 = 0;
    U1STAbits.UTXISEL1 = 0;//U1TXIF set when a write a U1TXREG
    
    U1STAbits.URXISEL = 0;
}

void setup_UART_Pins (void)
{
    //TRISDbits.TRISD10 = 0;
    
    //TRISDbits.TRISD9 = 1;
    
    //CONFIG_U1TX;
    //CONFIG_U1RX;
    
    U1RX_INPUT;
    U1RX_CONFIG;
    
    U1TX_OUTPUT;
    U1TX_CONFIG;
    
    asm volatile    ("MOV #OSCCON, w1   \n"
                    "MOV #0x46, w2      \n"
                    "MOV #0x57, w3      \n"
                    "MOV.b w2, [w1]     \n"
                    "MOV.b w3, [w1]     \n"
                    "BSET OSCCON, #6");
}

void enable_UART (void)
{
    ENABLE_UART;
    ENABLE_TX_UART;
    ENABLE_RX_UART;
    
    _U1TXIF = 0;
    _U1RXIF = 0;
    
    DELAY_105uS                
}