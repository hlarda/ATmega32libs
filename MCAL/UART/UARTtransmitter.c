#include <UART/UART.h>
#include <LCD/LCD.h>
/******transmitter*******/

int main() {
    UARTinit();
    LCDinit();

    char string[] = "I see u";
    LCDwriteString(string);
    int index = 0; 
    while (string[index] != '\0') {
        UARTsend(string[index]);
        index++;
        _delay_us(103);
    }
    
    //LCDwriteCharacter('h');
    //UARTsend('h');
    //LCDwriteCharacter('a');
    //UARTsend('a');

    while (1) {
    }

    return 0;
}