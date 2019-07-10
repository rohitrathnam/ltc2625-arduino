#include "Arduino.h"
#include <Wire.h>
#include "LTC2625.h"

bool LTC2625::begin()
{
	_wire = &Wire;
	_i2caddress = LTC2625_GLOBAL_ADDRESS;
	setVoltage(LTC2625_POWER_DOWN, LTC2625_DAC_ALL, 0);
	return init();
}

void LTC2625::setVoltage(uint8_t cmd, uint8_t address, uint16_t value)
{
	unint8_t data[3];
	data[0] = cmd + address;
	data[1] = (value >> 4) & 0xFF;
	data[2] = value & 0x0F;
	_wire -> beginTransmission(_i2caddress);
	_wire -> write(data, 3);
	_wire -> endTransmission();
}
