#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"

KeyboardState eKeyboardRead(void){
	if (0 == (IO0PIN & KEY0_bm)){
		return BUTTON_0;
	}else if(0 == (IO0PIN & KEY1_bm)){
		return BUTTON_1;
	}else if(0 == (IO0PIN & KEY2_bm)){
		return BUTTON_2;
	}else if(0 == (IO0PIN & KEY3_bm)){
		return BUTTON_3;
	}
	return RELEASED;
}


void KeyboardInit(void){
	IO0DIR &=~ (KEY0_bm | KEY1_bm | KEY2_bm | KEY3_bm);
}
