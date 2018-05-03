#include "SevSeg.h"
SevSeg sevseg;
void setup() {
  byte numDigits = 4;
  byte digitPins[] = {9, 10, 11, 12};
  byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8};
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);
}

unsigned long currentTime;
unsigned long lastTime;
int interval = 2000;
long sum = 0.0;
void loop() {
    currentTime = millis();
    if(currentTime - lastTime > interval) {
      sum++;
      lastTime = currentTime;
    }
    // 4 digit, 9999 is max value, any higher than that is not possible, ITLL BREAAAK!
    if(sum < 10000) {
       sevseg.refreshDisplay();
       sevseg.setNumber(sum);
       sevseg.refreshDisplay();
    }
}
