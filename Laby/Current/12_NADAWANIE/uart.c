#include <LPC210X.H>
#include "uart.h"
#include "string.h"
/************ UART ************/
// U0LCR Line Control Register
#define mDIVISOR_LATCH_ACCES_BIT                   0x00000080
#define m8BIT_UART_WORD_LENGTH                     0x00000003

// UxIER Interrupt Enable Register
#define mRX_DATA_AVALIABLE_INTERRUPT_ENABLE        0x00000001
#define mTHRE_INTERRUPT_ENABLE                     0x00000002

// UxIIR Pending Interrupt Identification Register
#define mINTERRUPT_PENDING_IDETIFICATION_BITFIELD  0x0000000F
#define mTHRE_INTERRUPT_PENDING                    0x00000002
#define mRX_DATA_AVALIABLE_INTERRUPT_PENDING       0x00000004

/************ Interrupts **********/
// VIC (Vector Interrupt Controller) channels
#define VIC_UART0_CHANNEL_NR  6
#define VIC_UART1_CHANNEL_NR  7

// VICVectCntlx Vector Control Registers
#define mIRQ_SLOT_ENABLE                           0x00000020

#define mUART0_TxD (1<<0)
#define mUART0_RxD (1<<2)
////////////// Zmienne globalne ////////////
char cOdebranyZnak;

struct RecieverBuffer sRxBuffer;
struct TransmiterBuffer sTransmiterBuffer;

char Transmiter_GetCharacterFromBuffer(void);
///////////////////////////////////////////
__irq void UART0_Interrupt (void) {
   // jesli przerwanie z odbiornika (Rx)
   
   unsigned int uiCopyOfU0IIR=U0IIR; // odczyt U0IIR powoduje jego kasowanie wiec lepiej pracowac na kopii

   if      ((uiCopyOfU0IIR & mINTERRUPT_PENDING_IDETIFICATION_BITFIELD) == mRX_DATA_AVALIABLE_INTERRUPT_PENDING) // odebrano znak
   {
      Reciever_PutCharacterToBuffer(U0RBR);
   } 
   
   if ((uiCopyOfU0IIR & mINTERRUPT_PENDING_IDETIFICATION_BITFIELD) == mTHRE_INTERRUPT_PENDING)              // wyslano znak - nadajnik pusty 
   {
		 if(sTransmiterBuffer.eStatus == BUSY ){
      U0THR=Transmiter_GetCharacterFromBuffer();
		 }
   }

   VICVectAddr = 0; // Acknowledge Interrupt
}

////////////////////////////////////////////
void UART_InitWithInt(unsigned int uiBaudRate){

   // UART0
   PINSEL0 = PINSEL0 | mUART0_RxD | mUART0_TxD;                                     // ustawic pina na odbiornik uart0
   U0LCR  |= m8BIT_UART_WORD_LENGTH | mDIVISOR_LATCH_ACCES_BIT; // dlugosc slowa, DLAB = 1
   U0DLL   = ((15000000)/16)/uiBaudRate;                      // predkosc transmisji
   U0LCR  &= (~mDIVISOR_LATCH_ACCES_BIT);                       // DLAB = 0
   U0IER  |= mRX_DATA_AVALIABLE_INTERRUPT_ENABLE | mTHRE_INTERRUPT_ENABLE;               // przerwanie kiedy gotowy odbior

   // INT
   VICVectAddr0  = (unsigned long) UART0_Interrupt;             // set interrupt service routine address
   VICVectCntl0  = mIRQ_SLOT_ENABLE | VIC_UART0_CHANNEL_NR;     // use it for UART 0 Interrupt
   VICIntEnable |= (0x1 << VIC_UART0_CHANNEL_NR);               // Enable UART 0 Interrupt Channel
}

//odbi�r
void Reciever_PutCharacterToBuffer(char cCharacter){
	if(sRxBuffer.ucCharCtr == RECIEVER_SIZE){
		sRxBuffer.eStatus = OVERFLOW;
	}else if(TERMINATOR == cCharacter){
		sRxBuffer.cData[sRxBuffer.ucCharCtr] = NULL;
		sRxBuffer.ucCharCtr = 0;
		sRxBuffer.eStatus = READY;
	}else{
		sRxBuffer.cData[sRxBuffer.ucCharCtr] = cCharacter;
		sRxBuffer.ucCharCtr++;
	}
}

enum eRecieverStatus eReciever_GetStatus(void){
	return sRxBuffer.eStatus;
}

void Reciever_GetStringCopy(char * ucDestination){
	CopyString(sRxBuffer.cData,ucDestination);
	sRxBuffer.eStatus = EMPTY;
}

//nadawanie
char Transmiter_GetCharacterFromBuffer(){
	char cCurrentChar = sTransmiterBuffer.cData[sTransmiterBuffer.cCharCtr];
	
		if(sTransmiterBuffer.fLastCharacter == 1){
			sTransmiterBuffer.eStatus = FREE;
			return NULL;
		}else{
			if(cCurrentChar == NULL){
				sTransmiterBuffer.fLastCharacter=1;
				return TERMINATOR;
			}else{
				sTransmiterBuffer.cCharCtr++;
				return cCurrentChar;
			}
		}
	
}

void Transmiter_SendString(char cString[]){
	while(sTransmiterBuffer.eStatus==BUSY);
	CopyString(cString,sTransmiterBuffer.cData);
	sTransmiterBuffer.cCharCtr=0;
	sTransmiterBuffer.fLastCharacter=0;
	sTransmiterBuffer.eStatus=BUSY;
	U0THR=Transmiter_GetCharacterFromBuffer();
}

enum eTransmiterStatus Transmiter_GetStatus(void){
	return sTransmiterBuffer.eStatus;
}
