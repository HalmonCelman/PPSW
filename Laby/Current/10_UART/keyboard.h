typedef enum {RELEASED,BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3} KeyboardState;

KeyboardState eKeyboardRead(void);
void KeyboardInit(void);
