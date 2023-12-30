#include <DIO/DIO.h>
#include <ADC/ADC.h> 
#include <GINT/GINT.h>  
#include <util/delay.h>

u8 map(u32 INmax, u32 INmin, u32 OUTmax, u32 OUTmin, u32 IN);
int main() {
    DIOsetPortDirection(portC,OUTPUT_REG);
    DIOsetPortDirection(portD,OUTPUT_REG);
    DIOsetPortDirection(portB,OUTPUT_REG);

    DIOsetPinDirection(PA0,INPUT_PIN);
    DIOsetPinDirection(PA3,INPUT_PIN);
    DIOsetPinDirection(PA7,INPUT_PIN);
    ADCinit();
    globalInterruptEnable();

    while (1){
        
        u16 adc0Data=ADCread(ADC0);
        u8 mappedValueSync0 = map(1023,0,255,0,adc0Data);
        DIOsetPortLogic(portC,mappedValueSync0);

        u16 adc3Data=ADCread(ADC3);
        u8 mappedValueSync3 = map(1023,0,255,0,adc3Data);
        DIOsetPortLogic(portB,mappedValueSync3);

        //ADCasyncStart(ADC3);
        //u8 mappedValueSync3 = map(1023,0,255,0,ADC_ISR_value);
        //DIOsetPortLogic(portD,mappedValueSync3);

        //ADCasyncStart(ADC7);
        //u8 mappedValueASync7 = map(1023,0,255,0,ADC_ISR_value);
        //DIOsetPortLogic(portD,mappedValueASync7);
    }   
    return 0;
}
u8 map(u32 INmax, u32 INmin, u32 OUTmax, u32 OUTmin, u32 IN) {
    u8 OUT = ((((IN - INmin) * (OUTmax - OUTmin)) / (INmax - INmin)) + OUTmin);
    return OUT;
}