#include "konwersje.h"

//********************* czesc 2 *****************************
void UIntToHex(unsigned int uiValue, char pcStr[]){
	pcStr[0]='0';
	pcStr[1]='x';
	unsigned char ucNibbleValue;
	for(unsigned char ucNibbleCounter=0;ucNibbleCounter<8;ucNibbleCounter++){
		ucNibbleValue=((uiValue>>(ucNibbleCounter*4)) & 0xF);
		pcStr[9-ucNibbleCounter]=((char)(ucNibbleValue+((ucNibbleValue>9)?('A'-10):('0'))));
	}
	pcStr[10]=NULL;
}

Result eHexStringToUInt(char pcStr[],unsigned int *puiValue){
	if (!(('0' == pcStr[0]) && ('x' == pcStr[1]))){
		return ERROR;
	}
	*(puiValue)=0;
	char cCharacterValue;
	for(unsigned char ucCharacterCounter=0;pcStr[ucCharacterCounter]!=NULL;ucCharacterCounter++){
		if(4==ucCharacterCounter){
			return ERROR;
		}
		cCharacterValue=pcStr[ucCharacterCounter+2];
		*(puiValue)=(*(puiValue)<<4)+cCharacterValue-((cCharacterValue>='A')?('A'-10):('0'));
	}
	return OK;
}

void AppendUIntToString (unsigned int uiValue, char pcDestinationStr[]){
	unsigned char ucNullPosition;
	for(ucNullPosition=0;pcDestinationStr[ucNullPosition]!=NULL;ucNullPosition++);
	UIntToHex(uiValue,&pcDestinationStr[ucNullPosition]);
}


//****************************************************************
