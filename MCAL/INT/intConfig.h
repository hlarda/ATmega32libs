#ifndef INT_CONFIG_H
#define INT_CONFIG_H

#define LOW_LEVEL               1
#define ANY_CHANGE              2
#define RISING_EDGE             3
#define FALLING_EDGE            4

#define INT0_SENSE_CONTROL      RISING_EDGE
#define INT1_SENSE_CONTROL      LOW_LEVEL
/*ONLY raising and falling available options for INT2*/
#define INT2_SENSE_CONTROL      FALLING_EDGE

#endif