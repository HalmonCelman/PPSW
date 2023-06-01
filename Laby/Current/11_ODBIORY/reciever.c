#include "reciever.h"
#include "lancuchy.h"

struct RecieverBuffer sRxBuffer;

void Reciever_PutCharacterToBuffer(char cCharacter){
	if(sRxBuffer.ucCharCtr>=RECIEVER_SIZE){
		sRxBuffer.eStatus = OVERFLOW;
	}else if(TERMINATOR == cCharacter){
		sRxBuffer.cData[sRxBuffer.ucCharCtr] = NULL;
		sRxBuffer.ucCharCtr = 0;
		sRxBuffer.eStatus = READY;
	}else{
		sRxBuffer.cData[sRxBuffer.ucCharCtr] = cCharacter;
		sRxBuffer.ucCharCtr++;
	}
}

enum eRecieverStatus eReciever_GetStatus(void){
	return sRxBuffer.eStatus;
}

void Reciever_GetStringCopy(char * ucDestination){
	CopyString(sRxBuffer.cData,ucDestination);
	sRxBuffer.eStatus = EMPTY;
}
