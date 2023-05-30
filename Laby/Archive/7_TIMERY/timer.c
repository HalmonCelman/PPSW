#include <LPC21xx.H>
#include "timer.h"

#define mTIMER0_ENABLE (1<<0)
#define mTIMER0_RESET (1<<1)
#define mTIMER0_MR0_INTERRUPT_ENABLE (1<<0)
#define mTIMER0_MR0_RESET_TC (1<<1)
#define mTIMER0_MR0_INTERRUPT_FLAG (1<<0)

void InitTimer0(void){
  T0TCR = mTIMER0_ENABLE;
}


void WaitOnTimer0(unsigned int uiTime){
	T0TCR |= mTIMER0_RESET;
	T0TCR &=~ mTIMER0_RESET;
  while( T0TC<(uiTime*15) );
}

void InitTimer0Match0(unsigned int iDelayTime){
	T0MR0 = iDelayTime*15;
	T0MCR |= mTIMER0_MR0_INTERRUPT_ENABLE | mTIMER0_MR0_RESET_TC;
	T0TCR |= mTIMER0_RESET;
	T0TCR &=~ mTIMER0_RESET;
	InitTimer0();
}

void WaitOnTimer0Match0(void){
	while(0 == (T0IR & mTIMER0_MR0_INTERRUPT_FLAG));
	T0IR = mTIMER0_MR0_INTERRUPT_FLAG;
}

