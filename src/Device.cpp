#include "Device.h"

Device::Device(const std::string& name) : name(name), power(false) {}
Device::~Device() {}

void Device::turnOn() {
    power = true;
}

void Device::turnOff() {
    power = false;
}

std::string Device::getStatus() const {
    return power ? name + " is ON" : name + " is OFF";
}

bool Device::testOperation() const {
    return power;
}
