#include <GINT/GINT.h>
#include <INT/INT.h>
#include <DIO/DIO.h>

void int0Callback(void);
void int1Callback(void);
void int2Callback(void);

int main() {
    ExIntInitSetCallback(INT0, int0Callback);
    ExIntInitSetCallback(INT1, int1Callback);
    ExIntInitSetCallback(INT2, int2Callback);

    DIOsetPinDirection(PA0,OUTPUT_PIN);
    DIOsetPinDirection(PA1,OUTPUT_PIN);
    DIOsetPinDirection(PA2,OUTPUT_PIN);
    
    DIOsetPinDirection(PD2,INPUT_PIN);
    DIOsetPinDirection(PD3,INPUT_PIN);
    DIOsetPinDirection(PB2,INPUT_PIN);

    DIOsetPinPullUpResistor(PD2,ENABLE);
    DIOsetPinPullUpResistor(PD3,ENABLE);
    DIOsetPinPullUpResistor(PB2,ENABLE);

    ExIntInit(INT0);
    ExIntInit(INT1);
    ExIntInit(INT2);
    globalInterruptEnable();

    while (1) {
    }

    return 0;
}
void int0Callback(void) {
    DIOsetPinLogic(PA0,HIGH_PIN);
}

void int1Callback(void) {
    DIOsetPinLogic(PA1,HIGH_PIN);
}

void int2Callback(void) {
    DIOsetPinLogic(PA2,HIGH_PIN);
}
