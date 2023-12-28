#include"SPI.h"
#include"SPIprivate.h"
void SPIinit (void){
    #if     MASTER_SLAVE_SELECT ==  MASTER
            /* Set MOSI and SCK output, all others input */
            DIOsetPinDirection(MOSI,OUTPUT_PIN);
            DIOsetPinDirection(SCK,OUTPUT_PIN);
            /* Enable SPI, Master, set clock rate fck/16 */
            SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
    #elif   MASTER_SLAVE_SELECT ==  SLAVE
            /* Set MISO output, all others input */
            DIOsetPinDirection(MISO,OUTPUT_PIN);
            /* Enable SPI */
            SET_BIT(SPCR,SPE);
    #endif
}
u8 SPItranseve (u8 data){
    /* Start transmission */
    SPDR = data;
    /* Wait for reception complete */
    while(isStillProcessing());
    /* Return data register */
    return SPDR;  
}

u8 isStillProcessing(void){
    return (!GET_BIT(SPSR,SPIF));
}
