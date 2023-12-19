#include"INT.h"
#include"intPrivate.h"

void (*exInt0Callback)(void);
void (*exInt1Callback)(void);
void (*exInt2Callback)(void);

void ExIntInit(ExtIntChannels_t INTX){
    switch (INTX){
        case INT0:
                #if     INT0_SENSE_CONTROL == LOW_LEVEL
                        CLR_BIT(MCUCR,MCUCR_ISC00);
                        CLR_BIT(MCUCR,MCUCR_ISC01);
                #elif   INT0_SENSE_CONTROL == ANY_CHANGE
                        SET_BIT(MCUCR,MCUCR_ISC00);
                        CLR_BIT(MCUCR,MCUCR_ISC01);
                #elif   INT0_SENSE_CONTROL == FALLING_EDGE
                        CLR_BIT(MCUCR,MCUCR_ISC00);
                        SET_BIT(MCUCR,MCUCR_ISC01);
                #elif   INT0_SENSE_CONTROL == RISING_EDGE
                        SET_BIT(MCUCR,MCUCR_ISC00);
                        SET_BIT(MCUCR,MCUCR_ISC01);
                #else
                    #error "invalid sense control option"
                #endif
                SET_BIT(GICR,GICR_INT0_EN);
                break;
        case INT1:
                #if     INT1_SENSE_CONTROL == LOW_LEVEL
                        CLR_BIT(MCUCR,MCUCR_ISC10);
                        CLR_BIT(MCUCR,MCUCR_ISC11);
                #elif   INT1_SENSE_CONTROL == ANY_CHANGE
                        SET_BIT(MCUCR,MCUCR_ISC10);
                        CLR_BIT(MCUCR,MCUCR_ISC11);
                #elif   INT1_SENSE_CONTROL == FALLING_EDGE
                        CLR_BIT(MCUCR,MCUCR_ISC10);
                        SET_BIT(MCUCR,MCUCR_ISC11);
                #elif   INT1_SENSE_CONTROL == RISING_EDGE
                        SET_BIT(MCUCR,MCUCR_ISC10);
                        SET_BIT(MCUCR,MCUCR_ISC11);
                #else
                    #error "invalid sense control option"
                #endif
                SET_BIT(GICR,GICR_INT1_EN);
                break;
        case INT2:
                #if     INT2_SENSE_CONTROL == FALLING_EDGE
                        CLR_BIT(MCUCSR,MCUCSR_ISC2);
                #elif   INT2_SENSE_CONTROL == RISING_EDGE
                        SET_BIT(MCUCSR,MCUCSR_ISC2);
                #else
                    #error "invalid sense control option"
                #endif
                SET_BIT(GICR,GICR_INT2_EN);
                break;
        default:                                   break;
    }
}
void ExIntInitSetCallback(ExtIntChannels_t INTX,void(*exIntCallbackPtr)(void)){
        switch(INTX){
        case INT0:      exInt0Callback = exIntCallbackPtr;       break;
        case INT1:      exInt1Callback = exIntCallbackPtr;       break;
        case INT2:      exInt2Callback = exIntCallbackPtr;       break;
        default:                                                 break;
        }
}
ISR(INT0_vect)  { if (exInt0Callback != NULL) { exInt0Callback(); } }
ISR(INT1_vect)  { if (exInt1Callback != NULL) { exInt0Callback(); } }
ISR(INT2_vect)  { if (exInt2Callback != NULL) { exInt0Callback(); } }