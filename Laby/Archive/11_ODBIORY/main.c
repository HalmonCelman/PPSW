#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"
#include "servo.h"
#include "uart.h"
#include "string.h"
#include "command_decoder.h"

/**********************************************/
int main (){
	
	KeyboardInit();
	DetectorInit();
	
	UART_InitWithInt(9600);
	
	ServoInit(50);
	
	char cKomunikat[RECIEVER_SIZE]="";

	while(1){
		if(eReciever_GetStatus() == READY){
				Reciever_GetStringCopy(cKomunikat);
				DecodeMsg(cKomunikat);
				if((ucTokenNr != 0) && (asToken[0].eType == KEYWORD)){
					switch(asToken[0].uValue.eKeyword){
					case CAL:
						ServoCallib();
						break;
					case GO:
						sServo.uiDesiredPosition = asToken[1].uValue.uiNumber;
						break;
					}
				}
		}	
}
	
	return 0;
	}
