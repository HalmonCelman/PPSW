#ifndef LED_H
#define LED_H

#define LED0_bm (1<<16)
#define LED1_bm (1<<17)
#define LED2_bm (1<<18)
#define LED3_bm (1<<19)

typedef enum {LEFT,RIGHT} StepSide;

void LedInit(void);
void LedOn(unsigned char ucLedIndeks);
static void LedStep(StepSide eStepSide);
void LedStepLeft(void);
void LedStepRight(void);

#endif
