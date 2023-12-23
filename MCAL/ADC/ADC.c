#include"ADC.h"
#include"ADCprivate.h"
#include"ADCconfig.h"

volatile u16 ADC_ISR_value = 0;

void ADCinit(void){
        ADCsetVoltReference ();
        ADCsetPrescaler     ();
        ADCenable           ();
}

void ADCasyncStart(ADCx_t ADCx){
        ADCsetVoltReference ();
        ADCsetPrescaler     ();
        ADCenable           ();
        ADCenablrInterrupt  ();
        ADCselectChannel    (ADCx);
        ADCstartConversion  ();
}

u16 ADCread(ADCx_t ADCx){
    ADCselectChannel            (ADCx);
    ADCstartConversion              ();
    ADCwaitForConversionCompletion  ();
    return ADCL;
}

void __vector_16(void) __attribute__((signal, used, externally_visible));
void __vector_16(void) {
    ADC_ISR_value=ADCL;
}

void ADCsetVoltReference(void){
    #if     ADC_VOLT_REF == AREF
            CLR_BIT(ADMUX,REFS0);
            CLR_BIT(ADMUX,REFS1);
    #elif   ADC_VOLT_REF == AVCC_WITH_EXTERNAL_CAPACITOR_AT_AREF
            SET_BIT(ADMUX,REFS0);
            CLR_BIT(ADMUX,REFS1);
    #elif   ADC_VOLT_REF == _2_26V_WITH_EXTERNAL_CAPACITOR_AT_AREF
            SET_BIT(ADMUX,REFS0);
            SET_BIT(ADMUX,REFS1);
    #endif
}
void ADCsetPrescaler(void){
    #if     ADC_DIVISION_FACTOR == _8_ADC
            SET_BIT(ADCSRA,ADPS0);
            SET_BIT(ADCSRA,ADPS1);
            CLR_BIT(ADCSRA,ADPS2);
    #elif   ADC_DIVISION_FACTOR == _16_ADC
            CLR_BIT(ADCSRA,ADPS0);
            CLR_BIT(ADCSRA,ADPS1);
            SET_BIT(ADCSRA,ADPS2);
    #elif   ADC_DIVISION_FACTOR == _32_ADC
            SET_BIT(ADCSRA,ADPS0);
            CLR_BIT(ADCSRA,ADPS1);
            SET_BIT(ADCSRA,ADPS2);
    #elif   ADC_DIVISION_FACTOR == _64_ADC
            CLR_BIT(ADCSRA,ADPS0);
            SET_BIT(ADCSRA,ADPS1);
            SET_BIT(ADCSRA,ADPS2);
    #elif   ADC_DIVISION_FACTOR == _128_ADC
            SET_BIT(ADCSRA,ADPS0);
            SET_BIT(ADCSRA,ADPS1);
            SET_BIT(ADCSRA,ADPS2);
    #endif
}
void ADCenable(void){
    SET_BIT(ADCSRA,ADEN);
}
void ADCdisable(void){
    CLR_BIT(ADCSRA,ADEN);
}
void ADCselectChannel(ADCx_t ADCx){
    ADMUX = (ADMUX & CLR_FIRST_3_BITS) | ADCx;
}
void ADCstartConversion(void){
    SET_BIT(ADCSRA,ADSC);
}
void ADCwaitForConversionCompletion(void){
    while (!GET_BIT(ADCSRA,ADIF));
    /*clr flag*/
    SET_BIT(ADCSRA,ADIF);
}
void ADCenablrInterrupt(void){
        SET_BIT(ADCSRA,ADIE);
}