#include "EnvironmentSensor.h"

EnvironmentSensor::EnvironmentSensor(uint8_t pin, uint8_t type, EventHandler* eventHandler)
    : Sensor(pin, eventHandler), dht(pin, type), temperature(0.0), humidity(0.0) {
}

void EnvironmentSensor::begin() {
    dht.begin();
}

void EnvironmentSensor::read() {
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();
}

float EnvironmentSensor::getTemperature() const {
    return temperature;
}

float EnvironmentSensor::getHumidity() const {
    return humidity;
}

