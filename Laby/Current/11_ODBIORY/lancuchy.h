#pragma once

#undef NULL
#define NULL (0)

typedef enum{
DIFFRENT,
EQUAL
} CompResult;

void CopyString(char pcSource[], char pcDestination[]);
CompResult eCompareString(char pcStr1[], char pcStr2[]);
void AppendString (char pcSourceStr[],char pcDestinationStr[]);
void ReplaceCharactersInString(char pcString[],char cOldChar,char cNewChar);
