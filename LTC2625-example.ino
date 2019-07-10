#include <Wire.h>
#include "LTC2625.h"

uint8_t data[3] = {0x3F, 0xFF, 0xF0};

void setup()
{
  Serial.begin(9600);
  Serial.println("hiiii");
  LTC2625_begin();
  LTC2625_setVoltage(LTC2625_WRITE_UPDATE, LTC2625_DAC_ALL, 4095);
}

void loop()
{
  uint16_t i=0;
  for(i=0; i<4096; i++)
  {
    LTC2625_setVoltage(LTC2625_WRITE_UPDATE, LTC2625_DAC_ALL, i);
    delay(1);
  }
  for(i=4095; i>0; i--)
  {
    LTC2625_setVoltage(LTC2625_WRITE_UPDATE, LTC2625_DAC_ALL, i);
    delay(1);
  }
}
