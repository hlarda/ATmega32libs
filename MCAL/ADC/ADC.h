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

void ADCinit(void);
u16  ADCread(ADCx_t ADCx);
#endif