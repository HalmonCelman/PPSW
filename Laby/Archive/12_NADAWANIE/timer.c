#include <LPC21xx.H>
#include "timer.h"

void InitTimer0(void){
  T0TCR |= (1<<0);
}


void WaitOnTimer0(unsigned int uiTime){
	T0TCR |= (1<<1);
	T0TCR &=~ (1<<1);
  while( T0TC<(uiTime*15) );
}

void InitTimer0Match0(unsigned int iDelayTime){
	T0MR0 = iDelayTime*15;
	T0MCR |= (1<<0) | (1<<1);
	T0TCR |= (1<<1);
	T0TCR &=~ (1<<1);
	InitTimer0();
}

void WaitOnTimer0Match0(void){
	while(!(T0IR & (1<<0)));
	T0IR |= (1<<0);
}

