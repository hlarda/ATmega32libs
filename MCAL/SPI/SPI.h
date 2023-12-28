#ifndef SPI_H
#define SPI_H

#include <stdtype.h>
#include <bitmath.h>
#include "DIO/DIO.h"
#include "SPIconfig.h"

void SPIinit    (void);
u8   SPItranseve(u8 data);


#endif