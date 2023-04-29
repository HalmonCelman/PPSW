#include <LPC21xx.H>

#include "led.h"
#include "keyboard.h"

void Delay(unsigned int uiDelayTime);

void Delay(unsigned int uiDelayTime){
	for(unsigned int uiTimeCounter=0;uiTimeCounter<uiDelayTime*8000;uiTimeCounter++);
}




//main
int main(void){
	LedInit();
	KeyboardInit();
	
	typedef enum {L0,L1,L2,R0,R1,R2} LedState;
  LedState eLedState = L0;
  while(1){
    switch(eLedState){
      case L0:
        LedStepLeft();
        eLedState = L1;
        break;
			case L1:
        LedStepLeft();
        eLedState = L2;
        break;
			case L2:
        LedStepLeft();
        eLedState = R0;
        break;
			 case R0:
        LedStepRight();
        eLedState = R1;
        break;
			case R1:
        LedStepRight();
        eLedState = R2;
        break;
			case R2:
        LedStepRight();
        eLedState = L0;
        break;
    }
  }
	return 0;
}

