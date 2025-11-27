#ifndef DISPLAY_SERVICE_H
#define DISPLAY_SERVICE_H

#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

class DisplayService {
private:
    LiquidCrystal_I2C lcd;

public:
    DisplayService(uint8_t addr, uint8_t cols, uint8_t rows);
    void begin();
    void showStatus(float temp, float hum, String gasStatus, String gpsLoc);
    void showGps(String gpsLoc);
};

#endif // DISPLAY_SERVICE_H

