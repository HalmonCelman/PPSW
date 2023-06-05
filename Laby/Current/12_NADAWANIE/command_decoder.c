#include "command_decoder.h"


Token asToken[MAX_TOKEN_NR];

Keyword asKeywordList[MAX_KEYWORD_NR]={
{CALC,"calc"}
};

unsigned char ucTokenNr;

unsigned char ucFindTokensInString (char *pcString){
	unsigned char ucTokenCounter=0;
	State eState=DELIMITER;
	char cCurrentCharacter;
	for(unsigned char ucCharacterCounter=0;;ucCharacterCounter++){
		cCurrentCharacter = pcString[ucCharacterCounter];
		switch(eState){
			case TOKEN:
				if(NULL == cCurrentCharacter){
					return ucTokenCounter;
				}
				else if(' ' == cCurrentCharacter){
					eState=DELIMITER;
				}
				break;
			case DELIMITER:
				if(MAX_TOKEN_NR == ucTokenCounter){
					return ucTokenCounter;
				}
				else if(NULL == cCurrentCharacter){
					return ucTokenCounter;
				}
				else if(cCurrentCharacter!=' '){
					asToken[ucTokenCounter].uValue.pcString=&pcString[ucCharacterCounter];
					ucTokenCounter++;
					eState=TOKEN;
				}
				break;
		}
		
	}
}

Result eStringToKeyword (char pcStr[],KeywordCode *peKeywordCode){
	unsigned char ucDelimiterPosition;
  for(ucDelimiterPosition=0; (pcStr[ucDelimiterPosition]!=NULL) && (pcStr[ucDelimiterPosition]!=' '); ucDelimiterPosition++ );

	for(unsigned char ucKeywordCounter=0;ucKeywordCounter<MAX_KEYWORD_NR;ucKeywordCounter++){
		
		if(EQUAL == eCompareString(pcStr,asKeywordList[ucKeywordCounter].cString)){
			*(peKeywordCode)=asKeywordList[ucKeywordCounter].eCode;
			return OK;
		}
	}
	return ERROR;
}

void DecodeTokens(void){
	for(unsigned char ucTokenCounter=0; ucTokenCounter<ucTokenNr;ucTokenCounter++){
		Token *sCurrentToken = &asToken[ucTokenCounter];
		
		if(OK == eStringToKeyword(sCurrentToken->uValue.pcString,&sCurrentToken->uValue.eKeyword)){
			sCurrentToken->eType = KEYWORD;
		}
		else if(OK == eHexStringToUInt(sCurrentToken->uValue.pcString,&(sCurrentToken->uValue.uiNumber))){
			sCurrentToken->eType = NUMBER;
		}
		else{
			sCurrentToken->eType = STRING;
		}
	}
}

void DecodeMsg(char *pcString){
	ucTokenNr=ucFindTokensInString(pcString);
	ReplaceCharactersInString(pcString,' ',NULL);
	DecodeTokens();
}
