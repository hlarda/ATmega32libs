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

