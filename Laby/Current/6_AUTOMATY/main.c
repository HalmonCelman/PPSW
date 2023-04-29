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

	unsigned char ucMoveCounter=0;
	
	typedef enum {MOVE_LEFT, MOVE_RIGHT} LedState;
  LedState eLedState = MOVE_LEFT;
  while(1){
    switch(eLedState){
      case MOVE_LEFT:
        LedStepLeft();
				if(2==ucMoveCounter){
          eLedState = MOVE_RIGHT;
					ucMoveCounter=0;
				}else{
					ucMoveCounter++;
				}
        break;
      case MOVE_RIGHT:
        LedStepRight();
				if(2==ucMoveCounter){
          eLedState = MOVE_LEFT;
					ucMoveCounter=0;
				}else{
					ucMoveCounter++;
				}
        break;
    }
  }
	return 0;
}

