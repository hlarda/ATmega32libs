#ifndef TIMER_H
#define TIMER_H

#include<stdtype.h>
#include<bitmath.h>
#include"timerConfig.h"

typedef enum Timerx_t{
    TIMER0,
    TIMER1,
    TIMER2
}Timerx_t;

void timerInit(Timerx_t TIMERX);
void timerSet_ms(Timerx_t TIMERX,u16 time_ms);
void timerSetCallback(Timerx_t TIMERX,void(*timerCallbackPtr)(void));

#endif