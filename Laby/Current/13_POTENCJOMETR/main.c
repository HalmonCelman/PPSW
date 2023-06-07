#include <LPC21xx.H>

#include "servo.h"
#include "uart.h"
#include "string.h"
#include "potencjometr.h"
/**********************************************/
int main (){
	
	ServoInit(50);
	UART_InitWithInt(9600);
	Potencjometr_Init();
	char cKomunikat[30];
	
	while(1){
		if((Transmiter_GetStatus()==FREE) && (ADDR & (1u<<31))){
			UIntToHex(Potencjometr_Read()*48/1024,cKomunikat);
			Transmiter_SendString(cKomunikat);
		}
	}
	return 0;
	}
