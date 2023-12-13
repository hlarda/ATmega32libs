#ifndef KEYPAD_H
#define KEYPAD_H

#include"DIO/DIO.h"
#include"keyPad/keyPadConfig.h"
#include <util/delay.h>

typedef enum KEYPAD_STATE_T{
    KEYPAD_PRESSED = 0
}KEYPAD_STATE_T;

u8 keyPadLayout [4][4] = {{ '7' , '8' , '9' , '+' },
			              { '4' , '5' , '6' , '-' },
						  { '1' , '2' , '3' , '*' },
						  { 'C' , '0' , '=' , '/' }};
                          
void keyPadInit(void);
u8 keyPadRead(void);

#endif