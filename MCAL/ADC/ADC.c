#include"ADC.h"
#include"ADCprivate.h"

void ADCinit(void){
     ADCsetVoltReference ();
     ADCsetPrescaler     ();
     ADCenable           ();
}

u16 ADCread(ADCx_t ADCx){
    ADCselectChannel            (ADCx);
    ADCstartConversion              ();
    ADCwaitForConversionCompletion  ();
    return ADCmergeDataRegisters    ();
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
    #if     ADC_DIVISION_FACTOR == _8_
            SET_BIT(ADCSRA,ADPS0);
            SET_BIT(ADCSRA,ADPS1);
            CLR_BIT(ADCSRA,ADPS2);
    #elif   ADC_DIVISION_FACTOR == _16_
            CLR_BIT(ADCSRA,ADPS0);
            CLR_BIT(ADCSRA,ADPS1);
            SET_BIT(ADCSRA,ADPS2);
    #elif   ADC_DIVISION_FACTOR == _32_
            SET_BIT(ADCSRA,ADPS0);
            CLR_BIT(ADCSRA,ADPS1);
            SET_BIT(ADCSRA,ADPS2);
    #elif   ADC_DIVISION_FACTOR == _64_
            CLR_BIT(ADCSRA,ADPS0);
            SET_BIT(ADCSRA,ADPS1);
            SET_BIT(ADCSRA,ADPS2);
    #elif   ADC_DIVISION_FACTOR == _128_
            SET_BIT(ADCSRA,ADPS0);
            SET_BIT(ADCSRA,ADPS1);
            SET_BIT(ADCSRA,ADPS2);
    #endif
}
void ADCenable(void){
    SET_BIT(ADCSRA,ADEN);
}
void ADCselectChannel(ADCx_t ADCx){
    switch (ADCx){
        case ADC0:
            CLR_BIT(ADMUX,MUX0);
            CLR_BIT(ADMUX,MUX1);
            CLR_BIT(ADMUX,MUX2);
            break;
        case ADC1:
            SET_BIT(ADMUX,MUX0);
            CLR_BIT(ADMUX,MUX1);
            CLR_BIT(ADMUX,MUX2);
            break;
        case ADC2:
            CLR_BIT(ADMUX,MUX0);
            SET_BIT(ADMUX,MUX1);
            CLR_BIT(ADMUX,MUX2);
            break;
        case ADC3:
            SET_BIT(ADMUX,MUX0);
            SET_BIT(ADMUX,MUX1);
            CLR_BIT(ADMUX,MUX2);
            break;
        case ADC4:
            CLR_BIT(ADMUX,MUX0);
            CLR_BIT(ADMUX,MUX1);
            SET_BIT(ADMUX,MUX2);
            break;
        case ADC5:
            SET_BIT(ADMUX,MUX0);
            CLR_BIT(ADMUX,MUX1);
            SET_BIT(ADMUX,MUX2);
            break;
        case ADC6:
            CLR_BIT(ADMUX,MUX0);
            SET_BIT(ADMUX,MUX1);
            SET_BIT(ADMUX,MUX2);
            break;
        case ADC7:
            SET_BIT(ADMUX,MUX0);
            SET_BIT(ADMUX,MUX1);
            SET_BIT(ADMUX,MUX2);
            break;
        default:          break;
    }
}
void ADCstartConversion(void){
    SET_BIT(ADCSRA,ADSC);
}
void ADCwaitForConversionCompletion(void){
    while (GET_BIT(ADCSRA,ADIF));
}
u16 ADCmergeDataRegisters(void){
    return ( ADCL | (u16)(ADCH << 8) );
}