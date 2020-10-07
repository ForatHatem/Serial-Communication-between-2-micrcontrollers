#include <xc.h>
//#include "System.h"
#include "LCD.h"
#include <stdio.h>

//timer definitions
#define FOSC         16000000
#define FCY          (FOSC/2)

//fast lcd instruction time > 40us
#define LCD_F_INSTR  2//400//count = Fcy*t = 40us*8Mhz
//#define LCD_F_INSTR  (FCY*40)

//slow lcd instruction time > 1.64ms
#define LCD_S_INSTR  52//15000//count = Fcy*t = 1640us*8Mhz = 
//#define LCD_S_INSTR  (FCY*1640)


//starting up the LCD requires a delaly of > 60ms
#define LCD_STARTUP     1900//count = Fcy*t = 60ms * 8000 Khz = 480000 loop 8 times
//#define LCD_STARTUP     ((FCY/1000)*60)

#define ONE_SEC_DELAY   31250

#define CS1_BASE_ADDRESS    0x00020000ul //start of CS1 address at the eds
#define CS2_BASE_ADDRESS    0x000A0000ul //start of CS2 address at the eds

#define LCD_delay(delay) {TMR1 = 0; while(TMR1 < delay);}

#define LCD_SendData(data) {DATA = data; LCD_delay(LCD_F_INSTR);}
#define LCD_SendCommand(command, delay) {CMD = command; LCD_delay(delay);}


//#define TOTAL_POWER     1
//#define POWER_PER_LED   0

static __eds__ unsigned int __attribute__ ( ( noload , section ( "epmp_cs1" ) , address ( CS1_BASE_ADDRESS ) ) ) CMD 
__attribute__ ( ( space ( eds ) ) ) ;
static __eds__ unsigned int __attribute__ ( ( noload , section ( "epmp_cs1" ) , address ( CS1_BASE_ADDRESS ) ) ) DATA 
__attribute__ ( ( space ( eds ) ) ) ;
 
//unsigned int LED [3];

enum CommandsLCD
{
    FunctionSet = 0x38,
    DisplayON = 0x0C,
    EntryModeSet = 0x06,
    Row0Set = 0x80,
    Row1Set = 0xC0,
    ClearDisplay = 0x01,
    ReturnCursorHome = 0x02
};

void displayHelloMsg (void);
void displayComm (unsigned int CommMode);
//void displayLED (unsigned int LED0, unsigned int LED1, unsigned int LED2);
//void displayPower (unsigned int LED0, unsigned int LED1, unsigned int LED2);
void displayLED(unsigned int * LED);
void displayPower(unsigned int * LED, unsigned int powerMode);

//void ClearDisplay (void);

void displayString(char*str)
{  
       
    while(*str)
    {
        LCD_SendData(*str);
        str++;//while the dereference of str is not a null loop
        //send the dereference, incr str pointer position to next char                 
    }
    
}

void InitEPMP (void)
{
    PMCON1bits.ADRMUX = 0 ;      // address is not multiplexed
    PMCON1bits.MODE = 3 ;        // master mode
    PMCON1bits.CSF = 0 ;         // PMCS1 pin used for chip select 1,
    // PMCS2 pin used for chip select 2
    PMCON1bits.ALP = 0 ;         //
    PMCON1bits.ALMODE = 0 ;      // "smart" address strobes are not used
    PMCON1bits.BUSKEEP = 0 ;     // bus keeper is not used

    // CS1 start address
    PMCS1BS = ( CS1_BASE_ADDRESS >> 8 ) ;
    //PMCS1BS = CS1_BASE_ADDRESS;

    PMCS1CFbits.CSDIS = 0 ;      // enable CS
    PMCS1CFbits.CSP = 1 ;        // CS1 polarity
    PMCS1CFbits.BEP = 1 ;        // byte enable polarity
    PMCS1CFbits.WRSP = 1 ;       // write strobe polarity
    PMCS1CFbits.RDSP = 1 ;        // read strobe polarity
    PMCS1CFbits.CSPTEN = 1 ;     // enable CS port
    PMCS1CFbits.SM = 1;//PMCS1CFbits.SM = 0 ;         // read and write strobes on separate lines
    PMCS1CFbits.PTSZ = 0 ;       // data bus width is 8-bit
    PMCS1MDbits.ACKM = 0 ;       // PMACK is not used

    // The device timing parameters. Set the proper timing
    // according to the device used (the timing macros are defined in the hardware profile)
    PMCS1MDbits.DWAITB = 0b11 ;     // access time 3 1/4 Tcy
    PMCS1MDbits.DWAITM = 0b1111 ;
    PMCS1MDbits.DWAITE = 0b11 ;

    PMCON2bits.RADDR = 0 ;       // don't care since CS2 is not be used
    PMCON4 = 0x0001 ;            // PMA0 - PMA15 address lines are enabled

    PMCON3bits.PTWREN = 1 ;      // enable write strobe port
    PMCON3bits.PTRDEN = 1 ;      // enable read strobe port
    PMCON3bits.PTBE0EN = 1 ;     // enable byte enable port
    PMCON3bits.PTBE1EN = 1 ;     // enable byte enable port
    PMCON3bits.AWAITM = 0b11 ;      // set address latch pulses width to 3 1/2 Tcy
    PMCON3bits.AWAITE = 1 ;      // set address hold time to 1 1/4 Tcy

    PMCON1bits.PMPEN = 1 ;       // enable the module
}

void InitLCD (void)
{
    //unsigned int LED [] = {1,0,1};
    
    InitEPMP ();
    
    
    T1CON = 0x8030;
    
    
    LCD_delay(LCD_STARTUP);
    
    LCD_SendCommand((unsigned int)FunctionSet,LCD_F_INSTR);//8 bits 2 lines
    
    
    LCD_SendCommand((unsigned int)DisplayON,LCD_F_INSTR);
    
    //Enter Data mode or Entry Mode
    LCD_SendCommand((unsigned int)EntryModeSet,LCD_F_INSTR);


    
    //Clear the screen
   
    LCD_SendCommand((unsigned int)ClearDisplay,LCD_S_INSTR);
    LCD_SendCommand((unsigned int)ReturnCursorHome,LCD_S_INSTR);
        
    /*while(1)
    {
        LCD_SendCommand((unsigned int)ClearDisplay,LCD_S_INSTR);
        
        displayHelloMsg ();
    
        LCD_delay(ONE_SEC_DELAY);
    
        LCD_SendCommand((unsigned int)ClearDisplay,LCD_S_INSTR);
        
        displayLED(LED);
    
        LCD_delay(ONE_SEC_DELAY);
        
        LCD_SendCommand((unsigned int)ClearDisplay,LCD_S_INSTR);
        
        displayComm(0);
        
        LCD_delay(ONE_SEC_DELAY);
        
        LCD_SendCommand((unsigned int)ClearDisplay,LCD_S_INSTR);
        
        displayPower(LED,POWER_PER_LED);
        
        LCD_delay(ONE_SEC_DELAY);
        
        LCD_SendCommand((unsigned int)ClearDisplay,LCD_S_INSTR);
        
        displayPower(LED,TOTAL_POWER);
        
        LCD_delay(ONE_SEC_DELAY);
    }*/
    
}

void displayHelloMsg (void)
{
    displayString("Hello");
}

void displayLED (unsigned int * LED)
{
    char * str[3] = {"L0 ","L1 ","L2 "};
    
    int i = 0;
    for(i = 0; i < 3; i++)
    {
        if(i == 2)
            LCD_SendCommand((unsigned int)Row1Set,LCD_F_INSTR);//move cursor down
        
        displayString(str[i]);
        
        if(LED[i] != 0)//ON
            displayString("ON ");
        else
            displayString("OFF ");
        
    }
    
    LCD_SendCommand(Row0Set,LCD_F_INSTR);
}

void displayComm (unsigned int CommMode)
{
    if(CommMode == 0)
        displayString("UART");
    else if(CommMode == 1)
        displayString("SPI");
    else if(CommMode == 2)
        displayString("I2C");
}

void displayPower (unsigned int * LED, unsigned int powerMode)
{
//P = VI
#define V  3
#define I  5 //mA
#define P  (V*I)
    
    char power[4];
    //unsigned int LED [] = {LED0*P,LED1*P,LED2*P};//LEDX is either 0 or 1
    //unsigned int TotalPower = 0;
    
    //sprintf(power,"%d",P);
    
    /*int i = 0;
    for(i = 0;i < 3;i++)
    {
        if(i == 2)
            LCD_SendCommand((unsigned int)Row1Set,LCD_F_INSTR);
        
        displayString(str[i]);
        
        sprintf(power,"%d",LED[i]);
        
        displayString(power);
        
        displayString("mW ");
    }
    
    LCD_SendCommand((unsigned int)Row0Set,LCD_F_INSTR);*/
    
    if(powerMode)//total power
    {
        unsigned int TotalPower = 0;
        int i = 0;
        for(i = 0; i < 3; i++)
            TotalPower += (LED[i]*P);
        
        sprintf(power,"%d",TotalPower);
        
        displayString("Total Power = ");
        
        LCD_SendCommand(Row1Set,LCD_F_INSTR);
        
        displayString(power);
        displayString("mW ");
    }
    else
    {
        char * str[3] = {"P0 ","P1 ","P2 "};//an array of char pointers
        sprintf(power,"%d",P);
        int i = 0;
        for(i = 0; i < 3; i++)
        {
            if(i == 2)
                LCD_SendCommand(Row1Set,LCD_F_INSTR);
            
            displayString(str[i]);
            
            if(LED[i] != 0)//ON
                displayString(power);
            else
                displayString("0");
            
            displayString("mW ");
        }
        
        LCD_SendCommand(Row0Set,LCD_F_INSTR);
    }
        
    
}

void ClearDisplayLCD (void)
{
    LCD_SendCommand((unsigned int)ClearDisplay,LCD_S_INSTR);
}