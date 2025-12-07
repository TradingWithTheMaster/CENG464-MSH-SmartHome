#include "DeviceManager.h"
#include "DeviceFactory.h"
#include <iostream>

DeviceManager::DeviceManager() {}

DeviceManager::~DeviceManager() {
    for (auto& pair : devices)
        delete pair.second;
}

void DeviceManager::addDevice(const std::string& type, const std::string& name) {
    if (devices.count(name)) {
        std::cout << "Device already exists.\n";
        return;
    }

    Device* d = DeviceFactory::createDevice(type, name);
    if (!d) {
        std::cout << "Unknown device type.\n";
        return;
    }

    devices[name] = d;
    std::cout << "Added " << type << " named " << name << ".\n";
}

void DeviceManager::removeDevice(const std::string& name) {
    if (!devices.count(name)) {
        std::cout << "Device not found.\n";
        return;
    }

    delete devices[name];
    devices.erase(name);
    std::cout << "Removed device " << name << ".\n";
}

void DeviceManager::powerOnDevice(const std::string& name) {
    if (!devices.count(name)) {
        std::cout << "Device not found.\n";
        return;
    }

    devices[name]->turnOn();
    std::cout << name << " turned ON.\n";
}

void DeviceManager::powerOffDevice(const std::string& name) {
    if (!devices.count(name)) {
        std::cout << "Device not found.\n";
        return;
    }

    devices[name]->turnOff();
    std::cout << name << " turned OFF.\n";
}

void DeviceManager::listDevices() const {
    if (devices.empty()) {
        std::cout << "No devices added.\n";
        return;
    }

    for (const auto& pair : devices)
        std::cout << pair.first << ": " << pair.second->getStatus() << "\n";
}
