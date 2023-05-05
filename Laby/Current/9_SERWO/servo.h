#ifndef SERWO_H
#define SERWO_H


#define DETECTOR_bm (1<<10)

typedef enum {ACTIVE, INACTIVE} DetectorState;

enum ServoState {CALLIB, IDLE, IN_PROGRESS};

struct Servo
{
enum ServoState eState; unsigned int
uiCurrentPosition; unsigned int
uiDesiredPosition;
}; 

extern struct Servo sServo;


static void Automat(void);

void DetectorInit(void);
DetectorState eReadDetector(void);

void ServoCallib(void);
void ServoInit(unsigned int uiServoFrequency);
void ServoGoTo(unsigned int uiPosition);

#endif
