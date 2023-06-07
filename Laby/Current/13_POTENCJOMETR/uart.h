__irq void UART0_Interrupt (void);
void UART_InitWithInt(unsigned int uiBaudRate);

extern char cOdebranyZnak;


#define TERMINATOR 		'\r'
#define RECIEVER_SIZE 30
#define TRANSMITER_SIZE 30

//odbiór
enum eRecieverStatus {EMPTY, READY, OVERFLOW};
enum eTransmiterStatus {FREE, BUSY};


struct RecieverBuffer{
char cData[RECIEVER_SIZE];
unsigned char ucCharCtr;
enum eRecieverStatus eStatus;
};

struct TransmiterBuffer{
char cData[TRANSMITER_SIZE];
enum eTransmiterStatus eStatus;
unsigned char fLastCharacter;
unsigned char cCharCtr;
};

extern struct RecieverBuffer sRxBuffer;
extern struct TransmiterBuffer sTransmiterBuffer;

void Reciever_PutCharacterToBuffer(char cCharacter);
enum eRecieverStatus eReciever_GetStatus(void);
void Reciever_GetStringCopy(char * ucDestination);

void Transmiter_SendString(char cString[]);
enum eTransmiterStatus Transmiter_GetStatus(void);
