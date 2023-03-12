#include "funkcje.h"


void CopyString(char pcSource[], char pcDestination[]){
    while(*(pcSource))
        *(pcDestination++)=*(pcSource++);
}



CompResult eCompareString(char * pcStr1, char * pcStr2){
    while(*(pcStr1)==*(pcStr2++))
        if(!(*(pcStr1++))) return EQUAL;
    return DIFFRENT;
}

void AppendString (char pcSourceStr[],char pcDestinationStr[]){
    while(*(pcDestinationStr++));
    CopyString(pcSourceStr,pcDestinationStr-1);
}

void ReplaceCharactersInString(char pcString[],char cOldChar,char cNewChar){
    pcString-=1;
    while(*(++pcString))
        if(*(pcString)==cOldChar) *(pcString)=cNewChar;
}