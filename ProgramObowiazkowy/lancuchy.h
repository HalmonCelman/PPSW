#pragma once

#undef NULL
#define NULL (0)

typedef enum{
DIFFRENT,
EQUAL
} CompResult;

void CopyString(char*, char*);
CompResult eCompareString(char*, char*);
void AppendString (char*,char*);
void ReplaceCharactersInString(char*,char,char);
