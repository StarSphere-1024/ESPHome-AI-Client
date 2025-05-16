#include "AHT20.h"
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

static const char* TAG = "AHT20";

bool AHT20::Initialize() {
    vTaskDelay(pdMS_TO_TICKS(40)); // Initial power-up delay

    uint8_t count = 0;
    while (!IsCalibrated() && count < 10) {
        // Soft reset
        WriteReg(CMD_SOFT_RESET, 0x00);
        vTaskDelay(pdMS_TO_TICKS(200));

        // Send initialization command
        uint8_t init_cmd[] = {CMD_INITIALIZE, 0x08, 0x00};
        i2c_master_transmit(i2c_device_, init_cmd, sizeof(init_cmd), -1);
        vTaskDelay(pdMS_TO_TICKS(500));

        count++;
    }

    if (count >= 10) {
        ESP_LOGE(TAG, "Failed to initialize AHT20 after retries");
        return false;
    }
    return true;
}

bool AHT20::Read(float* temperature, float* humidity) {
    // Trigger measurement
    uint8_t trigger_cmd[] = {CMD_TRIGGER, 0x33, 0x00};
    i2c_master_transmit(i2c_device_, trigger_cmd, sizeof(trigger_cmd), -1);
    vTaskDelay(pdMS_TO_TICKS(75)); // Wait for measurement

    // Wait for busy status to clear
    if (!WaitForMeasurement()) {
        ESP_LOGE(TAG, "Measurement timeout");
        return false;
    }

    // Read 7 bytes (status + 6 bytes of data)
    uint8_t data[7];
    ReadRegs(0x00, data, sizeof(data));

    // Calculate humidity
    uint32_t raw_humidity = ((uint32_t)data[1] << 16) | ((uint32_t)data[2] << 8) | (data[3] >> 4);
    *humidity = (raw_humidity * 100.0f) / 1048576.0f; // 2^20

    // Calculate temperature
    uint32_t raw_temperature = (((uint32_t)(data[3] & 0x0F) << 16) | ((uint32_t)data[4] << 8) | data[5]);
    *temperature = ((raw_temperature * 200.0f) / 1048576.0f) - 50.0f;

    return true;
}

bool AHT20::IsCalibrated() {
    uint8_t status = ReadReg(0x00);
    return (status & 0x68) == 0x08; // Check NOR mode and calibration
}

bool AHT20::WaitForMeasurement() {
    for (int i = 0; i < 100; i++) {
        if (!(ReadReg(0x00) & STATUS_BUSY)) {
            return true;
        }
        vTaskDelay(pdMS_TO_TICKS(1));
    }
    return false;
}