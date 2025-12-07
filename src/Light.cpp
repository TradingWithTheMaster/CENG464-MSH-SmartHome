#include "Light.h"
#include <iostream>

Light::Light(int id,
             const std::string& name,
             int brightness)
    : Device(id, name, DeviceType::Light),
      brightness(brightness) {}

// set brightness between 0 and 100
void Light::setBrightness(int value) {
    if (value < 0)  value = 0;
    if (value > 100) value = 100;
    brightness = value;
}

int Light::getBrightness() const {
    return brightness;
}

void Light::turnOn() {
    isActive = true;
    std::cout << "[Light] " << name
              << " powered ON (brightness "
              << brightness << "%)" << std::endl;
}

void Light::turnOff() {
    isActive = false;
    std::cout << "[Light] " << name
              << " powered OFF" << std::endl;
}

std::string Light::getStatus() const {
    return std::string("Light '") + name + "' is "
        + (isActive ? "ON" : "OFF")
        + " (brightness " + std::to_string(brightness) + "%)";
}

void Light::testOperation() {
    std::cout << "[Light] Testing " << name << std::endl;
}
