/**
 * @file sketch.ino
 * @brief Main entry point for the Smart Cabine application.
 * 
 * Re-structured to follow the Modest IoT Nano-framework pattern.
 * Logic is delegated to the SmartCabineDevice class.
 */

#include "ModestIoT.h"
#include "SmartCabineDevice.h"

SmartCabineDevice device; ///< Instance of the SmartCabineDevice.

void setup() {
    Serial.begin(115200);
    device.setup();
}

void loop() {
    device.update();
    // No explicit delay needed as update() handles timing for display
    // but a small yield can help with watchdog
    delay(10); 
}
