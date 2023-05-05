#include <LPC21xx.H>

#include "led.h"
#include "keyboard.h"
#include "timer.h"


//main
int main(void){
	InitTimer0();
	LedInit();
	KeyboardInit();

  while(1){
    LedStepLeft();
		InitTimer0Match0(100000);
		WaitOnTimer0Match0();
  }
	return 0;
}

