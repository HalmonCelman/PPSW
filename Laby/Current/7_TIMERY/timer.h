#ifndef TIMER_H
#define TIMER_H

void InitTimer0(void);
void WaitOnTimer0(unsigned int uiTime);

void InitTimer0Match0(unsigned int iDelayTime);
void WaitOnTimer0Match0(void);


#endif
