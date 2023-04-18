#include <stdio.h>

#include "lancuchy.h"
#include "konwersje.h"
#include "dekodowanie.h"
#include "testy.h"


int main(){
  /// testy do konwersji
	// test konwersji na HEX
	char cConversionDestination[7];
	UIntToHex(6500,cConversionDestination);
	// test warto[ci skrajnych
	UIntToHex(0,cConversionDestination);
	UIntToHex(8503,cConversionDestination);
	UIntToHex(65535,cConversionDestination);
	
	// test konwersji na uint
	unsigned int uiConversionDestination;
	Result eConversionResult;
	// wartosc poprawna
	eConversionResult= eHexStringToUInt("0x2137",&uiConversionDestination);
	// ciag pusty
	eConversionResult= eHexStringToUInt("",&uiConversionDestination);
	// za duzo znakow po 0x
	eConversionResult= eHexStringToUInt("0x213769",&uiConversionDestination);
	// po 0x NULL
	eConversionResult= eHexStringToUInt("0x",&uiConversionDestination);
	
	char cDestinationString[254]={"555"};
	AppendUIntToString(0x555,cDestinationString);
	
	///testy do dekodowania
	
	return 0;
}
