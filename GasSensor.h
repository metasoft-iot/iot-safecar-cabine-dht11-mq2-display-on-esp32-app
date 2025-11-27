#ifndef GAS_SENSOR_H
#define GAS_SENSOR_H

#include "Sensor.h"
#include <Arduino.h>

class GasSensor : public Sensor {
private:
    int value;

public:
    GasSensor(uint8_t analogPin, EventHandler* eventHandler = nullptr);
    void begin();
    void read();
    int getValue() const;
    String getStatus() const;
};

#endif // GAS_SENSOR_H

