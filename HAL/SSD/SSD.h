#include<util/delay.h>
#include"DIO/DIO.h"
#include"SSD/SSDconfig.h"

typedef enum{
    SSD_COMMON_ANODE,
    SSD_COMMON_CATHODE
}SSDconnection_t;
typedef struct
{
    portPin_t       SSDpins[7];
    SSDconnection_t connection;
}SSD_t;


void SSDinit(SSD_t *SSD);
void SSD1digit(SSD_t *SSD , u8 _1digit);
void SSD2digits(SSD_t *SSD , u8 _2digits);