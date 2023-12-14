#include<DIO/DIO.h>
#include<util/delay.h>

int main()
{
  DIOsetPinDirection(PC0,OUTPUT_PIN);
  DIOsetPinDirection(PC1,OUTPUT_PIN);

  
  while (1)
  {
    DIOsetPinLogic(PC0,HIGH_PIN);
    DIOsetPinLogic(PC1,LOW_PIN);
    _delay_ms(500);
    DIOsetPinLogic(PC0,LOW_PIN);
    DIOsetPinLogic(PC1,LOW_PIN);
    _delay_ms(500);
    DIOsetPinLogic(PC0,LOW_PIN);
    DIOsetPinLogic(PC1,HIGH_PIN);
    _delay_ms(500);
    DIOsetPinLogic(PC0,LOW_PIN);
    DIOsetPinLogic(PC1,LOW_PIN);
    _delay_ms(500);
  }
  return 0;
}
