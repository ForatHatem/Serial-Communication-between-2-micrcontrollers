#include "xc.h"
#include "GPIO.h"

void init_DigitalOutput (void)
{   
    LED0_INPUT;
    LED1_INPUT;
    LED2_INPUT;
    
    LED0_DIGITAL;
    LED1_DIGITAL;
    LED2_DIGITAL;
}

void init_PortISR (void)
{
    //when a toggle LCD button is pressed
    //Port A, rising edge, pulldown
    //ANSA is analogu
    
    ANSAbits.ANSA6 = 0;//RA6 is in digital mode
    TRISAbits.TRISA6 = 1;//digital input
    
    IOCPUAbits.IOCPUA6 = 0;
    IOCPDAbits.IOCPDA6 = 1;//pulldown
    
    PADCONbits.IOCON = 1;//port a isr enabled
    
    IOCPAbits.IOCPA6 = 1;//ra6 L -> H
    IOCNAbits.IOCNA6 = 0;//ra6 L -> H only
    
    IOCFAbits.IOCFA6 = 0;//clear flag
}