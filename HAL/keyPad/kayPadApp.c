#include "LCD/LCD.h"
#include"keyPad/keyPad.h"

int main(void) {
    u8 num=0;

    LCDinit();
    keyPadInit();

    while (1) {
        num=keyPadRead();
        if(num != KEYPAD_NOT_PRESSED)
		{
			LCDwriteCharacter(num);
		}
    }

    return 0;
}
