#include "GpsService.h"
#include <Arduino.h>

GpsService::GpsService(HardwareSerial& ser, int rx, int tx) 
    : serial(ser), rxPin(rx), txPin(tx) {
}

void GpsService::begin() {
    serial.begin(9600, SERIAL_8N1, rxPin, txPin);
}

void GpsService::update() {
    while (serial.available() > 0) {
        gps.encode(serial.read());
    }
}

bool GpsService::isValid() {
    return gps.location.isValid();
}

String GpsService::getLocationString() {
    if (gps.location.isValid()) {
        return String(gps.location.lat(), 6) + "," + String(gps.location.lng(), 6);
    }
    return "No Fix";
}

double GpsService::getLatitude() {
    if (gps.location.isValid()) {
        return gps.location.lat();
    }
    return 0.0;  // Return 0.0 if no GPS fix
}

double GpsService::getLongitude() {
    if (gps.location.isValid()) {
        return gps.location.lng();
    }
    return 0.0;  // Return 0.0 if no GPS fix
}


