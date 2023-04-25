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
	// test wartosci skrajnych
	UIntToHex(0,cConversionDestination);
	UIntToHex(65535,cConversionDestination);
	
	// test konwersji na uint
	unsigned int uiConversionDestination;
	Result eConversionResult;
	// wartosc poprawna
	eConversionResult= eHexStringToUInt("0xFA57",&uiConversionDestination);
	// ciag pusty
	eConversionResult= eHexStringToUInt("",&uiConversionDestination);
	// za duzo znakow po 0x
	eConversionResult= eHexStringToUInt("0x33333",&uiConversionDestination);
	// NULL tuz po 0x
	eConversionResult= eHexStringToUInt("0x",&uiConversionDestination);
	
	char cDestinationString[254]={"555"};
	AppendUIntToString(0x555,cDestinationString);
	
	///testy do dekodowania
	
	//pusty komunikat
	char cKomunikat[254]={"    "};
	unsigned char ucNumberOfTokens;
	
	ucNumberOfTokens = ucFindTokensInString(cKomunikat);
	
	//delimiter przed tokenem, wiecej niz jeden delimiter
	CopyString(" komunikat2  reset 0x2023",cKomunikat);
	ucNumberOfTokens = ucFindTokensInString(cKomunikat);
	Token *eFoundToken1=&asToken[0];
	Token *eFoundToken2=&asToken[1];
	Token *eFoundToken3=&asToken[2];
	
	//poprawne slowo kluczowe
	CopyString("reset",cKomunikat);
	Result eResult;
	eResult = eStringToKeyword(cKomunikat, &eFoundToken1->uValue.eKeyword);
	
	//niepoprawne slowo kluczowe
	CopyString(" reset",cKomunikat);
	eResult = eStringToKeyword(cKomunikat, &eFoundToken1->uValue.eKeyword);
	
	//jeszcze raz ten sam komuniat
	CopyString(" komunikat2  reset 0x20",cKomunikat);
	ucTokenNr=ucFindTokensInString(cKomunikat); //dane dla DecodeTokens() musza byc przygotowane
	ReplaceCharactersInString(cKomunikat,' ',NULL);
	DecodeTokens();
	
	//ostateczne odczytanie komunikatu
	DecodeMsg("   load komunikat 0x1980");
	
	return 0;
}
