#include"GINT.h"
#include"GINTprivate.h"

void globalInterruptEnable(void){
    SET_BIT(SREG,SREG_GINT_EN);
}
void globalInterruptDisable(void){
    CLR_BIT(SREG,SREG_GINT_EN);
}