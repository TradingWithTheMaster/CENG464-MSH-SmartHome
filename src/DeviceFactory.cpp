#include "DeviceFactory.h"
#include "Light.h"
#include "Camera.h"
#include "TV.h"
#include "Detector.h"

Device* DeviceFactory::createDevice(const std::string& type, const std::string& name) {
    if (type == "Light") return new Light(name);
    if (type == "Camera") return new Camera(name);
    if (type == "TV") return new TV(name);
    if (type == "Detector") return new Detector(name);
    return nullptr;
}
