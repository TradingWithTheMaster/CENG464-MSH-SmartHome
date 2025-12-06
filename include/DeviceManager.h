#ifndef DEVICE_MANAGER_H
#define DEVICE_MANAGER_H

#include "DeviceManagerBase.h"
#include <string>
#include <map>

class LogManager;

class DeviceManager : public DeviceManagerBase {
public:
    explicit DeviceManager(LogManager* logger);
    ~DeviceManager() override;

    void addDevice(const std::string& name) override;
    void removeDevice(const std::string& name) override;
    void setPowerState(const std::string& name, bool on) override;
    std::string getStatus() override;
    void simulateLightFailure(const std::string& name) override;

private:
    LogManager* log_ = nullptr;
    std::map<std::string, bool> devices_;
};

#endif // DEVICE_MANAGER_H
