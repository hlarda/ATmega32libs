#ifndef WDT_PRIVATE_h
#define WDT_PRIVATE_h

#define WDTCR       (*(volatile u8*)0x41)
#define WDP0        0
#define WDP1        1
#define WDP2        2
#define WDE         3
#define WDTOE       4

#endif