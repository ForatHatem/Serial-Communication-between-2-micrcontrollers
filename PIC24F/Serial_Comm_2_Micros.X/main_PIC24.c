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
#include "LCD.h"
#include "ToggleLCD.h"
 
unsigned int LED [] = {0,0,0};

void enable_interrupt (void);



int main(void) 
{
        
    init_DigitalOutput ();
    //init_PortISR ();
    
    setup_UART ();
    setup_UART_Pins ();
    enable_UART ();
    
    init_uart_rx_isr ();
   
    InitLCD ();
    InitToggleLCD();
    
    displayHelloMsg ();
    
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
        //led[0] = !LED[0];
    }
    
    else if(receivedChar == 'B')
    {
        toggleLED(1);
        //led[1] != LED[1]       
    }
    
    else if(receivedChar == 'C')
    {
        toggleLED(2);
    }
    
    _U1RXIF = 0;
}



/*
 void _interrupt__ _Port1_ISR
 {
 * static int mode = 0;
 * 
 * mode++;
 * 
 * if(mode > 4)
 *  mode = 0;
 * 
 * ClearDisplay();
 * 
 * if(mode == 0)
 *  displayHelloMsg ();
 * else if(mode == 1)
 *  displayLED(LED);
 * else if(mode == 2)
 *  displayComm(CommMode);
 * else if(mode == 3)
 *  displayPower(LED,POWER_PER_LED);
 * else if(mode == 4)
 *  displayPower(LED,TOTAL_POWER); 
 *}
 */
 
void __attribute__((__interrupt__,no_auto_psv)) _INT1Interrupt (void)
{
    static int mode = 0;
    
    mode++;
    
    if(mode > 4)
        mode = 0;
    
    ClearDisplayLCD();
    
    if(mode == 0)
        displayHelloMsg ();
    else if(mode == 1)
        displayLED(LED);
    else if(mode == 2)
        displayComm(0);
    else if(mode == 3)
        displayPower(LED,POWER_PER_LED);
    else if(mode == 4)
        displayPower(LED,TOTAL_POWER);
                
    _INT1IF = 0;
}