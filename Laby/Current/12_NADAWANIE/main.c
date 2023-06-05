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
	
	char cKomunikat[30];
	unsigned char ucTimerCounter=0;
	
	while(1){
	if(sTransmiterBuffer.eStatus == FREE){
		CopyString("licznik ",cKomunikat);
		AppendUIntToString(ucTimerCounter,cKomunikat);
		Transmiter_SendString(cKomunikat);
		ucTimerCounter++;
	}
	}
	return 0;
	}
