typedef enum {ACTIVE, INACTIVE} DetectorState;

enum ServoState {CALLIB, IDLE, IN_PROGRESS};

struct Servo
{
enum ServoState eState;
unsigned int uiCurrentPosition; 
unsigned int uiDesiredPosition;
}; 

extern struct Servo sServo;

void DetectorInit(void);
DetectorState eReadDetector(void);

void ServoCallib(void);
void ServoInit(unsigned int uiServoFrequency);
void ServoGoTo(unsigned int uiPosition);

