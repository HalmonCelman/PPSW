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
	ServoInit(50);
	UART_InitWithInt(9600);
	
	Timer1Interrupts_Init(1000000,&WatchUpdate);
	
	unsigned char fResponse=0;
	
	char cKomunikat[30];
	
	while(1){
		if(sTransmiterBuffer.eStatus==FREE){
			if(	sWatch.fSeccondsValueChanged == 1 ){
				sWatch.fSeccondsValueChanged = 0;
				CopyString("sec ",cKomunikat);
				AppendUIntToString(sWatch.ucSeconds,cKomunikat);
				Transmiter_SendString(cKomunikat);
			}else if( sWatch.fMinutesValueChanged == 1 ){
				sWatch.fMinutesValueChanged =0;
				CopyString("min ",cKomunikat);
				AppendUIntToString(sWatch.ucMinutes,cKomunikat);
				Transmiter_SendString(cKomunikat);
			}else if( fResponse == 1 ){
				Transmiter_SendString(cKomunikat);
				fResponse = 0;
			}
				
		}
			if( eReciever_GetStatus() == READY ){
			Reciever_GetStringCopy(cKomunikat);
			DecodeMsg(cKomunikat);
				if(ucTokenNr != 0){
					switch(asToken[0].uValue.eKeyword){
						case CAL:
							ServoCallib();
							CopyString("OK",cKomunikat);
							fResponse=1;
							break;
						case GO:
							ServoGoTo(asToken[1].uValue.uiNumber);
							CopyString("OK",cKomunikat);
							fResponse=1;
							break;
						case CALC:
							CopyString("calc ",cKomunikat);
							AppendUIntToString(2*asToken[1].uValue.uiNumber,cKomunikat);
							fResponse=1;
							break;
						}
				}
				
					
			}
	}
	return 0;
	}
