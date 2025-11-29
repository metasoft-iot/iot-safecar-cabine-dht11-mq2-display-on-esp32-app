#ifndef SMART_CABINE_DEVICE_H
#define SMART_CABINE_DEVICE_H

#include "Device.h"
#include "EnvironmentSensor.h"
#include "GasSensor.h"
#include "Led.h"
#include "GpsService.h"
#include "DisplayService.h"
#include "EdgeServiceClient.h"  // HTTP client for Edge Service

class SmartCabineDevice : public Device {
private:
    EnvironmentSensor dhtSensor;
    GasSensor mq2Sensor;
    Led led;
    GpsService gpsService;
    DisplayService display;
    EdgeServiceClient edgeClient;  // Edge service client
    
    unsigned long lastUpdate;
    unsigned long lastSend;        // Timestamp for telemetry sending
    bool showGpsPage;

public:
    // Constants for pins
    static const int DHT_PIN = 5;
    static const int DHT_TYPE = DHT11;
    static const int MQ2_PIN = 23;
    static const int LED_PIN = 2;
    static const int GPS_RX_PIN = 16;
    static const int GPS_TX_PIN = 17;
    static const int LCD_ADDR = 0x27;
    static const int LCD_COLS = 16;
    static const int LCD_ROWS = 2;
    static const int LCD_SDA = 21;
    static const int LCD_SCL = 22;

    // Event IDs
    static const int EVENT_GAS_DETECTED = 20;
    static const int EVENT_AIR_CLEAN = 21;

    // Telemetry Sending Interval
    static const unsigned long SEND_INTERVAL = 10000;  // Send every 10 seconds

    SmartCabineDevice();

    void setup();
    void update(); // Main loop logic

    // Device interface implementation
    void on(Event event) override;
    void handle(Command command) override;

    // Accessors
    EnvironmentSensor& getEnvironmentSensor();
    GasSensor& getGasSensor();
    Led& getLed();
};

#endif // SMART_CABINE_DEVICE_H

