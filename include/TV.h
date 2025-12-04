#ifndef TV_H
#define TV_H

#include "Device.h"

class TV : public Device {
protected:
    int volume;    // 0–100
    int channel;   // current channel number

public:
    TV(int id,
       const std::string& name,
       DeviceType type,
       int volume = 10,
       int channel = 1);

    // Common TV controls
    void setVolume(int value);
    int getVolume() const;

    void setChannel(int ch);
    int getChannel() const;

    // Base implementation for power
    void turnOn() override;
    void turnOff() override;

    // Still abstract for brand-specific behavior
    virtual std::string getStatus() const override = 0;
    virtual void testOperation() override = 0;
};

// -------- SamsungTV --------
class SamsungTV : public TV {
public:
    SamsungTV(int id,
              const std::string& modelName);

    std::string getStatus() const override;
    void testOperation() override;
};

// -------- LGTV --------
class LGTV : public TV {
public:
    LGTV(int id,
         const std::string& modelName);

    std::string getStatus() const override;
    void testOperation() override;
};

#endif // TV_H
