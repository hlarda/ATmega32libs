#include"INT.h"
#include"intPrivate.h"

void ExIntInit(ExtIntChannels_t INTX){
    switch (INTX)
    {
        case INT0:
            #if     INT0_SENSE == LOW_LEVEL
                    CLR_BIT(MCUCR,MCUCR_ISC00);
                    CLR_BIT(MCUCR,MCUCR_ISC01);
            #elif   INT0_SENSE == ANY_CHANGE
                    SET_BIT(MCUCR,MCUCR_ISC00);
                    CLR_BIT(MCUCR,MCUCR_ISC01);
            #elif   INT0_SENSE == FALLING_EDGE
                    CLR_BIT(MCUCR,MCUCR_ISC00);
                    SET_BIT(MCUCR,MCUCR_ISC01);
            #elif   INT0_SENSE == RISING_EDGE
                    SET_BIT(MCUCR,MCUCR_ISC00);
                    SET_BIT(MCUCR,MCUCR_ISC01);
            #else
                #error "invalid sense control option"
            #endif
        break;

        case INT1:
            #if     INT1_SENSE == LOW_LEVEL
                    CLR_BIT(MCUCR,MCUCR_ISC10);
                    CLR_BIT(MCUCR,MCUCR_ISC11);
            #elif   INT1_SENSE == ANY_CHANGE
                    SET_BIT(MCUCR,MCUCR_ISC10);
                    CLR_BIT(MCUCR,MCUCR_ISC11);
            #elif   INT1_SENSE == FALLING_EDGE
                    CLR_BIT(MCUCR,MCUCR_ISC10);
                    SET_BIT(MCUCR,MCUCR_ISC11);
            #elif   INT1_SENSE == RISING_EDGE
                    SET_BIT(MCUCR,MCUCR_ISC10);
                    SET_BIT(MCUCR,MCUCR_ISC11);
            #else
                #error "invalid sense control option"
            #endif
        break;
        case INT2:
            #if     INT2_SENSE == FALLING_EDGE
                    CLR_BIT(MCUCSR,MCUCSR_ISC2);
            #elif   INT2_SENSE == RISING_EDGE
                    SET_BIT(MCUCSR,MCUCSR_ISC2);
            #else
                #error "invalid sense control option"
            #endif
        break;
        default:                break;
    }
}
