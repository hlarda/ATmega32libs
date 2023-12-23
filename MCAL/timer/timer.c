#include"timer.h"
#include"timerPrivate.h"

void (*timer0Callback)(void) = NULL;
void (*timer1Callback)(void) = NULL;
void (*timer2Callback)(void) = NULL;

u32 timer0_overflowTimes=0;
u32 timer0_compareMatchTimes=0;

u32 timer0_remainedTicks=0;

void timerInit(Timerx_t TIMERX){
     timerSetOperationMode (TIMERX);
     timerEnableInterrupt  (TIMERX);
}

void timerSet_ms(Timerx_t TIMERX,u16 time_ms){
    u32 time_us=1000*time_ms;
    u32 tickTime    = prescalerValue[TIMER0_PRESCALER] / SYSTEM_CLK;
    u32 totalTicks  = time_us / tickTime;

    switch (TIMERX){
    case TIMER0:
        #if TIMER0_OPERATION_MODE == NORMAL
            timer0_overflowTimes = totalTicks / _8_BIT_TIMER_OVERFLOW_TICKS;
            timer0_remainedTicks = totalTicks % _8_BIT_TIMER_OVERFLOW_TICKS;
            if(timer0_remainedTicks){
                timer0_overflowTimes++;
                TCNT0 = _8_BIT_TIMER_OVERFLOW_TICKS - timer0_remainedTicks;
            }  
            timerSetPrescalarValue(TIMERX);
        #elif TIMER0_OPERATION_MODE == CTC
            u8 compareMatch = 255;
            while (totalTicks % compareMatch){
                compareMatch --;
            }
            OCR0 = compareMatch - 1;
            timer0_compareMatchTimes = totalTicks / compareMatch;
            timerSetPrescalarValue(TIMERX);
        #endif
        break;  
    case TIMER1:

        break;
    case TIMER2:
        break;
    default:            break;
    }  
}

void timerSetCallback(Timerx_t TIMERX,void(*timerCallbackPtr)(void)){
    switch(TIMERX){
        case TIMER0:    timer0Callback = timerCallbackPtr;       break;
        case TIMER1:    timer1Callback = timerCallbackPtr;       break;
        case TIMER2:    timer2Callback = timerCallbackPtr;       break;
        default:                                                 break;
        }
}

void __vector_11(void) __attribute__((signal, used, externally_visible));
void __vector_11(void) {
    if (timer0Callback != NULL) {
        static u32 timer0_OV_counter = 0;
        timer0_OV_counter++;
        if (timer0_OV_counter == timer0_overflowTimes){
            timer0Callback();
            timer0_OV_counter=0;
            TCNT0 = _8_BIT_TIMER_OVERFLOW_TICKS - timer0_remainedTicks;
        }
    }
}

void timerSetOperationMode(Timerx_t TIMERX){
    switch (TIMERX){
    case TIMER0:
        #if TIMER0_MODE == NORMAL
	        CLR_BIT(TCCR0 , WGM00);
	        CLR_BIT(TCCR0 , WGM01);
        #elif TIMER0_MODE == PHASE_CORRECT
        	SET_BIT(TCCR0 , WGM00);
        	CLR_BIT(TCCR0 , WGM01);
        #elif TIMER0_MODE == CTC
        	CLR_BIT(TCCR0 , WGM00);
        	SET_BIT(TCCR0 , WGM01);
        #elif TIMER0_MODE == FAST_PWM
        	SET_BIT(TCCR0 , WGM00);
        	SET_BIT(TCCR0 , WGM01);
        #endif  
        break;
    case TIMER1:
        break;
    case TIMER2:
        break;
    default:            break;
    }
}
void timerSetPrescalarValue(Timerx_t TIMERX){
    switch (TIMERX){
    case TIMER0:
        TCCR0 = (TCCR0&CLR_FIRST_3_BITS_MASK) | TIMER0_PRESCALER ;
        break;
    case TIMER1:
        break;
    case TIMER2:
        break;
    default:            break;
    }  
}
void timerEnableInterrupt(Timerx_t TIMERX){
    switch (TIMERX){
    case TIMER0:
        SET_BIT(TIMSK,TOIE0);
        break;
    case TIMER1:
        break;
    case TIMER2:
        break;
    default:            break;
    }  
}