#include "lancuchy.h"
#include "konwersje.h"
#include "dekodowanie.h"


int main(){

	char cStr1[254];
	CopyString("costam\0",cStr1);

	AppendUIntToString(0xFAB4,cStr1);
	
	return 0;
}
