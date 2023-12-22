#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H

typedef enum timerOprationMode_t{
    NORMAL=0,
    PHASE_CORRECT,
    CTC,
    FAST_PWM
}timerOprationMode_t;
#define TIMER0_OPERATION_MODE   NORMAL

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