#ifndef AHT20_H
#define AHT20_H

#include "boards\common\i2c_device.h"

class AHT20 : public I2cDevice {
public:
    // AHT20 I2C address is 0x38
    AHT20(i2c_master_bus_handle_t i2c_bus) : I2cDevice(i2c_bus, 0x38) {}

    // Initialize the sensor
    bool Initialize();

    // Trigger measurement and read temperature and humidity
    bool Read(float* temperature, float* humidity);

private:
    static constexpr uint8_t CMD_INITIALIZE = 0xBE;
    static constexpr uint8_t CMD_TRIGGER = 0xAC;
    static constexpr uint8_t CMD_SOFT_RESET = 0xBA;
    static constexpr uint8_t STATUS_BUSY = 0x80;

    // Check if sensor is calibrated
    bool IsCalibrated();

    // Wait for measurement to complete
    bool WaitForMeasurement();
};

#endif // AHT20_H