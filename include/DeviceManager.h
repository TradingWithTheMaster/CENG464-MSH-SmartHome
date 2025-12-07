#ifndef DEVICE_MANAGER_H
#define DEVICE_MANAGER_H

#include <map>
#include <string>
#include "Device.h"

class DeviceManager {
private:
    std::map<std::string, Device*> devices;

public:
    DeviceManager();
    ~DeviceManager();

    void addDevice(const std::string& type, const std::string& name);
    void removeDevice(const std::string& name);
    void powerOnDevice(const std::string& name);
    void powerOffDevice(const std::string& name);
    void listDevices() const;
};

#endif
