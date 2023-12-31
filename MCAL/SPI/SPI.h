#ifndef SPI_H
#define SPI_H

#include <stdtype.h>
#include <bitmath.h>
#include "DIO/DIO.h"
#include "SPIconfig.h"

typedef enum SPI_t{
    MASTER=0,
    SLAVE
}SPI_t;

volatile u8 SPIreseviedData;

void SPIinit    (SPI_t MASTER_SLAVE_SELECT);
u8   SPItranseve(u8 data);
void SPItranmit (u8 data);



#endif