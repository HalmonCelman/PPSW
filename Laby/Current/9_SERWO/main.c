#include <LPC21xx.H>


#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"

#define DETECTOR_bm (1<<10)

typedef enum {MOVE_LEFT, MOVE_RIGHT, STAY, CALLIB} LedState;

typedef enum {ACTIVE, INACTIVE} DetectorState;


void Automat(void);
void DetectorInit(void);
DetectorState eReadDetector(void);



void Automat(void){
	static LedState eLedState = CALLIB;
	
	switch(eLedState){
		  case CALLIB:
			  if(ACTIVE == eReadDetector()){
				  eLedState = STAY;
        }else{
					LedStepLeft();
				}
			  break;
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

void DetectorInit(void){
	IO0DIR &=~ DETECTOR_bm;
}

DetectorState eReadDetector(void){
	if(IO0PIN & DETECTOR_bm){
    return INACTIVE;
	}else{
	  return ACTIVE;
  }
}


/**********************************************/
int main (){
	LedInit();
	KeyboardInit();
	DetectorInit();
	Timer0Interrupts_Init(20000,&Automat);

  while(1){
  }
	
	return 0;
	}
