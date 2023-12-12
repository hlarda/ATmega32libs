#include"SSD.h"
int digitsArr[10][7]={{1,1,1,1,1,1,0},     /*0*/
                   {0,1,1,0,0,0,0},     /*1*/
                   {1,1,0,1,1,0,1},     /*2*/
                   {1,1,1,1,0,0,1},     /*3*/
                   {0,1,1,0,0,1,1},     /*4*/
                   {1,0,1,1,0,1,1},     /*5*/
                   {1,0,1,1,1,1,1},     /*6*/
                   {1,1,1,0,0,0,0},     /*7*/
                   {1,1,1,1,1,1,1},     /*8*/
                   {1,1,1,1,0,1,1}};    /*9*/

void SSDinit(SSD_t *SSD){
    for (int i = 0; i < 7; i++)
    {
        DIOsetPinDirection(SSD->SSDpins[i],OUTPUT_PIN);
    }
    switch (SSD->connection){
        case SSD_COMMON_CATHODE:
            for (int i = 0; i < 7; i++){
                DIOsetPinLogic(SSD->SSDpins[i],LOW_PIN);
            }
            break;
        case SSD_COMMON_ANODE:
            for (int i = 0; i < 7; i++){
                DIOsetPinLogic(SSD->SSDpins[i],HIGH_PIN);
            }
            break;
        default:                                  break;
    }
}

void SSD1digit(SSD_t *SSD , u8 _1digit){
    switch (SSD->connection){
        case SSD_COMMON_CATHODE:
            for (int i = 0; i < 7; i++){
                DIOsetPinLogic(SSD->SSDpins[i],digitsArr[_1digit][i]);
            }
            break;
        case SSD_COMMON_ANODE:
            for (int i = 0; i < 7; i++){
                DIOsetPinLogic(SSD->SSDpins[i],!digitsArr[_1digit][i]);
            }
            break;
        default:                                  break;
    }
}

void SSD2digits(SSD_t *SSD, u8 _2digits) {
    DIOsetPinDirection(LEFT_DIGIT_EN, OUTPUT_PIN);
    DIOsetPinDirection(RIGHT_DIGIT_EN, OUTPUT_PIN);

    u8 leftDigit = _2digits / 10;
    u8 rightDigit = _2digits % 10;

    switch (SSD->connection) {
        case SSD_COMMON_CATHODE:
            for (int duration = 0; duration < 500; duration++) {
                for (int i = 0; i < 7; i++) {
                    DIOsetPinLogic(SSD->SSDpins[i], digitsArr[leftDigit][i]);
                }
                DIOsetPinLogic(LEFT_DIGIT_EN, HIGH_PIN);
                _delay_ms(1);
                DIOsetPinLogic(LEFT_DIGIT_EN, LOW_PIN);

                for (int i = 0; i < 7; i++) {
                    DIOsetPinLogic(SSD->SSDpins[i], digitsArr[rightDigit][i]);
                }
                DIOsetPinLogic(RIGHT_DIGIT_EN, HIGH_PIN);
                _delay_ms(1);
                DIOsetPinLogic(RIGHT_DIGIT_EN, LOW_PIN);
            }
            break;

        case SSD_COMMON_ANODE:
            for (int duration = 0; duration < 500; duration++) {
                for (int i = 0; i < 7; i++) {
                    DIOsetPinLogic(SSD->SSDpins[i], !digitsArr[leftDigit][i]);
                }
                DIOsetPinLogic(LEFT_DIGIT_EN, LOW_PIN);
                _delay_ms(5);
                DIOsetPinLogic(LEFT_DIGIT_EN, HIGH_PIN);

                for (int i = 0; i < 7; i++) {
                    DIOsetPinLogic(SSD->SSDpins[i], !digitsArr[rightDigit][i]);
                }
                DIOsetPinLogic(RIGHT_DIGIT_EN, LOW_PIN);
                _delay_ms(5);
                DIOsetPinLogic(RIGHT_DIGIT_EN, HIGH_PIN);
            }
            break;

        default:
            break;
    }
}
