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

void ServoCallib(void){
  sServo.eState=CALLIB;
}

void ServoInit(unsigned int uiServoFrequency){
	ServoCallib();
	LedInit();
	Timer0Interrupts_Init(1000000/uiServoFrequency,&Automat);
}

void ServoGoTo(unsigned int uiPosition){
	sServo.uiDesiredPosition=uiPosition;
}

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
	
	KeyboardInit();
	DetectorInit();
	
	ServoInit(50);
	
	

  while(1){
		switch(eKeyboardRead()){
			case BUTTON_0:
				ServoCallib();
			  break;
			case BUTTON_1:
				ServoGoTo(12);
			  break;
			case BUTTON_2:
				ServoGoTo(24);
			  break;
			case BUTTON_3:
				ServoGoTo(36);
			  break;
		}
  }
	
	return 0;
	}
