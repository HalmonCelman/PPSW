#define TERMINATOR 		';'
#define RECIEVER_SIZE 30

enum eRecieverStatus {EMPTY, READY, OVERFLOW};

struct RecieverBuffer{
char cData[RECIEVER_SIZE];
unsigned char ucCharCtr;
enum eRecieverStatus eStatus;
};

extern struct RecieverBuffer sRxBuffer;

void Reciever_PutCharacterToBuffer(char cCharacter);
enum eRecieverStatus eReciever_GetStatus(void);
void Reciever_GetStringCopy(char * ucDestination);
