#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

#define TCCR0           (*(volatile u8*)0x53)
#define CS00            0
#define CS01            1
#define CS02            2
#define WGM01           3
#define COM00           4
#define COM01           5
#define WGM00           6
#define FOC0            7

#define TCNT0           (*(volatile u8*)0x52)

#define OCR0            (*(volatile u8*)0x5C)

#define TIMSK           (*(volatile u8*)0x59)
#define TOIE0           0
#define OCIE0           1

#define TIFR            (*(volatile u8*)0x58)
#define TOV0            0
#define OCF0            1

u16 prescalerValue[] = {0,1,8,64,256,1024};
#define CLR_FIRST_3_BITS_MASK                 0xF8
#define _8_BIT_TIMER_OVERFLOW_TICKS           256

void timerSetOperationMode(Timerx_t TIMERX);
void timerSetPrescalarValue(Timerx_t TIMERX);
void timerEnableInterrupt(Timerx_t TIMERX);

#endif