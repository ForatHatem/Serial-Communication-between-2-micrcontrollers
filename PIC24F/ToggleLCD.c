#include <xc.h>
#include "ToggleLCD.h"

/*
 
 INT1 P43 RP14 RB14
 
 */


#define ANALOG  1
#define DIGITAL 0

#define INPUT   1
#define OUTPUT  0

#define PULLUP_TRUE     1
#define PULLUP_FALSE    0

#define PULLUP_TRUE     1
#define PULLDOWN_FALSE  0

//BTN RB15
#define BTN_ANS             ANSBbits.ANSB14
#define BTN_TRIS            TRISBbits.TRISB14
#define _INPUT              PORTBbits.RB14
#define PULLUP_REG          IOCPUBbits.IOCPUB14
#define PULLDOWN_REG        IOCPDBbits.IOCPDB14


void InitToggleLCD (void)
{
    BTN_ANS = DIGITAL;
    BTN_TRIS = INPUT;
    
    PULLUP_REG = 0;
    PULLDOWN_REG = 1;
    
    //setting the pins for INT1
    //Unlock registers
    /*asm volatile(   "MOV    #OSCCON, w1 \n"
                    "MOV    #0x46, w2   \n"
                    "MOV    #0x57, w3    \n"
                    "MOV.b  w2, [w1]    \n"
                    "MOV.b  w3, [w1]    \n"
                    "BCLR   OSCCON, #6");
    
    RPINR0bits.INT1R = 14;//INT1 is RP14 p43
    
    
    
    
    
    //Lock registers
    asm volatile(   "MOV    #OSCCON, w1 \n"
                    "MOV    #0x46, w2    \n"
                    "MOV    #0x57, w3    \n"
                    "MOV.b  w2, [w1]    \n"
                    "MOV.b  w3, [w1]    \n"
                    "BSET   OSCCON, #6");*/
    
    
    
    
    //setting the interrupt
    INTCON1bits.NSTDIS = 0;//no isr nesting
    INTCON2bits.INT1EP = 0;//isr on positive edge
    //IPC5bits.INT1IP = 2;//only one ISR
    IFS1bits.INT1IF = 0;//clear flag
    IEC1bits.INT1IE = 1;//enable INT1 isr
}

