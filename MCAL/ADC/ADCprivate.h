#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include"ADC.h"

#define ADMUX           (*((volatile u8*)0x27))
#define MUX0            0
#define MUX1            1
#define MUX2            2

#define ADLAR           5
#define REFS0           6
#define REFS1           7

#define ADCSRA          (*((volatile u8*)0x26))
#define ADPS0           0
#define ADPS1           1
#define ADPS2           2

#define ADIE            3
#define ADIF            4

#define ADATE           5
#define ADSC            6
#define ADEN            7

//#define ADCL            (*((volatile u8*)0x24))
//#define ADCH            (*((volatile u8*)0x25))

#define ADCL            (*((volatile u16*)0x24))

#define CLR_FIRST_3_BITS 0xF8

#define TRUE        1
#define FALSE       0

void ADCsetVoltReference(void);
void ADCsetPrescaler    (void);
void ADCenable          (void);
void ADCdisable         (void);
void ADCenablrInterrupt(void);

void ADCselectChannel               (ADCx_t ADCx);
void ADCstartConversion             (void);
void ADCwaitForConversionCompletion (void);

#endif