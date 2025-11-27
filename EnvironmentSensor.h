#ifndef ENVIRONMENT_SENSOR_H
#define ENVIRONMENT_SENSOR_H

#include "Sensor.h"
#include <DHT.h>

class EnvironmentSensor : public Sensor {
private:
    DHT dht;
    float temperature;
    float humidity;

public:
    EnvironmentSensor(uint8_t pin, uint8_t type, EventHandler* eventHandler = nullptr);
    void begin();
    void read();
    float getTemperature() const;
    float getHumidity() const;
};

#endif // ENVIRONMENT_SENSOR_H

