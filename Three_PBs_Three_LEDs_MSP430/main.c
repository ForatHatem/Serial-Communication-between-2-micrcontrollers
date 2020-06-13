#include <msp430.h> 
#include "Digital_Input_Output/GPIO.h"
#include "Digital_Input_Output/Debounce.h"

#define ENABLE_PINS 0xFFFE

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	PM5CTL0 = ENABLE_PINS;
	
	init_GPIO ();//set the Digital Input and Output

	while(1)
	{
	    //apply debounce code
	    if(BTN0)
	    {
	        ButtonPressedRoutine (Button0, LED0);
	    }

	    else if(!BTN0 && (BTN_pressed[Button0] == 1))
	    {
	        ButtonReleasedRoutine(Button0);
	    }

	    if(BTN1)
	    {
	        ButtonPressedRoutine(Button1, LED1);
	    }

	    else if(!BTN1 && (BTN_pressed[Button1] == 1))
	    {
	        ButtonReleasedRoutine(Button1);
	    }

	    if(BTN2)
	    {
	        ButtonPressedRoutine(Button2, LED2);
	    }

	    else if(!BTN2 && (BTN_pressed[Button2] == 1))
	    {
	        ButtonReleasedRoutine(Button2);
	    }
	}

	return 0;
}

