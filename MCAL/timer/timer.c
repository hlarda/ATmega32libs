#include"timer.h"
#include"timerPrivate.h"

u16 timer0_overflowTimes=0;
u16 timer0_counter = 0;
void (*timer0Callback)(void) = NULL;
void (*timer1Callback)(void) = NULL;
void (*timer2Callback)(void) = NULL;

void timerInit(Timerx_t TIMERX){
     timerSetOperationMode (TIMERX);
     timerSetPrescalarValue(TIMERX);
     timerEnableInterrupt  (TIMERX);
}

void timerSet_ms(Timerx_t TIMERX,u16 time_ms){
    u32 time_us=1000*time_ms;

    switch (TIMERX){
    case TIMER0:{
        u8  tickTime;
        u16 overflowTime;
        u8 preloadedValue;
        tickTime     = prescalerValue[TIMER0_PRESCALER] / SYSTEM_CLK;
        overflowTime = _8_BIT_TIMER_OVERFLOW_TICKS * tickTime;
        timer0_overflowTimes= time_us / overflowTime;
        preloadedValue = _8_BIT_TIMER_OVERFLOW_TICKS-(time_us % overflowTime);
        if(preloadedValue){
            timer0_overflowTimes++;
        }
        TCNT0 = preloadedValue;  
        break;
    }    
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
        timer0_counter++;
        if (timer0_counter >= timer0_overflowTimes){
            timer0Callback();
            timer0_counter=0;
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