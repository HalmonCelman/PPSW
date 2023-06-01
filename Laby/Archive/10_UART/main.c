#include <LPC21xx.H>
//git test

#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"
#include "servo.h"
#include "uart.h"


/**********************************************/
int main (){
	
	KeyboardInit();
	DetectorInit();
	
	UART_InitWithInt(9600);
	
	ServoInit(50);
	
	

  while(1){
		
		switch(cOdebranyZnak){
			case 'c':
				ServoCallib();
			  cOdebranyZnak=' ';
				break;
			case '1':
				ServoShift(12);
			  cOdebranyZnak=' ';
				break;			
			default:
				break;
		}
		
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
			default:
				break;
		}
  }
	
	return 0;
	}
