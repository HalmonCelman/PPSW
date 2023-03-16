#undef NULL
#define NULL (0)

// ***************** czesc 1 ************************

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
//**********************************************************

//********************* czesc 2 *****************************

typedef enum{
OK,
ERROR
} Result;

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


int main(){

	char cStr1[254];
	CopyString("costam\0",cStr1);

	AppendUIntToString(0xFAB4,cStr1);
	
	return 0;
}
