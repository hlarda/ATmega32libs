#include "LCD/LCD.h"

int main(void) {
    LCDinit();
    LCDwriteString("Hello, LCD!");
    
    LCDgoTo(1, 0);

    s32 number = -12345;
    LCDwriteSignedNumber(number);

    _delay_ms(700);

    LCDclear();

    LCDwriteString("LCD Cleared!");

    while (1) {
    }

    return 0;
}
