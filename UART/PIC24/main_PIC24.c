/*
   3V3 * 
       |        |---------|TX   (RD9/RP4/P69)RX|----------|
   BTN0|---/ ---|         |------------------->|          |----|>----|LED0 (RB4) P21
   BTN1|---/ ---|   MSP   |P4.2                |   PIC24  |----|>----|LED1 (RB3) P22
   BTN2|---/ ---|         |<-------------------|          |----|>----|LED2 (RB2) P23
                |---------|RX  (RD10/RP3/P70)TX|----------|          |
                           P4.3                                          |
                                                                     V GND

 * UART Baud Rate 9600 8 bits, No Parity, LSB first, One Stop bit
 * MSP430 CS 4MHz
 * PIC24  CS 4MHz
 *  
 */


#pragma config FWDTEN = OFF
#pragma config ICS = PGD2

#pragma config FNOSC = FRC

#include "xc.h"
#include "UART/UART_SETUP.h"
#include "Digital_Input_Output/GPIO.h"
#include "Digital_Input_Output/TOGGLE_LED.h"
#include "UART/UART_TX_RX.h"


//int toggleState[] = {0,0,0};

/*void toggleLED (unsigned int LED)
{
    if(LED >= 0 && LED < 3)
        toggleState[LED] = !toggleState[LED];
    
    switch(LED)
    {
        case 0:
            LED0 = toggleState[LED];
            break;
        case 1:
            LED1 = toggleState[LED];
            break;
        case 2:
            LED2 = toggleState[LED];
            break;
        default:
            break;
    }
}*/

void enable_interrupt (void);

int main(void) 
{
    init_DigitalOutput ();
    
    setup_UART ();
    setup_UART_Pins ();
    enable_UART ();
    
    init_uart_rx_isr ();
    
    enable_interrupt ();
    
    while(1);
    
    return 0;
}

void enable_interrupt (void)
{
    INTCON2bits.GIE = 1;
}

void __attribute__((__interrupt__,no_auto_psv)) _U1RXInterrupt (void)
{ 
    char receivedChar;
    
    if(U1STAbits.OERR)
        U1STAbits.OERR = 0;
    
    while(U1STAbits.URXDA)
        receivedChar = U1RXREG;
    
    if(receivedChar == 'A')
    {
        toggleLED(0);
    }
    
    else if(receivedChar == 'B')
    {
        toggleLED(1);
    }
    
    else if(receivedChar == 'C')
    {
        toggleLED(2);
    }
    
    _U1RXIF = 0;
}



