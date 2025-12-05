#ifndef DEVICE_H
#define DEVICE_H

#include <string>

enum class DeviceType {
    Light,
    Camera,
    SamsungTV,
    LGTV,
    SmokeDetector,
    GasDetector,
    Alarm
};

class Device {
protected:
    int id;
    std::string name;
    DeviceType type;
    bool isActive;
    bool isBroken;

public:
    Device(int id,
           const std::string& name,
           DeviceType type)
        : id(id), name(name), type(type),
          isActive(false), isBroken(false) {}

    virtual ~Device() = default;

    int getId() const { return id; }
    std::string getName() const { return name; }
    DeviceType getType() const { return type; }

    bool getIsActive() const { return isActive; }
    bool getIsBroken() const { return isBroken; }

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;

    virtual std::string getStatus() const = 0;
    virtual void testOperation() = 0;
};

#endif // DEVICE_H
