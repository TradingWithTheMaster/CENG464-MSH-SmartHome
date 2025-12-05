#ifndef DETECTOR_H
#define DETECTOR_H

#include "Device.h"

class Detector : public Device {
protected:
    bool critical;   // critical devices should usually always stay active

public:
    Detector(int id,
             const std::string& name,
             DeviceType type,
             bool critical = true);

    bool isCritical() const { return critical; }

    // Default power behavior (can be overridden)
    void turnOn() override;
    void turnOff() override;

    // Still abstract – specific detectors implement these:
    virtual std::string getStatus() const override = 0;
    virtual void testOperation() override = 0;
};

// -------- SmokeDetector --------
class SmokeDetector : public Detector {
public:
    SmokeDetector(int id,
                  const std::string& name);

    std::string getStatus() const override;
    void testOperation() override;
};

// -------- GasDetector --------
class GasDetector : public Detector {
public:
    GasDetector(int id,
                const std::string& name);

    std::string getStatus() const override;
    void testOperation() override;
};

// -------- Alarm --------
class Alarm : public Detector {
public:
    Alarm(int id,
          const std::string& name);

    void turnOff() override;  // alarms might have special turnOff rules
    std::string getStatus() const override;
    void testOperation() override;
};

#endif // DETECTOR_H
