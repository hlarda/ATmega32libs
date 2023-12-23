#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H

#define NORMAL          0
#define PHASE_CORRECT   1    
#define CTC             2    
#define FAST_PWM        3
#define TIMER0_OPERATION_MODE   CTC
#define TIMER0_CTC_TOP          _8_BIT_TIMER_OVERFLOW_TICKS-1


typedef enum timerPrescalar_t{
    NO_CLOCK_SOURCE=0,
    NO_PRESCALAR,
    _8_PRESCALAR,
    _64_PRESCALAR,
    _256_PRESCALAR,
    _1024_PRESCALAR
}timerPrescalar_t;
#define TIMER0_PRESCALER   _8_PRESCALAR

#define SYSTEM_CLK   8

#endif