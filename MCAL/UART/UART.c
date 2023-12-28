#include"UART.h"
#include"UARTprivate.h"

void UARTinit(void)
{
    selectBaudRate();
    setFrameFormat();
    enableReceiverAndTransmitter();
}
void UARTsend(u8 data){
    /* Wait for empty transmit buffer */
    while ( !GET_BIT(UCSRA,TXC) );
    /* Put data into buffer, sends the data */
    UDR = data;
}
u8   UARTreceive(void){
    /* Wait for data to be received */
    while ( !GET_BIT(UCSRA,RXC) );
    /* Get and return received data from buffer */
    return UDR;
}

void selectBaudRate(void){
    /* TO SELECT BAUDRATE -> 9600 */
	UBRRL = 103;
    /*Set baud rate 
    UBRRH = (unsigned char)(baud>>8);
    UBRRL = (unsigned char)baud;*/
}
void setFrameFormat(void){
    /*     RegisterSelect,   1stop bit,        disable parity,        8bits Data,  Asynchronous*/
    UCSRC = (1 << URSEL) | (0 << USBS) | (0 << UPM0) | (0 << UPM1) | (3 << UCSZ0) | (0 << UMSEL);
}
void enableReceiverAndTransmitter(void){
    UCSRB = (1<<RXEN)|(1<<TXEN);
}