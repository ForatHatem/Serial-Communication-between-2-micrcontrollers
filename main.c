#include <msp430.h> 

//press P1.5, goes to an ISR and toggles an LED

#define PUSHBUTTON     0x20 //0b0010 0000  1101 1111
#define LED_OUTPUT     0x01 //0b0000 0001
#define CLEAR_RED_LED  0xFE //0b1111 1110
#define ENABLE_PINS    0xFFFE
#define TOGGLE_LED     0x80

void initDigitalInput (void);
void initDigitalOutput (void);
void initDebounceTimer (void);

void start_Debounce_Timer (void);
void stop_Debounce_Timer (void);

int is_Button_Pressed (void);
int is_Debounce_Timer_Greater_1ms (void);

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	PM5CTL0 = ENABLE_PINS;
	
	initDigitalInput ();
	initDigitalOutput ();
	initDebounceTimer ();

	int FirstFlag = 0;
	int value = 0;

	while(1)
	{
	    if(is_Button_Pressed () && !FirstFlag)
	    {
	        FirstFlag = 1;
	        start_Debounce_Timer ();
	        P4OUT = P4OUT ^ TOGGLE_LED;
	    }

	    else if(!is_Button_Pressed() && FirstFlag && !is_Debounce_Timer_Greater_1ms())
	        stop_Debounce_Timer ();//resets timer as well

	    else if(is_Button_Pressed() && FirstFlag)
	        start_Debounce_Timer ();

	    else if(!is_Button_Pressed() && FirstFlag && is_Debounce_Timer_Greater_1ms())
	        FirstFlag = 0;
	}

	return 0;
}

void initDigitalInput (void)
{
    //P1.5 is input
    P1DIR = P1DIR & 0b11011111;//make sure P1.5 is input

    //P1.5 is a pulldown resistor enable the Pull resistor
    P1REN = P1REN | 0x20;
    P1OUT = P1OUT & 0xDF;//make sure P1.5 is pulldown p1out xx0x xxxx
}

void initDigitalOutput (void)
{
    //P1.0 is output led
    P4DIR = P4DIR | 0b10000000;//P1DIR =  xxxx xxx1

    //P4OUT = P4OUT | 0x80;
}

void initDebounceTimer (void)
 {
   //we would set a timer for 5 sec.
   TA0CTL = TASSEL__ACLK;
   //timer0 cs ACLK,
   TA0CCR0 = 50;
   //t = COUNT*Taclk
   //faclk = 50kHz Taclk = 20us
   //1ms = Count*20us
   //1 = Count*0.02
   //Count = 1/0.02 = 50
}

void start_Debounce_Timer (void)
{
    //start the timer
    TA0CTL = TA0CTL | MC__UP;
}

void stop_Debounce_Timer (void)
{
    TA0CTL = TA0CTL & (~TAIFG);//clear flag
    TA0CTL = TA0CTL | MC__STOP;//stop timer
    TA0CTL = TA0CTL | TACLR;//reset the timer
}

int is_Button_Pressed (void)
{
    if((P1IN & BIT5) == BIT5)
        return 1;//button pressed return 1

    else if ((P1IN & BIT5) == 0)
        return 0;//button not pressed r
}

int is_Debounce_Timer_Greater_1ms (void)
{
    if((TA0CTL & TAIFG) == TAIFG)
        return 1;

    else if ((TA0CTL & TAIFG) == 0)
        return 0;
}
