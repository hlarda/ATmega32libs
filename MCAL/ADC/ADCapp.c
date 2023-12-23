#include <DIO/DIO.h>
#include <ADC/ADC.h>   
#include <util/delay.h>

u8 map(u32 INmax, u32 INmin, u32 OUTmax, u32 OUTmin, u32 IN);
int main() {
    DIOsetPortDirection(portC,OUTPUT_REG);
    DIOsetPortLogic(portC,HIGH_REG);

    DIOsetPinDirection(PA0,INPUT_PIN);
    ADCx_t selectedChannel = ADC0;
    ADCinit();

    while (1)
    {
        u16 adcData=ADCread(selectedChannel);
        u8 mappedValue = map(1023,0,255,0,adcData);
        DIOsetPortLogic(portC,mappedValue);
        _delay_ms(10);
    }
    return 0;
}
u8 map(u32 INmax, u32 INmin, u32 OUTmax, u32 OUTmin, u32 IN) {
    u8 OUT = ((((IN - INmin) * (OUTmax - OUTmin)) / (INmax - INmin)) + OUTmin);
    return OUT;
}

