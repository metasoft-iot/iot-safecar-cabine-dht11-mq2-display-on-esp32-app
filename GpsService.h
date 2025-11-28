#ifndef GPS_SERVICE_H
#define GPS_SERVICE_H

#include <TinyGPS++.h>
#include <HardwareSerial.h>

class GpsService {
private:
    TinyGPSPlus gps;
    HardwareSerial& serial;
    int rxPin;
    int txPin;

public:
    GpsService(HardwareSerial& ser, int rx, int tx);
    void begin();
    void update();
    bool isValid();
    String getLocationString();
    double getLatitude();
    double getLongitude();
};

#endif // GPS_SERVICE_H

