#ifndef DEVICE_FACTORY_H
#define DEVICE_FACTORY_H

#include <memory>
#include <string>

#include "Device.h"
#include "Light.h"
#include "Camera.h"
#include "TV.h"
#include "Detector.h"

class DeviceFactory {
public:
    // Create a device of the given type
    // (Implementation will be in DeviceFactory.cpp later)
    static std::unique_ptr<Device> createDevice(DeviceType type,
                                                int id,
                                                const std::string& name);
};

#endif // DEVICE_FACTORY_H
