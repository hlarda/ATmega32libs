#ifndef DIO_H
#define DIO_H

#include"stdtype.h"
#include"bitmath.h"

typedef enum{
    PA0 = 10, PA1, PA2, PA3, PA4, PA5, PA6, PA7, 
    PB0 = 20, PB1, PB2, PB3, PB4, PB5, PB6, PB7, 
    PC0 = 30, PC1, PC2, PC3, PC4, PC5, PC6, PC7, 
    PD0 = 40, PD1, PD2, PD3, PD4, PD5, PD6, PD7
}portPin_t;

typedef enum{
    INPUT_PIN=0,
    OUTPUT_PIN
}pinDirection_t;

typedef enum{
    LOW_PIN=0,
    HIGH_PIN
}pinLogic_t;

typedef enum{
    LOW_REG = 0x00,
    HIGH_REG= 0xFF
}registerLogic_t;

typedef enum{
    INPUT_REG = 0x00,
    OUTPUT_REG= 0xFF
}registerDirection_t;

typedef enum{
    portA=1,
    portB,
    portC,
    portD
}portX_t;

typedef enum{
    DISABLE=0,
    ENABLE
}pullUpResState_t;

void        DIOsetPinDirection(portPin_t portPin,pinDirection_t direction);
void        DIOsetPinLogic    (portPin_t portPin,pinLogic_t logic);
pinLogic_t  DIOgetPinLogic    (portPin_t portPin);
void   DIOsetPinPullUpResistor(portPin_t portPin,pullUpResState_t state);

void            DIOsetPortDirection(portX_t portX,registerDirection_t direction);
void            DIOsetPortLogic    (portX_t portX,registerLogic_t logic);
registerLogic_t DIOgetPortLogic    (portX_t portX);


#endif