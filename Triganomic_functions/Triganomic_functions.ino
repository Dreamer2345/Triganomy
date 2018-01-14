#include <FixedPoints.h>
#include <FixedPointsCommon.h>
#include <Arduboy2.h>
Arduboy2 ard;

#include "Trig.h"

uint8_t dex = 0;

void setup() {
  ard.begin();
}

void loop() {
  ard.clear();
  
  for(uint8_t i=0; i<128; ++i)
    {
    ard.drawPixel(i,round(static_cast<float>(Sin(i+dex))*10)+31);
    }
  dex++;
  ard.display();
}
