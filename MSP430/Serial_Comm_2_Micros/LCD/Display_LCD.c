#include <msp430.h>
#include "Display_LCD.h"

const char digits[][2] =
{
    {0xFC, 0x28},  /* "0" LCD segments a+b+c+d+e+f+k+q */
    {0x60, 0x20},  /* "1" */
    {0xDB, 0x00},  /* "2" */
    {0xF3, 0x00},  /* "3" */
    {0x67, 0x00},  /* "4" */
    {0xB7, 0x00},  /* "5" */
    {0xBF, 0x00},  /* "6" */
    {0xE4, 0x00},  /* "7" */
    {0xFF, 0x00},  /* "8" */
    {0xF7, 0x00}   /* "9" */
};

const char alphabets[][2] =
{
    {0xEF, 0x00},  /* "A" LCD segments a+b+c+e+f+g+m */
    {0xF1, 0x50},  /* "B" */
    {0x9C, 0x00},  /* "C" */
    {0xF0, 0x50},  /* "D" */
    {0x9F, 0x00},  /* "E" */
    {0x8F, 0x00},  /* "F" */
    {0xBD, 0x00},  /* "G" */
    {0x6F, 0x00},  /* "H" */
    {0x90, 0x50},  /* "I" */
    {0x78, 0x00},  /* "J" */
    {0x0E, 0x22},  /* "K" */
    {0x1C, 0x00},  /* "L" */
    {0x6C, 0xA0},  /* "M" */
    {0x6C, 0x82},  /* "N" */
    {0xFC, 0x00},  /* "O" */
    {0xCF, 0x00},  /* "P" */
    {0xFC, 0x02},  /* "Q" */
    {0xCF, 0x02},  /* "R" */
    {0xB7, 0x00},  /* "S" */
    {0x80, 0x50},  /* "T" */
    {0x7C, 0x00},  /* "U" */
    {0x0C, 0x28},  /* "V" */
    {0x6C, 0x0A},  /* "W" */
    {0x00, 0xAA},  /* "X" */
    {0x00, 0xB0},  /* "Y" */
    {0x90, 0x28},   /* "Z" */
};

void show_Char(unsigned char ch, unsigned int pos)
{
    char AX [2];


    if(ch >= '0' && ch <= '9')//'0' = 48 '9' = 57
    {
        AX[0] = digits[(unsigned int)ch - 48][0];
        AX[1] = digits[(unsigned int)ch - 48][1];
    }

    else if(ch >= 'A' && ch <= 'Z')
    {
        AX[0] = alphabets[(unsigned int)ch - 65][0];
        AX[1] = alphabets[(unsigned int)ch - 65][1];
    }

    else if(ch == ' ')
    {
        AX[0] = 0x00;
        AX[1] = 0x00;
    }

    switch(pos)
    {
    case 1:
        A1_1 = AX[0];
        A1_2 = AX[1];
        break;
    case 2:
        A2_1 = AX[0];
        A2_2 = AX[1];
        break;
    case 3:
        A3_1 = AX[0];
        A3_2 = AX[1];
        break;
    case 4:
        A4_1 = AX[0];
        A4_2 = AX[1];
        break;
    case 5:
        A5_1 = AX[0];
        A5_2 = AX[1];
        break;
    case 6:
        A6_1 = AX[0];
        A6_2 = AX[1];
        break;
    default:
        break;
    }
}

void show_String(char*str)
{
    //get the size of the string
    unsigned int str_length = strlen(str);
    int i;

    if(str_length <= 6)
    {
        for(i = 0; i < str_length; ++i)
            show_Char(str[i],i+1);
    }

    else
    {
        show_Char('E',1);
        show_Char('R',2);
        show_Char('R',3);
        show_Char('O',4);
        show_Char('R',5);
    }
}


void displayHelloMsg (void)
{
    show_String("HELLO");
}
