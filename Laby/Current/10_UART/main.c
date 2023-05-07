#include <LPC21xx.H>


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
				break;
			case '1':
				ServoGoTo(50);
				break;
			case '2':
				ServoGoTo(100);
				break;
			case '3':
				ServoGoTo(150);
				break;			
			
		}
		
		cOdebranyZnak=' ';
		
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
