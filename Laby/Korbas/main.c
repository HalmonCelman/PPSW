#include <LPC21xx.H>

void Delay(int);

void Delay(int czas){
	for(int i=0;i<czas*8000;i++);
}



int main(void){
	
	IO1DIR |= (1<<16);
	
	
	while(1){
		IO1SET |= (1<<16);
		Delay(1000);
		IO1CLR |= (1<<16);
		Delay(1000);
	}
	
	return 0;
}

