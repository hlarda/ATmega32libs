#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H

#define NORMAL          0
#define PHASE_CORRECT   1    
#define CTC             2    
#define FAST_PWM        3
#define TIMER0_OPERATION_MODE   CTC
#define TIMER0_CTC_TOP          _8_BIT_TIMER_OVERFLOW_TICKS-1

#define    NO_CLOCK_SOURCE      0
#define    NO_PRESCALAR         1
#define    _8_PRESCALAR         2
#define    _64_PRESCALAR        3
#define    _256_PRESCALAR       4
#define    _1024_PRESCALAR      5

#define TIMER0_PRESCALER   _8_PRESCALAR

#define SYSTEM_CLK   8

#endif