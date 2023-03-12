/*
by KK
*/
#include <stdio.h>
#include "global.h"
#include "funkcje.h"

int main(void){
    char acSourceString1[MAX_STRING_LENGTH];
    char acSourceString2[MAX_STRING_LENGTH];
    char cOldChar,cNewChar;
    fgets(acSourceString1, MAX_STRING_LENGTH, stdin);
    fgets(acSourceString2, MAX_STRING_LENGTH, stdin);
    
    ReplaceCharactersInString(acSourceString1,'t','a');
    
    puts(acSourceString1);

}
