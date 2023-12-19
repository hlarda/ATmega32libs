#include"ADC.h"
#include"ADCprivate.h"

void ADCinit(void){
    ADCsetVoltReference ();
    ADCsetPrescaler     ();
    ADCenable           ();
}
u16  ADCread(ADCx_t ADCx){

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