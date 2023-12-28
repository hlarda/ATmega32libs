#include"SPI.h"
#include"SPIprivate.h"

void(*SPIcallback)(void);

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
            /* Enable SPI init*/
            SET_BIT(SPCR,SPIE);

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
void SPItranmit (u8 data){
    /* Start transmission */
    SPDR = data;
}

u8 isStillProcessing(void){
    return (!GET_BIT(SPSR,SPIF));
}

void SPIsetCallback(void(*SPIcallbackPtr)(void)){
    SPIcallback=SPIcallbackPtr;
}

void __vector_12(void) __attribute__((signal, used, externally_visible));
void __vector_12(void) {
    SPIreseviedData = SPDR;
}