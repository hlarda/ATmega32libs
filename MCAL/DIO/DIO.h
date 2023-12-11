#ifndef DIO_H
#define DIO_H

#include"stdtype.h"
#include"bitmath.h"
#include "DIOconfig.h"

#define PA0                 10
#define PA1                 11
#define PA2                 12
#define PA3                 13
#define PA4                 14
#define PA5                 15
#define PA6                 16
#define PA7                 17

#define PB0                 20
#define PB1                 21
#define PB2                 22
#define PB3                 23
#define PB4                 24
#define PB5                 25
#define PB6                 26
#define PB7                 27

#define PC0                 30
#define PC1                 31
#define PC2                 32
#define PC3                 33
#define PC4                 34
#define PC5                 35
#define PC6                 36
#define PC7                 37

#define PD0                 40
#define PD1                 41
#define PD2                 42
#define PD3                 43
#define PD4                 44
#define PD5                 45
#define PD6                 46
#define PD7                 47

#define INPUT               0
#define OUTPUT              1

#define LOW                 0
#define HIGH                1

#define LOW_REG             0x00
#define HIGH_REG            0xFF

#define INPUT_REG           0x00
#define OUTPUT_REG          0xFF

#define portA               1
#define portB               2
#define portC               3
#define portD               4

void DIOsetPinDirection(u8 pinCpy,u8 directionCpy);
void DIOsetPinValue    (u8 pinCpy,u8 valueCpy);
u8   DIOgetPinValue    (u8 pinCpy);

void DIOsetPortDirection(u8 portX,u8 directionCpy);
void DIOsetPortValue    (u8 portX,u8 valueCpy);
u8   DIOgetPortValue    (u8 portX);


#endif