#include "SSD/SSD.h"

int main(void) {
  SSD_t SSD1={
  .connection=SSD_COMMON_CATHODE,
  .SSDpins={PC0, PC1, PC2, PC3, PC4, PC5, PC6}
  };
  SSD_t SSD2={
  .connection=SSD_COMMON_ANODE,
  .SSDpins={PD0, PD1, PD2, PD3, PD4, PD5, PD6}
  };
  SSD_t SSD00={
  .connection=SSD_COMMON_ANODE,
  .SSDpins={PA0, PA1, PA2, PA3, PA4, PA5, PA6}
  };

  SSDinit(&SSD1);
  SSDinit(&SSD2);
  SSDinit(&SSD00);

  for (int i = 0; i < 10; i++)
  {
    SSD1digit(&SSD1,i);
    SSD1digit(&SSD2,9-i);
    _delay_ms(50);
  }

    SSD2digits(&SSD00,99);
    _delay_ms(50);
  
  
  
  return 0;
}
