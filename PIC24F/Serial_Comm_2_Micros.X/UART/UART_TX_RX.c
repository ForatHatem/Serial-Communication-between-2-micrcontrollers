#include "xc.h"
#include "UART_TX_RX.h"

void sendChar (char ch)
{
    if(U1STAbits.TRMT)
    {
       U1TXREG = ch; 
    }
}

char receiveChar (void)
{
    char receivedChar;
    
    if(U1STAbits.OERR)
        U1STAbits.OERR = 0;
    
    if(_U1RXIF)
    {
        while(U1STAbits.URXDA)
        {
            receivedChar = U1RXREG;
        }
        
        _U1RXIF = 0;
    }
    
    return receivedChar;
}