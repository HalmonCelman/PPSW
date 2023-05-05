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

