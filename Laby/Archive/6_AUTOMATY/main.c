#include "led.h"
#include "keyboard.h"

void Delay(unsigned int uiDelayTime){
	for(unsigned int uiTimeCounter=0;uiTimeCounter<uiDelayTime*8000;uiTimeCounter++);
}


//main
int main(void){
	LedInit();
	KeyboardInit();

	unsigned char ucChangeCounter=0;
	
	typedef enum {MOVE_LEFT, MOVE_RIGHT, STAY, BLINK} LedState;
  LedState eLedState = STAY;

  while(1){
    switch(eLedState){
      case MOVE_LEFT:
				if(BUTTON_1 == eKeyboardRead()){
          eLedState = STAY;
				} else {
					LedStepLeft();
				}
        break;
      case STAY:
        if(BUTTON_2 == eKeyboardRead()){
				  eLedState=MOVE_RIGHT;
        }else if(BUTTON_0 == eKeyboardRead()){
          eLedState = MOVE_LEFT;
				}else if(BUTTON_3 == eKeyboardRead()){
					eLedState = BLINK;
				}
        break;
			case MOVE_RIGHT:
				if(BUTTON_1 == eKeyboardRead()){
          eLedState = STAY;
				}	else{
					LedStepRight();
				}
        break;
			case BLINK:
				if(6 == ucChangeCounter){
					ucChangeCounter = 0;
					eLedState = STAY;
				}else{
					if((ucChangeCounter%2) == 0){
						ucChangeCounter++;
						LedOn(4);
					}else{
						ucChangeCounter++;
						LedOn(0);
					}
				}
			
				break;
			
    }
		Delay(100);
  }
	return 0;
}

