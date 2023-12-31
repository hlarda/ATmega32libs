#include <UART/UART.h>
#include <LCD/LCD.h>
/**********recevicer******************/
int main() {
    UARTinit();
    LCDinit();

    u8 receivedString[7];
    for (u8 i = 0; i < 7; i++){
        receivedString[i]=UARTreceive();
    }
    LCDwriteString(receivedString);
    //u8 data=UARTreceive();
    //LCDwriteCharacter(data);
    //LCDgoTo(1,0);
    //u8 dataa=UARTreceive();
    //LCDwriteCharacter(dataa);
    while (1) {
    }

    return 0;
}
