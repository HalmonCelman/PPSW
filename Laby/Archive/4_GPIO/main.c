#include <LPC21xx.H>


#define LED0_bm (1<<16)
#define LED1_bm (1<<17)
#define LED2_bm (1<<18)
#define LED3_bm (1<<19)

#define KEY0_bm (1<<4)
#define KEY1_bm (1<<6)
#define KEY2_bm (1<<5)
#define KEY3_bm (1<<7)


typedef enum {RELEASED,BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3} KeyboardState;

typedef enum {LEFT,RIGHT} StepSide;

void Delay(unsigned int);
void LedInit(void);
void LedOn(unsigned char);
KeyboardState eKeyboardRead(void);
void KeyboardInit(void);
void LedStep(StepSide);
void LedStepLeft(void);
void LedStepRight(void);


void Delay(unsigned int uiDelayTime){
	for(unsigned int uiTimeCounter=0;uiTimeCounter<uiDelayTime*8000;uiTimeCounter++);
}

void LedInit(void){
	IO1DIR |= LED0_bm | LED1_bm | LED2_bm | LED3_bm;
	IO1SET |= LED0_bm;
}

void LedOn(unsigned char ucLedIndeks){
	IO1CLR |= LED0_bm | LED1_bm | LED2_bm | LED3_bm;
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

KeyboardState eKeyboardRead(void){
	if (!(IO0PIN & KEY0_bm)){
		return BUTTON_0;
	}else if(!(IO0PIN & KEY1_bm)){
		return BUTTON_1;
	}else if(!(IO0PIN & KEY2_bm)){
		return BUTTON_2;
	}else if(!(IO0PIN & KEY3_bm)){
		return BUTTON_3;
	}
	return RELEASED;
}

void KeyboardInit(void){
	IO0DIR &=~ (KEY0_bm | KEY1_bm | KEY2_bm | KEY3_bm);
}

void LedStep(StepSide eStepSide){
	static unsigned char ucCurrentDiode=0;
	if(eStepSide == RIGHT ){
		if(0 == ucCurrentDiode){
			ucCurrentDiode=3;
		}else{
			ucCurrentDiode--;
		}
		
	}else{
		if(3 == ucCurrentDiode){
			ucCurrentDiode=0;
		}else{
			ucCurrentDiode++;
		}
	}
	LedOn(ucCurrentDiode);
}

void LedStepLeft(void){
	LedStep(LEFT);
}

void LedStepRight(void){
	LedStep(RIGHT);
}

//main
int main(void){
	
	LedInit();
	KeyboardInit();
	
	while(1){
		switch((int)eKeyboardRead()){
			case BUTTON_1:
				LedStepRight();
				break;
			case BUTTON_2:
				LedStepLeft();
				break;
		}
	}
	return 0;
}

