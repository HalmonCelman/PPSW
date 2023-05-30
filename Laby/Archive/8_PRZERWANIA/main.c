#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"

typedef enum {MOVE_LEFT, MOVE_RIGHT, STAY} LedState;

void Automat(void){
	static LedState eLedState = STAY;
	
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
}
/**********************************************/
int main (){
	LedInit();
	KeyboardInit();
	Timer0Interrupts_Init(100000,&Automat);

  while(1){
  }
	
	return 0;
	}
