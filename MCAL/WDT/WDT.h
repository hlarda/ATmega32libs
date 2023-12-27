#ifndef WDT_h
#define WDT_h

#include<stdtype.h>
#include<bitmath.h>

typedef enum WDTprescalar_t{
    _16_3_ms=0,
    _32_5_ms,
    _65_ms,
    _0_13_s,
    _0_26_s,
    _0_52_s,
    _1_s,
    _2_1_s
}WDTprescalar_t;

void WDTenable(WDTprescalar_t WDTprescalar);
void WDTdisenable(void);
#endif