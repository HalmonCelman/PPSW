#ifndef UART_H
#define UART_H

__irq void UART0_Interrupt (void);
void UART_InitWithInt(unsigned int uiBaudRate);


extern char cOdebranyZnak;

#endif
