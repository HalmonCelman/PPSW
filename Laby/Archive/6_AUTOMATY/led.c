#include <LPC21xx.H>
#include "led.h"


void LedInit(void){
	IO1DIR |= LED0_bm | LED1_bm | LED2_bm | LED3_bm;
	IO1SET = LED0_bm;
}

void LedOn(unsigned char ucLedIndeks){
	IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
	switch(ucLedIndeks){
	case 0:
		IO1SET = LED0_bm;
		break;
	case 1:
		IO1SET = LED1_bm;
		break;
	case 2:
		IO1SET = LED2_bm;
		break;
	case 3:
		IO1SET = LED3_bm;
		break;
	}
}

static void LedStep(StepSide eStepSide){
	static unsigned char ucCurrentDiode=0;
	if(eStepSide == RIGHT ){
			ucCurrentDiode--;
	}else{
			ucCurrentDiode++;
	}
	LedOn(ucCurrentDiode%4);
}

void LedStepLeft(void){
	LedStep(LEFT);
}

void LedStepRight(void){
	LedStep(RIGHT);
}
