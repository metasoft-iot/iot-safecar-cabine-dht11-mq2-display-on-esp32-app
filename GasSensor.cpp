#include "GasSensor.h"

GasSensor::GasSensor(uint8_t analogPin, EventHandler* eventHandler)
    : Sensor(analogPin, eventHandler), value(0) {
}

void GasSensor::begin() {
    pinMode(pin, INPUT);
}

void GasSensor::read() {
    value = analogRead(pin);
}

int GasSensor::getValue() const {
    return value;
}

String GasSensor::getStatus() const {
    if (value < 1000) return "Clean";
    if (value < 2500) return "Warning";
    return "Danger";
}

