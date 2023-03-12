#include "funkcje.h"


void CopyString(char pcSource[], char pcDestination[]){
    pcDestination[0]=pcSource[0];
    for(unsigned char ucIterator=1; pcSource[ucIterator-1]!=NUL; ++ucIterator){
        pcDestination[ucIterator]=pcSource[ucIterator];
    }
}


CompResult eCompareString(char pcStr1[], char pcStr2[]){
    for(unsigned char ucIterator=0; ucIterator<MAX_STRING_LENGTH; ++ucIterator){
        if( pcStr1[ucIterator]==pcStr2[ucIterator] ){
            if( pcStr1[ucIterator]==NUL ){
                return EQUAL;
            }
        }else{
           break;
        }
    }
		return DIFFRENT;
}

void AppendString (char pcSourceStr[],char pcDestinationStr[]){
    unsigned char ucNulPosition=0;
    for(; (ucNulPosition<MAX_STRING_LENGTH) && (pcDestinationStr[ucNulPosition]!=NUL); ++ucNulPosition){}
    CopyString(pcSourceStr,&pcDestinationStr[ucNulPosition]);
}

void ReplaceCharactersInString(char pcString[],char cOldChar,char cNewChar){
    for(unsigned char ucIterator=0; pcString[ucIterator]!=NUL; ++ucIterator){
        if(pcString[ucIterator] == cOldChar){
            pcString[ucIterator] = cNewChar;
        }
    }
}
