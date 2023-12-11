#include "DIO.h"
#include "DIOprivate.h"

void DIOsetPinDirection(u8 pinCpy,u8 directionCpy){
    u8 bit =pinCpy % 10;
    u8 port=pinCpy / 10;

    switch (directionCpy){
        case INPUT:
            switch (port){
                case portA: CLR_BIT(DDRA,bit);  break;
                case portB: CLR_BIT(DDRB,bit);  break;
                case portC: CLR_BIT(DDRC,bit);  break;
                case portD: CLR_BIT(DDRD,bit);  break;
                default:                        break;
            }
        break;
        case OUTPUT:
            switch (port){
                case portA: SET_BIT(DDRA,bit);  break;
                case portB: SET_BIT(DDRB,bit);  break;
                case portC: SET_BIT(DDRC,bit);  break;
                case portD: SET_BIT(DDRD,bit);  break;
                default:                        break;
            }
        break;
    }
}

void DIOsetPinValue(u8 pinCpy,u8 valueCpy){
    u8 bit =pinCpy % 10;
    u8 port=pinCpy / 10;

    switch (valueCpy){
        case LOW:
            switch (port){
                case portA: CLR_BIT(PORTA,bit); break;
                case portB: CLR_BIT(PORTB,bit); break;
                case portC: CLR_BIT(PORTC,bit); break;
                case portD: CLR_BIT(PORTD,bit); break;
                default: break;
            }
        break;
        case HIGH:
            switch (port){
                case portA: SET_BIT(PORTA,bit); break;
                case portB: SET_BIT(PORTB,bit); break;
                case portC: SET_BIT(PORTC,bit); break;
                case portD: SET_BIT(PORTD,bit); break;
                default: break;
            }
        break;
        }
}

u8 DIOgetPinValue(u8 pinCpy){
    u8 bit =pinCpy % 10;
    u8 port=pinCpy / 10;
    u8 pinValue=LOW;
    switch (port){
        case portA: pinValue = GET_BIT(PINA,bit);  break;
        case portB: pinValue = GET_BIT(PINB,bit);  break;
        case portC: pinValue = GET_BIT(PINC,bit);  break;
        case portD: pinValue = GET_BIT(PIND,bit);  break;
        default:                                   break;
    }
    return pinValue;
}

void DIOsetPortDirection(u8 portX,u8 directionCpy){
    switch (portX){
        case portA: DDRA=directionCpy;  break;
        case portB: DDRB=directionCpy;  break;
        case portC: DDRC=directionCpy;  break;
        case portD: DDRD=directionCpy;  break;
        default:                        break;
    }
}

void DIOsetPortValue(u8 portX,u8 valueCpy){
    switch (portX){
        case portA: PORTA=valueCpy;  break;
        case portB: PORTB=valueCpy;  break;
        case portC: PORTC=valueCpy;  break;
        case portD: PORTD=valueCpy;  break;
        default:                     break;
    }
}

u8 DIOgetPortValue(u8 portX){
    u8 portValue;
    switch (portX){
        case portA: portValue=PINA;  break;
        case portB: portValue=PINB;  break;
        case portC: portValue=PINC;  break;
        case portD: portValue=PIND;  break;
        default:                     break;
    }
    return portValue;
}