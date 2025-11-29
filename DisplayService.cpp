#include "DisplayService.h"
#include <Wire.h>

DisplayService::DisplayService(uint8_t addr, uint8_t cols, uint8_t rows) 
    : lcd(addr, cols, rows) {
}

void DisplayService::begin(int sda, int scl) {
    Wire.begin(sda, scl);
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Smart Cabine");
    delay(2000);
    lcd.clear();
}

void DisplayService::showStatus(float temp, float hum, String gasStatus, String gpsLoc) {
    // Cycle 1: Temp & Hum
    lcd.setCursor(0, 0);
    lcd.print("T:" + String(temp, 1) + "C H:" + String(hum, 0) + "%");
    lcd.setCursor(0, 1);
    lcd.print("Gas: " + gasStatus + "    "); // Padding to clear line
}

void DisplayService::showGps(String gpsLoc) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("GPS Location:");
    lcd.setCursor(0, 1);
    lcd.print(gpsLoc.substring(0, 16)); // Ensure it fits
}

