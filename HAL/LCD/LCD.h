#ifndef LCD_H
#define LCD_H

#include <util/delay.h>

#include"DIO/DIO.h"
#include"LCDconfig.h"

void LCDinit             (void);
void LCDwriteCharacter   (u8 character);
void LCDwriteCommand     (u8 cmd);
void LCDwriteString      (u8* string);
void LCDclear            (void);
void LCDwriteSignedNumber(s32 num);
void LCDgoTo             (u8 row,u8 col);

#endif