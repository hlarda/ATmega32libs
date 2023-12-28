#ifndef SPI_H
#define SPI_H

#include <stdtype.h>
#include <bitmath.h>
#include "DIO/DIO.h"
#include "SPIconfig.h"

volatile u8 SPIreseviedData;

void SPIinit    (void);
u8   SPItranseve(u8 data);
void SPItranmit (u8 data);



#endif