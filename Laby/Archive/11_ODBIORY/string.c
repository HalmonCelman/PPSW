#include "string.h"

// ***************** czesc 1 ************************

void CopyString(char pcSource[], char pcDestination[]){
	unsigned char ucCharacterCounter;
  for(ucCharacterCounter=0; pcSource[ucCharacterCounter]!=NULL; ucCharacterCounter++){
		pcDestination[ucCharacterCounter]=pcSource[ucCharacterCounter];
  }
	pcDestination[ucCharacterCounter]=NULL;
}


CompResult eCompareString(char pcStr1[], char pcStr2[]){
  for(unsigned char ucCharacterCounter=0; pcStr1[ucCharacterCounter]==pcStr2[ucCharacterCounter]; ucCharacterCounter++){
		if( NULL == pcStr1[ucCharacterCounter]){
			return EQUAL;
    }
  }
	return DIFFRENT;
}

void AppendString (char pcSourceStr[],char pcDestinationStr[]){
  unsigned char ucCharacterCounter;
  for(ucCharacterCounter=0; pcDestinationStr[ucCharacterCounter]!=NULL; ucCharacterCounter++ ){}
  CopyString(pcSourceStr,&pcDestinationStr[ucCharacterCounter]);
}

void ReplaceCharactersInString(char pcString[],char cOldChar,char cNewChar){
  for(unsigned char ucCharacterCounter=0; pcString[ucCharacterCounter]!=NULL; ucCharacterCounter++){
		if(pcString[ucCharacterCounter] == cOldChar){
			pcString[ucCharacterCounter] = cNewChar;
    }
  }
}
//**********************************************************


//********************* czesc 2 *****************************
void UIntToHex(unsigned int uiValue, char pcStr[]){
	pcStr[0]='0';
	pcStr[1]='x';
	char cCurrentNibble;
	for(unsigned char ucNibbleCounter=0;ucNibbleCounter<4;ucNibbleCounter++){
		cCurrentNibble=((uiValue>>(ucNibbleCounter*4)) & 0xF);
		pcStr[5-ucNibbleCounter]=((char)(cCurrentNibble+((cCurrentNibble>9)?('A'-10):('0'))));
	}
	pcStr[6]=NULL;
}

Result eHexStringToUInt(char pcStr[],unsigned int *puiValue){
	if ((pcStr[0] != '0' ) || (pcStr[1] != 'x' ) || (pcStr[2] == NULL )){
		return ERROR;
	}
	*(puiValue)=0;
	char cCurrentNibble;
	for(unsigned char ucCharacterCounter=2;pcStr[ucCharacterCounter]!=NULL;ucCharacterCounter++){
		if(6 == ucCharacterCounter){
			return ERROR;
		}
		cCurrentNibble=pcStr[ucCharacterCounter];
		*(puiValue)=(*(puiValue)<<4)+cCurrentNibble-((cCurrentNibble>='A')?('A'-10):('0'));
	}
	return OK;
}

void AppendUIntToString (unsigned int uiValue, char pcDestinationStr[]){
	unsigned char ucCharacterCounter;
	for(ucCharacterCounter=0;pcDestinationStr[ucCharacterCounter]!=NULL;ucCharacterCounter++);
	UIntToHex(uiValue,&pcDestinationStr[ucCharacterCounter]);
}

//****************************************************************
