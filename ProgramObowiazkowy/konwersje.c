#include "konwersje.h"

//********************* czesc 2 *****************************
void UIntToHex(unsigned int uiValue, char pcStr[]){
	pcStr[0]='0';
	pcStr[1]='x';
	unsigned char ucNibbleValue;
	for(unsigned char ucNibbleCounter=0;ucNibbleCounter<4;ucNibbleCounter++){
		ucNibbleValue=((uiValue>>(ucNibbleCounter*4)) & 0xF);
		pcStr[5-ucNibbleCounter]=((char)(ucNibbleValue+((ucNibbleValue>9)?('A'-10):('0'))));
	}
	pcStr[6]=NULL;
}

Result eHexStringToUInt(char pcStr[],unsigned int *puiValue){
	if (!(('0' == pcStr[0]) && ('x' == pcStr[1]))){
		return ERROR;
	}
	*(puiValue)=0;
	char cCharacterValue;
	for(unsigned char ucCharacterCounter=2;pcStr[ucCharacterCounter]!=NULL;ucCharacterCounter++){
		if(6 == ucCharacterCounter){
			return ERROR;
		}
		cCharacterValue=pcStr[ucCharacterCounter];
		*(puiValue)=(*(puiValue)<<4)+cCharacterValue-((cCharacterValue>='A')?('A'-10):('0'));
	}
	return OK;
}

void AppendUIntToString (unsigned int uiValue, char pcDestinationStr[]){
	unsigned char ucCharacterCounter;
	for(ucCharacterCounter=0;pcDestinationStr[ucCharacterCounter]!=NULL;ucCharacterCounter++);
	UIntToHex(uiValue,&pcDestinationStr[ucCharacterCounter]);
}

//****************************************************************
