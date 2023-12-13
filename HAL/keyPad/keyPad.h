#ifndef KEYPAD_H
#define KEYPAD_H

#include"DIO/DIO.h"
#include"keyPad/keyPadConfig.h"
#include <util/delay.h>

#define KEYPAD_NOT_PRESSED      0xff
                          
void keyPadInit(void);
u8 keyPadRead(void);

#endif