#include "xc.h"


//disable Watch Dog Timer
#pragma config FWDTEN = OFF  // Watchdog Timer Enable bits (WDT and SWDTEN disabled)
#pragma config ICS = PGD2    // ICD Communication Channel Select bits (Communicate on PGEC2 and PGED2)

void init_Digital_Output (void);
void init_Digital_Input (void);

void Toggle_LED(unsigned int LED);

int main(void) 
{
    init_Digital_Output ();
    init_Digital_Input ();
    
    unsigned int flag = 0;
    
    while(1)
    {
        if(PORTAbits.RA9)
        {
            Toggle_LED(flag);
            ++flag;
            
            if(flag == 3)
                flag = 0;
        }
            
        
 
    }
    
    return 0;
}

void init_Digital_Output (void)
{
    //P44, P42, P40 are digital outputs
    //RB15 RB13 RF12
    TRISBbits.TRISB15 = 0;//output
    TRISBbits.TRISB13 = 0;
    TRISFbits.TRISF12 = 0;
    
    ANSBbits.ANSB15 = 0;//digital
    ANSBbits.ANSB13 = 0;
}

void init_Digital_Input (void)
{
    //P28 RA9 is digital input
    //enable pull down resistor
    TRISAbits.TRISA9 = 1;//input
    ANSAbits.ANSA9 = 0;//digital
    
    IOCPDAbits.IOCPDA9 = 1;//enable RA9 PD
    IOCPUAbits.IOCPUA9 = 0;//disable RA9 PU
}

void Toggle_LED (unsigned int LED)
{
    if(LED == 0)
        LATBbits.LATB15 = ~LATBbits.LATB15;
    
    else if(LED == 1)
        LATBbits.LATB13 = ~LATBbits.LATB13;
    
    else if(LED == 2)
        LATFbits.LATF12 = ~LATFbits.LATF12;
}