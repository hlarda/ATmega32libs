#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

#define AREF                                    0
#define AVCC_WITH_EXTERNAL_CAPACITOR_AT_AREF    1
#define RESERVED                                2
#define _2_26V_WITH_EXTERNAL_CAPACITOR_AT_AREF  3
#define ADC_VOLT_REF   AVCC_WITH_EXTERNAL_CAPACITOR_AT_AREF

/*frq should be [50,200k] in our case 8000000/64<200*/
#define _8_ADC          0
#define _16_ADC         1
#define _32_ADC         2
#define _64_ADC         3
#define _128_ADC        4   
#define ADC_DIVISION_FACTOR           _64_ADC

#endif