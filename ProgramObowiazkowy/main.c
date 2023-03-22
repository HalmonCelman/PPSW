#include "lancuchy.h"
#include "konwersje.h"
#include "dekodowanie.h"


int main(){

	char cStr1[254];
	CopyString("  test1 0x0021 reset",cStr1);
	unsigned int uicos;
	
	
	//DecodeMsg(cStr1);
	
	
	//char * tmp=asToken[0].uValue.pcString;
	//tmp=1[asToken];
	//tmp=2[asToken];
	
	UIntToHex(0xFBC2,cStr1);
	eHexStringToUInt(cStr1,&uicos);
	
	return 0;
}
