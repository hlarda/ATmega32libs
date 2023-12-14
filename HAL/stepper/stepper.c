#include "stepper.h"
#include "stepperConfig.h"

void stepperInit(void){
    DIOsetPinDirection(STEPPER4_ORANGE_PIN,OUTPUT_PIN);
    DIOsetPinDirection(STEPPER3_YELLOW_PIN,OUTPUT_PIN);
    DIOsetPinDirection(STEPPER1_BLUE_PIN,OUTPUT_PIN);
    DIOsetPinDirection(STEPPER2_PINK_PIN,OUTPUT_PIN);
}
void stepperWriteAngle(u8 degree){
	for(u8 angle=0; angle < degree; angle ++)
	{
        DIOsetPinLogic(STEPPER1_BLUE_PIN,  LOW_PIN);
        DIOsetPinLogic(STEPPER2_PINK_PIN,  HIGH_PIN);
        DIOsetPinLogic(STEPPER3_YELLOW_PIN,HIGH_PIN);
        DIOsetPinLogic(STEPPER4_ORANGE_PIN,HIGH_PIN);
		_delay_ms(5);
		DIOsetPinLogic(STEPPER1_BLUE_PIN,  HIGH_PIN);
        DIOsetPinLogic(STEPPER2_PINK_PIN,  LOW_PIN);
        DIOsetPinLogic(STEPPER3_YELLOW_PIN,HIGH_PIN);
        DIOsetPinLogic(STEPPER4_ORANGE_PIN,HIGH_PIN);
		_delay_ms(5);
		DIOsetPinLogic(STEPPER1_BLUE_PIN,  HIGH_PIN);
        DIOsetPinLogic(STEPPER2_PINK_PIN,  HIGH_PIN);
        DIOsetPinLogic(STEPPER3_YELLOW_PIN,LOW_PIN);
        DIOsetPinLogic(STEPPER4_ORANGE_PIN,HIGH_PIN);
		_delay_ms(5);
		DIOsetPinLogic(STEPPER1_BLUE_PIN,  HIGH_PIN);
        DIOsetPinLogic(STEPPER2_PINK_PIN,  HIGH_PIN);
        DIOsetPinLogic(STEPPER3_YELLOW_PIN,HIGH_PIN);
        DIOsetPinLogic(STEPPER4_ORANGE_PIN,LOW_PIN);
		_delay_ms(5);
        stepperStop();
	}
}
void stepperStop(void){
    DIOsetPinLogic(STEPPER1_BLUE_PIN,  HIGH_PIN);
    DIOsetPinLogic(STEPPER2_PINK_PIN,  HIGH_PIN);
    DIOsetPinLogic(STEPPER3_YELLOW_PIN,HIGH_PIN);
    DIOsetPinLogic(STEPPER4_ORANGE_PIN,HIGH_PIN);
}
