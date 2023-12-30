#include <DIO/DIO.h>
#include <WDT/WDT.h>
#include <util/delay.h>

/*expected: pin never low*/
int main()
{   
    WDTenable(_1_s);
    DIOsetPinDirection(PA0,OUTPUT_PIN);
    while (1)
    {
        DIOsetPinLogic(PA0,HIGH_PIN);
        _delay_ms(2000);
        DIOsetPinLogic(PA0,LOW_PIN);
    }
    return 0;
}
