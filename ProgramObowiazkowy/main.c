#undef NULL
#define NULL (0)

typedef enum{
DIFFRENT,
EQUAL
} CompResult;



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
  unsigned char ucNullPosition;
  for(ucNullPosition=0; pcDestinationStr[ucNullPosition]!=NULL; ucNullPosition++ ){}
  CopyString(pcSourceStr,&pcDestinationStr[ucNullPosition]);
}

void ReplaceCharactersInString(char pcString[],char cOldChar,char cNewChar){
  for(unsigned char ucCharacterCounter=0; pcString[ucCharacterCounter]!=NULL; ucCharacterCounter++){
		if(pcString[ucCharacterCounter] == cOldChar){
			pcString[ucCharacterCounter] = cNewChar;
    }
  }
}


int main(){
char cStr1[254];

CopyString("sttring2\0",cStr1);

ReplaceCharactersInString(cStr1,'t','A');

return 0;
}
