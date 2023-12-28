#ifndef UART_H
#define UART_H

#include <stdtype.h>
#include <bitmath.h>

void UARTinit   (void);
void UARTsend(u8 data);
u8   UARTreceive(void);


#endif