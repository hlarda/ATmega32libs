#include"WDT.h"
#include"WDTprivate.h"

void WDTenable(WDTprescalar_t WDTprescalar){
    WDTCR = (WDTCR & 0b11111000) | WDTprescalar;
    SET_BIT(WDTCR,WDE);
}
void WDTdisenable(void){
    WDTCR = (1<<WDTOE) | (1<<WDE);
    WDTCR = 0x00;
    }
