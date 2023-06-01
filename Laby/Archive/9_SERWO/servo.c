#include <LPC21xx.H>

#include "servo.h"
#include "led.h"
#include "timer_interrupts.h"

#define DETECTOR_bm (1<<10)

enum ServoState {CALLIB, IDLE, IN_PROGRESS, OFFSET};


struct Servo
{
enum ServoState eState;
unsigned int uiCurrentPosition;
unsigned int uiDesiredPosition;
}; 

struct Servo sServo;

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
			case OFFSET:
				if(sServo.uiCurrentPosition==12){
					sServo.uiCurrentPosition = 0;
					sServo.eState = IDLE;
				}else{
					LedStepRight();
					sServo.uiCurrentPosition++;
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

void ServoInit(unsigned int uiServoFrequency){
	LedInit();
	DetectorInit();
	Timer0Interrupts_Init(1000000/uiServoFrequency,&Automat);
	ServoCallib();
}

void ServoCallib(void){
  sServo.eState=CALLIB;
	while(sServo.eState == CALLIB);
}

void ServoGoTo(unsigned int uiPosition){
	while(sServo.eState == IN_PROGRESS);
	sServo.uiDesiredPosition=uiPosition;
	sServo.eState = IN_PROGRESS;
}

DetectorState eReadDetector(void){
	if(IO0PIN & DETECTOR_bm){
    return INACTIVE;
	}else{
	  return ACTIVE;
  }
}
