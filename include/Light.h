#ifndef LIGHT_H
#define LIGHT_H

#include "Device.h"

class Light : public Device {
private:
    int brightness;  // 0–100

public:
    // Constructor
    Light(int id,
          const std::string& name,
          int brightness = 100);

    // Brightness controls
    void setBrightness(int value);
    int getBrightness() const;

    // Implement abstract functions from Device
    void turnOn() override;
    void turnOff() override;
    std::string getStatus() const override;
    void testOperation() override;
};

#endif // LIGHT_H
