#include "DIO.h"
#include "DIOprivate.h"

void DIOsetPinDirection(portPin_t portPin,pinDirection_t direction){
    u8      bit =portPin % 10;
    portX_t port=portPin / 10;

    switch (direction){
        case INPUT_PIN:
            switch (port){
                case portA: CLR_BIT(DDRA,bit);  break;
                case portB: CLR_BIT(DDRB,bit);  break;
                case portC: CLR_BIT(DDRC,bit);  break;
                case portD: CLR_BIT(DDRD,bit);  break;
                default:                        break;
            }
        break;
        case OUTPUT_PIN:
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

void DIOsetPinLogic    (portPin_t portPin,pinLogic_t logic){
    u8      bit =portPin % 10;
    portX_t port=portPin / 10;

    switch (logic){
        case LOW_PIN:
            switch (port){
                case portA: CLR_BIT(PORTA,bit); break;
                case portB: CLR_BIT(PORTB,bit); break;
                case portC: CLR_BIT(PORTC,bit); break;
                case portD: CLR_BIT(PORTD,bit); break;
                default:                        break;
            }
        break;
        case HIGH_PIN:
            switch (port){
                case portA: SET_BIT(PORTA,bit); break;
                case portB: SET_BIT(PORTB,bit); break;
                case portC: SET_BIT(PORTC,bit); break;
                case portD: SET_BIT(PORTD,bit); break;
                default:                        break;
            }
        break;
        }
}

pinLogic_t DIOgetPinLogic(portPin_t portPin){
    u8      bit =portPin % 10;
    portX_t port=portPin / 10;
    u8 pinLogic=LOW_PIN;
    switch (port){
        case portA: pinLogic = GET_BIT(PINA,bit);  break;
        case portB: pinLogic = GET_BIT(PINB,bit);  break;
        case portC: pinLogic = GET_BIT(PINC,bit);  break;
        case portD: pinLogic = GET_BIT(PIND,bit);  break;
        default:                                   break;
    }
    return pinLogic;
}

void DIOsetPortDirection(portX_t portX,registerDirection_t directionCpy){
    switch (portX){
        case portA: DDRA=directionCpy;  break;
        case portB: DDRB=directionCpy;  break;
        case portC: DDRC=directionCpy;  break;
        case portD: DDRD=directionCpy;  break;
        default:                        break;
    }
}

void DIOsetPortLogic(portX_t portX,registerLogic_t logic){
    switch (portX){
        case portA: PORTA=logic;  break;
        case portB: PORTB=logic;  break;
        case portC: PORTC=logic;  break;
        case portD: PORTD=logic;  break;
        default:                     break;
    }
}

registerLogic_t DIOgetPortLogic (portX_t portX){
    registerLogic_t portLogic;
    switch (portX){
        case portA: portLogic=PINA;  break;
        case portB: portLogic=PINB;  break;
        case portC: portLogic=PINC;  break;
        case portD: portLogic=PIND;  break;
        default:                     break;
    }
    return portLogic;
}