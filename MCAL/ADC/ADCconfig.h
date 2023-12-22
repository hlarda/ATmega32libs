#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

typedef enum ADCvoltRefernce_t{
    AREF,
    AVCC_WITH_EXTERNAL_CAPACITOR_AT_AREF,
    RESERVED,
    _2_26V_WITH_EXTERNAL_CAPACITOR_AT_AREF
}ADCvoltRefernce_t;
#define ADC_VOLT_REF                  AREF

typedef enum ADCprescaler_t{
    _8_,
    _16_,
    _32_,
    _64_,
    _128_
}ADCprescaler_t;
/*frq should be [50,200k] in our case 8000000/64<200*/
#define ADC_DIVISION_FACTOR           _64_

#endif