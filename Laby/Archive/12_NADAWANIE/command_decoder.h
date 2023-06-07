#include "string.h"

#undef NULL
#define NULL (0)


#define MAX_TOKEN_NR 3 //maksymalna dopuszczalna ilosc tokenów
#define MAX_KEYWORD_STRING_LTH 10 // mksymalna dlugosc komendy
#define MAX_KEYWORD_NR 3

typedef enum {CAL,GO,CALC} KeywordCode;
typedef enum {TOKEN,DELIMITER} State;
typedef enum {KEYWORD, NUMBER, STRING} TokenType;

typedef union {
KeywordCode eKeyword; // jezeli KEYWORD
unsigned int uiNumber; // jezeli NUMBER
char * pcString; // jezeli STRING
} TokenValue;

typedef struct
{
TokenType eType; // KEYWORD, NUMBER, STRING
TokenValue uValue; // enum, unsigned int, char*
} Token;

typedef struct{
KeywordCode eCode;
char cString[MAX_KEYWORD_STRING_LTH + 1];
} Keyword;


extern Token asToken[MAX_TOKEN_NR];
extern Keyword asKeywordList[MAX_KEYWORD_NR];
extern unsigned char ucTokenNr;

unsigned char ucFindTokensInString (char*);
Result eStringToKeyword(char*,KeywordCode*);
void DecodeTokens(void);
void DecodeMsg(char *pcString);
