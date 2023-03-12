/*
by KK
*/
#include <stdio.h>
#include <string.h>
#include "global.h"
#include "funkcje.h"

int main(void){
    char acSourceString1[MAX_STRING_LENGTH];
    char acSourceString2[MAX_STRING_LENGTH];
    
		strcpy(acSourceString1, "string1\0");
		strcpy(acSourceString2, "string2\0");
    AppendString(acSourceString1,acSourceString2);
    
}
