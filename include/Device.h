#ifndef DEVICE_H
#define DEVICE_H

#include <string>

class Device {
protected:
    std::string name;
    bool power;

public:
    Device(const std::string& name);
    virtual ~Device();

    virtual void turnOn();
    virtual void turnOff();
    virtual std::string getStatus() const;
    virtual bool testOperation() const;

    std::string getName() const { return name; }
};

#endif
