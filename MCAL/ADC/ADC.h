#ifndef ADC_H
#define ADC_H

#include<stdtype.h>
#include<bitmath.h>

typedef enum ADCx_t{
    ADC0,
    ADC1,
    ADC2,
    ADC3,
    ADC4,
    ADC5,
    ADC6,
    ADC7
}ADCx_t;

extern volatile u16 ADC_ISR_value;

void ADCinit(void);
void ADCasyncStart(ADCx_t ADCx);
u16  ADCread(ADCx_t ADCx);
#endif