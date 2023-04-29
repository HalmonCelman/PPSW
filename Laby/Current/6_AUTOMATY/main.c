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
	
	typedef enum {LED_LEFT, LED_RIGHT} LedState;
  LedState eLedState = LED_LEFT;
  while(1){
    switch(eLedState){
      case LED_LEFT:
        LedStepLeft();
        eLedState = LED_RIGHT;
        break;
      case LED_RIGHT:
        LedStepRight();
        eLedState = LED_LEFT;
        break;
    }
  }
	return 0;
}

