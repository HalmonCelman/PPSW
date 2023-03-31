#include "testy.h"

void TestOf_CopyString(void){
  // deklaracje zmiennych pomocniczych
	char cDestinationStr[10];
	
	printf("CopyString\n\n ");
	printf ("Test 1 - ");
	// czy NULL jest kopiowany
	CopyString("test1",cDestinationStr);
	if (NULL==cDestinationStr[5]) printf("OK\n"); else printf("Error\n");
	
	printf ("Test 2 - ");
	// czy caly string jest poprawnie skopiowany
	CopyString("testDrugi",cDestinationStr);
	if (strcmp(cDestinationStr,"testDrugi")==0) printf("OK\n"); else printf("Error\n");

}
