#ifndef vision_h
#define vision_h

#include "Arduino.h"
#include "Modular.h"
#include "Pixy.h"
#include <SPI.h>

#define VISION_MAX_X 320
#define VISION_MAX_Y 200
#define TARGET_LOST_COUNT 10

struct VisionState {
  int targetSignature = 1;
  int targetDistance = -1;
  int targetDeviation = 0; // minus is left, plus is right
};

class Vision : public Component
{
  public:
    Vision();
    void loop(VisionState *state);
    void reset();
    void setTarget(int signature);
  protected:
    VisionState currentState;
    Pixy myPixy;
    int x;
    int y;
    int lostCount;
};

#endif
