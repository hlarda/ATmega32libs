#include"keyPad.h"

void keyPadInit(void){
    DIOsetPinDirection(KEYPAD_R0,OUTPUT_PIN);
    DIOsetPinDirection(KEYPAD_R1,OUTPUT_PIN);
    DIOsetPinDirection(KEYPAD_R2,OUTPUT_PIN);
    DIOsetPinDirection(KEYPAD_R3,OUTPUT_PIN);

    DIOsetPinLogic(KEYPAD_R0,HIGH_PIN);
    DIOsetPinLogic(KEYPAD_R1,HIGH_PIN);
    DIOsetPinLogic(KEYPAD_R2,HIGH_PIN);
    DIOsetPinLogic(KEYPAD_R3,HIGH_PIN);

    DIOsetPinDirection(KEYPAD_C0,INPUT_PIN);
    DIOsetPinDirection(KEYPAD_C1,INPUT_PIN);
    DIOsetPinDirection(KEYPAD_C2,INPUT_PIN);
    DIOsetPinDirection(KEYPAD_C3,INPUT_PIN);
    
    DIOsetPinPullUpResistor(KEYPAD_C0,ENABLE);        
    DIOsetPinPullUpResistor(KEYPAD_C1,ENABLE);    
    DIOsetPinPullUpResistor(KEYPAD_C2,ENABLE);    
    DIOsetPinPullUpResistor(KEYPAD_C3,ENABLE);
}

u8 keyPadRead(void){
    u8 reading=1,   col=0,  row=0;
    for (row = KEYPAD_R0; row <= KEYPAD_R3; row++){
        DIOsetPinLogic(row,LOW_PIN);
        for (col = KEYPAD_C0; col <= KEYPAD_C3; col++){
            if (DIOgetPinLogic(col) == KEYPAD_PRESSED){
                _delay_ms(120);
                if (DIOgetPinLogic(col) == KEYPAD_PRESSED){
                    while (DIOgetPinLogic(col) == KEYPAD_PRESSED);
                    reading = keyPadLayout[row-KEYPAD_R0][col-KEYPAD_C0];
                    break;
                }
            }
        }
        DIOsetPinLogic(row,HIGH_PIN);
    }
    return reading;
}