#include <LPC21xx.H>


#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"

#define DETECTOR_bm (1<<10)

typedef enum {ACTIVE, INACTIVE} DetectorState;

enum ServoState {CALLIB, IDLE, IN_PROGRESS};

struct Servo
{
enum ServoState eState; unsigned int
uiCurrentPosition; unsigned int
uiDesiredPosition;
}; struct Servo sServo;


void Automat(void);
void DetectorInit(void);
DetectorState eReadDetector(void);



void Automat(void){
		
	switch(sServo.eState){
		  case CALLIB:
			  if(ACTIVE == eReadDetector()){
				  sServo.eState = IDLE;
					sServo.uiCurrentPosition=0;
					sServo.uiDesiredPosition=0;
        }else{
					LedStepLeft();
				}
			  break;
      case IDLE:
				if(sServo.uiCurrentPosition != sServo.uiDesiredPosition){
          sServo.eState = IN_PROGRESS;
				}
        break;
      case IN_PROGRESS:
        if(sServo.uiCurrentPosition < sServo.uiDesiredPosition){
          LedStepRight();
					sServo.uiCurrentPosition++;
				} else if(sServo.uiCurrentPosition > sServo.uiDesiredPosition){
          LedStepLeft();
					sServo.uiCurrentPosition--;
				} else{
          sServo.eState = IDLE;
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
	
	sServo.eState=CALLIB;
	
	Timer0Interrupts_Init(20000,&Automat);

  while(1){
		switch(eKeyboardRead()){
			case BUTTON_0:
				sServo.eState=CALLIB;
			  break;
			case BUTTON_1:
				sServo.uiDesiredPosition=12;
			  break;
			case BUTTON_2:
				sServo.uiDesiredPosition=24;
			  break;
			case BUTTON_3:
				sServo.uiDesiredPosition=36;
			  break;
		}
  }
	
	return 0;
	}
