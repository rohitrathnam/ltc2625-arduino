#include "Arduino.h"
#include <Wire.h>
#include "LTC2625.h"

bool LTC2625::begin(TwoWire *theWire)
{
	_wire = &Wire;
	_i2caddr = LTC2625_GLOBAL_ADDRESS;
	return init();
}

void LTC2625::setVoltage(uint8_t cmd, uint8_t address, uint16_t value)
{
	unint8_t data[3];
	data[0] = cmd + address;
	data[1] = value 
}
