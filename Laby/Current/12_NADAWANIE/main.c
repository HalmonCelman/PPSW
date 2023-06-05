#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"
#include "servo.h"
#include "uart.h"
#include "string.h"
#include "command_decoder.h"


struct Watch {
	unsigned char ucMinutes;
	unsigned char ucSeconds;
	unsigned char fSeccondsValueChanged;
	unsigned char fMinutesValueChanged;
};

struct Watch sWatch;

void WatchUpdate(void){
	sWatch.ucSeconds++;
	sWatch.fSeccondsValueChanged=1;
	if(sWatch.ucSeconds==60){
		sWatch.ucSeconds=0;
		sWatch.ucMinutes++;
		sWatch.fMinutesValueChanged=1;
	}
}
/**********************************************/
int main (){
	
	KeyboardInit();
	DetectorInit();
	
	UART_InitWithInt(9600);
	
	Timer0Interrupts_Init(1000000,&WatchUpdate);
	
	char cKomunikat[30];
	
	while(1){
		if(	sWatch.fSeccondsValueChanged == 1 ){
			CopyString("sec ",cKomunikat);
			AppendUIntToString(sWatch.ucSeconds,cKomunikat);
			sWatch.fSeccondsValueChanged = 0;
			
			Transmiter_SendString(cKomunikat);
			if( sWatch.fMinutesValueChanged == 1 ){
				CopyString("min ",cKomunikat);
				AppendUIntToString(sWatch.ucMinutes,cKomunikat);
				Transmiter_SendString(cKomunikat);
				sWatch.fMinutesValueChanged =0;
			}
		}
		
		if( eReciever_GetStatus() == READY ){
			Reciever_GetStringCopy(cKomunikat);
			DecodeMsg(cKomunikat);
			if(ucTokenNr != 0){
				if( asToken[0].uValue.eKeyword==CALC){
					CopyString("calc ",cKomunikat);
					AppendUIntToString(2*asToken[1].uValue.uiNumber,cKomunikat);
					Transmiter_SendString(cKomunikat);
				}
			}
		}

	}
	return 0;
	}
