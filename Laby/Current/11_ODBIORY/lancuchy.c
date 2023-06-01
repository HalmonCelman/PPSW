#include "lancuchy.h"

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
