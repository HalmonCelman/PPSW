#include "lancuchy.h"
#include "konwersje.h"
#include "dekodowanie.h"


int main(){

	char cStr1[254];
	CopyString("  test1 0x0021 reset",cStr1);
	unsigned int uicos;
	
	
	DecodeMsg(&cStr1[0]);
	
	
	char * tmp=asToken[0].uValue.pcString;
	//tmp=1[asToken];
	//tmp=2[asToken];
	return 0;
}
