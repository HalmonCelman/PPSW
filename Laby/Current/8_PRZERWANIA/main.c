#include "led.h"
#include "timer_interrupts.h"


/**********************************************/
int main (){
	LedInit();
	
	unsigned int iMainLoopCtr;
	Timer0Interrupts_Init(250000,&LedStepLeft);

	while(1){
	 	iMainLoopCtr++;
	}
}
