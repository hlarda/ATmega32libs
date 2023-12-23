#include <GINT/GINT.h>
#include <timer/timer.h>
#include <DIO/DIO.h>

void action(void);

int main() {
    DIOsetPinDirection(PA0,OUTPUT_PIN);
    DIOsetPinLogic(PA0,LOW_PIN);
    timerSetCallback(TIMER0, action); 
    timerInit(TIMER0);
    timerSet_ms(TIMER0, 2000); 
    globalInterruptEnable();
    while (1) {
    }

    return 0;
}
void action(void){
    if (DIOgetPinLogic(PA0))
    {
        DIOsetPinLogic(PA0,LOW_PIN);
    }else
    {
        DIOsetPinLogic(PA0,HIGH_PIN);
    }
}
