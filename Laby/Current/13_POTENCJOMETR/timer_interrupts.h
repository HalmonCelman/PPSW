extern void (*ptrTimer0InterruptFunction)(void);
extern void (*ptrTimer1InterruptFunction)(void);

void Timer0Interrupts_Init(unsigned int uiPeriod, void (*ptrInterruptFunction)(void) );
void Timer1Interrupts_Init(unsigned int uiPeriod, void (*ptrInterruptFunction)(void) );
