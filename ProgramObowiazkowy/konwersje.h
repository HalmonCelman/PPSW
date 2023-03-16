#pragma once

#undef NULL
#define NULL (0)

typedef enum{
OK,
ERROR
} Result;

void UIntToHex(unsigned int, char*);
Result eHexStringToUInt(char*,unsigned int*);
void AppendUIntToString (unsigned int, char*);
