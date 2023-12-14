#ifndef STEPPER_H
#define STEPPER_H

#include "DIO/DIO.h"
#include <util/delay.h>

void stepperInit(void);
void stepperWriteAngle(u8 degree);
void stepperStop(void);


#endif