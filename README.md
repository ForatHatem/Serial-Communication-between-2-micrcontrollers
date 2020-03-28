# Serial-Communication-between-2-micrcontrollers
Two microcontrollers (MSP430, PIC24F) communicate with each other via UART, SPI, or I2C, three push buttons are connected to the MSP430, 
and three LEDs are connected to the PIC24F.

When a button is pressed at the MSP430, it will send a signal to the PIC24F of which LED to toggle. 
The PIC24F will send a signal to the MSP430 of which LEDs are ON or OFF.

There will a toggle button at the MSP430 which would allow us to change the communication protocol between the two microcontrollers.

Additionally there the microcontrollers will each have an LCD screen, at the MSP430 the LCD will display which LED on the PIC24F side is ON or OFF, what is 
the current communication protocol.
At the PIC24F side, the LCD will dislay which LED is ON or OFF, the total power consumed, the power consumed by each LED, the total time for each
LED when it was turned ON. These display modes will be toggled by a push button connected to the PIC24F.





