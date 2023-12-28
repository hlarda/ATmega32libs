#include "DIO/DIO.h"

int main(void) {
    //DIOsetPinDirection(PA0, OUTPUT_PIN);
    //DIOsetPinDirection(PA5, OUTPUT_PIN);

    DIOsetPortDirection(portA, OUTPUT_REG);
    DIOsetPortDirection(portB, OUTPUT_REG);
  while (1)
  {
    //DIOsetPinLogic(PA0, HIGH_PIN);
    //pinLogic_t pinLogic = DIOgetPinLogic(PA0);
    //DIOsetPinLogic(PA5,pinLogic);

    DIOsetPortLogic(portB, HIGH_REG);
    registerLogic_t portClogic = DIOgetPortLogic(portB);
    DIOsetPortLogic(portA,portClogic);
  }
  return 0;
}