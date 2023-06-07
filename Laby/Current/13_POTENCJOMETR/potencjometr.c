#include <LPC21xx.H>
#include "potencjometr.h"

void Potencjometr_Init(){
	PINSEL1 |= (1<<22);
	ADCR = (1<<0) | (14<<8) | (1<<16) | (1<<21) | (1<<24);
}
int Potencjometr_Read(){
	return ((ADDR >> 6) & 0x3FF);
}
