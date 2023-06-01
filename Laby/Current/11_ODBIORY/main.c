#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"
#include "servo.h"
#include "uart.h"
#include "reciever.h"

#include "lancuchy.h"

/**********************************************/
int main (){
	
	KeyboardInit();
	DetectorInit();
	
	UART_InitWithInt(9600);
	
	ServoInit(50);
	
	char cKomunikat[RECIEVER_SIZE]="";

	while(1){
		switch(eReciever_GetStatus()){
			case READY:
				Reciever_GetStringCopy(cKomunikat);
				if(EQUAL == eCompareString(cKomunikat,"callib")){
					ServoCallib();
				}else if(EQUAL == eCompareString(cKomunikat,"left")){
					ServoGoTo(50);
				}else if(EQUAL == eCompareString(cKomunikat,"right")){
					ServoGoTo(150);
				}
				break;
			default:
				break;
		}	
}
	
	return 0;
	}
