typedef enum {ACTIVE, INACTIVE} DetectorState;

void DetectorInit(void);
DetectorState eReadDetector(void);

void ServoCallib(void);
void ServoInit(unsigned int uiServoFrequency);
void ServoGoTo(unsigned int uiPosition);

