#ifndef INT_H
#define INT_H

#include<bitmath.h>
#include<stdtype.h>
#include"intConfig.h"

typedef enum ExtIntChannels_t{
    INT0,
    INT1,
    INT2
}ExtIntChannels_t;

void ExIntInit(ExtIntChannels_t INTX);
#endif