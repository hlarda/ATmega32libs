#include <DIO/DIO.h>
#include <ADC/ADC.h>   
#include <util/delay.h>

u8 map(f128 INmax, f128 INmin, f128 OUTmax, f128 OUTmin, u16 IN);
int main() {
    DIOsetPortDirection(portC,OUTPUT_REG);
    DIOsetPortLogic(portC,HIGH_REG);

    DIOsetPinDirection(PA0,INPUT_PIN);
    ADCx_t selectedChannel = ADC0;
    ADCinit();

    while (1)
    {
        u16 adcData=ADCread(selectedChannel);
        u8 mappedValue = map(255,0,1023,0,adcData);
        DIOsetPortLogic(portC,mappedValue);
        _delay_ms(10);
    }
    return 0;
}
u8 map(f128 INmax, f128 INmin, f128 OUTmax, f128 OUTmin, u16 IN) {
    u8 OUT;
    OUT = ((((IN - INmin) * (OUTmax - OUTmin)) / (INmax - INmin)) / 4 + OUTmin);
    return OUT;
}

