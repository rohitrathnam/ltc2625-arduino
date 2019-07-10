#include "Arduino.h"
#include <Wire.h>
#include "LTC2625.h"

void LTC2625_begin()
{
	Wire.begin(LTC2625_GLOBAL_ADDRESS);
	LTC2625_setVoltage(LTC2625_POWER_DOWN, LTC2625_DAC_ALL, 0);
}

void LTC2625_setVoltage(uint8_t cmd, uint8_t address, uint16_t value)
{
	uint8_t data[3];
	data[0] = cmd + address;
	data[1] = (value >> 4) & 0xFF;
	data[2] = value & 0x0F;
	Wire.beginTransmission(LTC2625_GLOBAL_ADDRESS);
	Wire.write(data, 3);
	Wire.endTransmission();
}
