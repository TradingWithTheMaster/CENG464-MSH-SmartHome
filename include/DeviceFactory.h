#ifndef DEVICE_FACTORY_H
#define DEVICE_FACTORY_H

#include <string>
#include "Device.h"

class DeviceFactory {
public:
    static Device* createDevice(const std::string& type, const std::string& name);
};

#endif
