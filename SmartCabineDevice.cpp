#include "SmartCabineDevice.h"
#include <Arduino.h>

SmartCabineDevice::SmartCabineDevice()
    : dhtSensor(DHT_PIN, DHT_TYPE),
      mq2Sensor(MQ2_PIN),
      led(LED_PIN),
      gpsService(Serial2, GPS_RX_PIN, GPS_TX_PIN),
      display(LCD_ADDR, LCD_COLS, LCD_ROWS),
      lastUpdate(0),
      showGpsPage(false) {
}

void SmartCabineDevice::setup() {
    Serial.println("Initializing Smart Cabine...");
    
    dhtSensor.begin();
    mq2Sensor.begin();
    gpsService.begin();
    display.begin();
    
    // LED initialized in constructor
    led.setState(false);

    Serial.println("System Ready.");
}

void SmartCabineDevice::update() {
    // 1. Update Sensors
    dhtSensor.read();
    mq2Sensor.read();
    gpsService.update(); // Call frequently for serial buffer

    // 2. Logic: Check gas levels
    // Logic > 1000 means gas detected
    if (mq2Sensor.getValue() > 1000) {
        on(Event(EVENT_GAS_DETECTED));
    } else {
        on(Event(EVENT_AIR_CLEAN));
    }

    // 3. Display Update (Every 2 seconds)
    if (millis() - lastUpdate > 2000) {
        lastUpdate = millis();
        
        Serial.printf("Temp: %.1f C, Hum: %.1f %%, Gas: %d (%s), GPS: %s\n", 
            dhtSensor.getTemperature(), 
            dhtSensor.getHumidity(), 
            mq2Sensor.getValue(),
            mq2Sensor.getStatus().c_str(),
            gpsService.getLocationString().c_str()
        );

        if (showGpsPage) {
            display.showGps(gpsService.getLocationString());
        } else {
            display.showStatus(
                dhtSensor.getTemperature(), 
                dhtSensor.getHumidity(), 
                mq2Sensor.getStatus(), 
                gpsService.getLocationString()
            );
        }
        showGpsPage = !showGpsPage;
    }
}

void SmartCabineDevice::on(Event event) {
    if (event.id == EVENT_GAS_DETECTED) {
        led.handle(Led::TURN_ON_COMMAND);
    } else if (event.id == EVENT_AIR_CLEAN) {
        led.handle(Led::TURN_OFF_COMMAND);
    }
}

void SmartCabineDevice::handle(Command command) {
    led.handle(command);
}

EnvironmentSensor& SmartCabineDevice::getEnvironmentSensor() {
    return dhtSensor;
}

GasSensor& SmartCabineDevice::getGasSensor() {
    return mq2Sensor;
}

Led& SmartCabineDevice::getLed() {
    return led;
}

