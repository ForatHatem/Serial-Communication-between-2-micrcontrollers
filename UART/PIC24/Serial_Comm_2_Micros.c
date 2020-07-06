/*
   3V3 * 
       |        |---------|TX                RX|----------|
   BTN0|---/ ---|         |------------------->|          |----|>----|LED0 (RB4)
   BTN1|---/ ---|   MSP   |                    |   PIC24  |----|>----|LED1 (RB3)
   BTN2|---/ ---|         |<-------------------|          |----|>----|LED2 (RB2)
                |---------|RX                TX|----------|          |
                                                                     |
                                                                     V GND

 * UART Baud Rate 9600 8 bits, No Parity, LSB first, One Stop bit
 *  
 */


#pragma config FWDTEN = OFF
#pragma config ICS = PGD2

#pragma config FNOSC = FRC

#include "xc.h"
#include "UART/UART_SETUP.h"
#include "Digital_Input_Output/GPIO.h"
#include "UART/UART_TX_RX.h"
//#include "Delay/Delay.h"


int toggleState[] = {0,0,0};

void toggleLED (unsigned int LED)
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
}

void enable_interrupt (void);

void init_uart_rx_isr (void);

int main(void) 
{
    init_DigitalOutput ();
    
    setup_UART ();
    setup_UART_Pins ();
    enable_UART ();
    
    init_uart_rx_isr ();
    
    enable_interrupt ();
    
    //sendChar ('A');
    
    //enable uart_rx_isr
    
    //enable global interrupt
    
    while(1);
    
    /*while(1)
    {
        LED0 = 1;
        delay(1000);
        LED0 = 0;
        delay (1000);
    }*/
    
    /*while(1)
    {
        if(receiveChar () == 'A')
        {
            LED0 = 1;
            LED1 = 0;
            LED2 = 0;
        }
        else if(receiveChar () == 'B')
        {
            LED0 = 0;
            LED1 = 1;
            LED2 = 0;
        }
        else if(receiveChar () == 'C')
        {
            LED0 = 0;
            LED1 = 0;
            LED2 = 1;
        }
        
        else
        {
            LED0 = 0;
            LED1 = 0;
            LED2 = 0;
        }
    }*/
    
    return 0;
}

void enable_interrupt (void)
{
    INTCON2bits.GIE = 1;
}

void init_uart_rx_isr (void)
{
    //enable interrupt
    INTCON1bits.NSTDIS = 0;
    
    IEC0bits.U1RXIE = 1;
    
    IFS0bits.U1RXIF = 0;                     
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
        //LED0 = 1;
        //LED1 = 0;
        //LED2 = 0;
        toggleLED(0);
    }
    
    else if(receivedChar == 'B')
    {
        //LED0 = 0;
        //LED1 = 1;
        //LED2 = 0;
        toggleLED(1);
    }
    
    else if(receivedChar == 'C')
    {
        //LED0 = 0;
        //LED1 = 0;
        //LED2 = 1;
        toggleLED(2);
    }
    
    /*else
    {
        LED0 = 0;
        LED1 = 0;
        LED2 = 0;
    }*/
    _U1RXIF = 0;
}



