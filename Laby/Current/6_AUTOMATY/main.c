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
	
	typedef enum {MOVE, STAY} LedState;
  LedState eLedState = STAY;
  while(1){
    switch(eLedState){
      case MOVE:
        LedStepRight();
				if(2==ucMoveCounter){
          eLedState = STAY;
					ucMoveCounter=0;
				}else{
					ucMoveCounter++;
				}
        break;
      case STAY:
        if(BUTTON_0 == eKeyboardRead()){
				  eLedState=MOVE;
        }
        break;
    }
  }
	return 0;
}

