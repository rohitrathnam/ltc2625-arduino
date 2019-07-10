#define LTC2625_GLOBAL_ADDRESS 0x73		//edit this for custom address if needed

//Command
#define LTC2625_WRITE 0x00
#define LTC2625_POWER_UP 0x10
#define LTC2625_WRITE_UPDATE 0x30
#define LTC2625_POWER_DOWN 0x40

//Address
#define LTC2625_DAC_A 0x00
#define LTC2625_DAC_B 0x01
#define LTC2625_DAC_C 0x02
#define LTC2625_DAC_D 0x03
#define LTC2625_DAC_E 0x04
#define LTC2625_DAC_F 0x05
#define LTC2625_DAC_G 0x06
#define LTC2625_DAC_H 0x07
#define LTC2625_DAC_ALL 0x0F

class LTC2625
{
public:
	LTC2625();
	bool begin();
	void setVoltage(uint8_t cmd, uint8_t address, uint16_t value);
	
protected:
	uint8_t i2c_address;
	TwoWire *_wire;
}
