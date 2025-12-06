#ifndef DEVICE_MANAGER_BASE_H
#define DEVICE_MANAGER_BASE_H

#include <string>

class DeviceManagerBase {
public:
    virtual ~DeviceManagerBase() = default;
    virtual void addDevice(const std::string& name) = 0;
    virtual void removeDevice(const std::string& name) = 0;
    virtual void setPowerState(const std::string& name, bool on) = 0;
    virtual std::string getStatus() = 0;
    virtual void simulateLightFailure(const std::string& name) = 0;
};

#endif // DEVICE_MANAGER_BASE_H