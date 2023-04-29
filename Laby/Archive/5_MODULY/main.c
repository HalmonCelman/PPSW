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
	
	while(1){
		switch((int)eKeyboardRead()){
			case BUTTON_1:
				LedStepRight();
				break;
			case BUTTON_2:
				LedStepLeft();
				break;
		}
		Delay(500);
	}
	return 0;
}

