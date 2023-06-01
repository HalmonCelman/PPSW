__irq void UART0_Interrupt (void);
void UART_InitWithInt(unsigned int uiBaudRate);

extern char cOdebranyZnak;


#define TERMINATOR 		'\r'
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
