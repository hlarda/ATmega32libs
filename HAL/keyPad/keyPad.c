#include"keyPad.h"

u8 keyPadLayout [4][4] = {{ '7' , '8' , '9' , '/' },
			              { '4' , '5' , '6' , '*' },
						  { '1' , '2' , '3' , '-' },
						  { 'C' , '0' , '=' , '+' }};

void keyPadInit(void){
    DIOsetPinDirection(KEYPAD_C0,OUTPUT_PIN);
    DIOsetPinDirection(KEYPAD_C1,OUTPUT_PIN);
    DIOsetPinDirection(KEYPAD_C2,OUTPUT_PIN);
    DIOsetPinDirection(KEYPAD_C3,OUTPUT_PIN);

    DIOsetPinDirection(KEYPAD_R0,INPUT_PIN);
    DIOsetPinDirection(KEYPAD_R1,INPUT_PIN);
    DIOsetPinDirection(KEYPAD_R2,INPUT_PIN);
    DIOsetPinDirection(KEYPAD_R3,INPUT_PIN);

    DIOsetPinPullUpResistor(KEYPAD_R0,ENABLE);        
    DIOsetPinPullUpResistor(KEYPAD_R1,ENABLE);    
    DIOsetPinPullUpResistor(KEYPAD_R2,ENABLE);    
    DIOsetPinPullUpResistor(KEYPAD_R3,ENABLE);

    DIOsetPinLogic(KEYPAD_C0,HIGH_PIN);
    DIOsetPinLogic(KEYPAD_C1,HIGH_PIN);
    DIOsetPinLogic(KEYPAD_C2,HIGH_PIN);
    DIOsetPinLogic(KEYPAD_C3,HIGH_PIN);
}

u8 keyPadRead(void){
    u8 reading=KEYPAD_NOT_PRESSED;
    u8 col,  row;
    u8 flag=0;
    for (col = KEYPAD_C0; col <= KEYPAD_C3; col++){
        DIOsetPinLogic(col,LOW_PIN);
        for (row = KEYPAD_R0; row <= KEYPAD_R3; row++){
            if (DIOgetPinLogic(row) == LOW_PIN){
                reading = keyPadLayout[row-KEYPAD_R0][col-KEYPAD_C0];
                    while (DIOgetPinLogic(row) == LOW_PIN);
                    flag=1;
                    break;
            }else{
            }
        }
        if (flag==1)
        {
            break;
        }
        DIOsetPinLogic(col,HIGH_PIN);
    }
    return reading;
}