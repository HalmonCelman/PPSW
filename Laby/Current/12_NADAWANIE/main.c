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
	while(1){
	if(sTransmiterBuffer.eStatus == FREE){
		Transmiter_SendString("test123");
	}
	}
	return 0;
	}
