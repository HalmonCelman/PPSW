
extern void (*ptrTimer0InterruptFunction)(void);

void Timer0Interrupts_Init(unsigned int uiPeriod, void (*ptrInterruptFunction)(void) );
