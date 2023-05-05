#include <LPC21xx.H>

#include "led.h"
#include "keyboard.h"
#include "timer.h"

void Delay(unsigned int uiDelayTime);

void Delay(unsigned int uiDelayTime){
	WaitOnTimer0(uiDelayTime*1000);
}




//main
int main(void){
	InitTimer0();
	LedInit();
	KeyboardInit();

	typedef enum {MOVE_LEFT, MOVE_RIGHT, STAY} LedState;
  LedState eLedState = STAY;

  while(1){
    switch(eLedState){
      case MOVE_LEFT:
        LedStepLeft();
				if(BUTTON_1 == eKeyboardRead()){
          eLedState = STAY;
				}
        break;
      case STAY:
        if(BUTTON_2 == eKeyboardRead()){
				  eLedState=MOVE_RIGHT;
        }
				else if(BUTTON_0 == eKeyboardRead()){
          eLedState = MOVE_LEFT;
				}
        break;
			case MOVE_RIGHT:
        LedStepRight();
				if(BUTTON_1 == eKeyboardRead()){
          eLedState = STAY;
				}
        break;	
			
    }
		Delay(100);
  }
	return 0;
}

