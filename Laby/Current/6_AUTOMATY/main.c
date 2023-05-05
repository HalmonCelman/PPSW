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

	typedef enum {MOVE, STAY} LedState;
  LedState eLedState = MOVE;

  while(1){
    switch(eLedState){
      case MOVE:
        LedStepRight();
				Delay(200);
				if(BUTTON_0 == eKeyboardRead()){
          eLedState = STAY;
				}
        break;
      case STAY:
        if(BUTTON_1 == eKeyboardRead()){
				  eLedState=MOVE;
        }
        break;
    }
  }
	return 0;
}

