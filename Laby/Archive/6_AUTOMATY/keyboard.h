#ifndef KEYBOARD_H
#define KEYBOARD_H


#define KEY0_bm (1<<4)
#define KEY1_bm (1<<6)
#define KEY2_bm (1<<5)
#define KEY3_bm (1<<7)

typedef enum {RELEASED,BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3} KeyboardState;

KeyboardState eKeyboardRead(void);
void KeyboardInit(void);

#endif
