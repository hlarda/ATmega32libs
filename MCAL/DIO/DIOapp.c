#include "DIO/DIO.h"

int main(void) {
  DIOsetPinDirection(PA0, OUTPUT_PIN);
  DIOsetPinDirection(PB0, OUTPUT_PIN);
  DIOsetPinLogic(PA0, HIGH_PIN);
  pinLogic_t pinLogic = DIOgetPinLogic(PA0);
  DIOsetPinLogic(PB0,pinLogic);

  DIOsetPortDirection(portC, OUTPUT_REG);
  DIOsetPortDirection(portD, OUTPUT_REG);
  DIOsetPortLogic(portC, HIGH_REG);
  registerLogic_t portClogic = DIOgetPortLogic(portC);
  DIOsetPortLogic(portD,portClogic);

  return 0;
}