#ifndef CAMERA_H
#define CAMERA_H

#include "Device.h"

class Camera : public Device {
private:
    std::string resolution;  // example: "1080p"
    int fps;                 // frames per second
    bool nightVision;        // true / false
    bool motionDetection;    // true / false

public:
    // Constructor
    Camera(int id,
           const std::string& name,
           const std::string& resolution = "1080p",
           int fps = 30,
           bool nightVision = true,
           bool motionDetection = true);

    // Camera features
    void enableNightVision(bool enabled);
    void enableMotionDetection(bool enabled);

    // Overrides from Device
    void turnOn() override;
    void turnOff() override;
    std::string getStatus() const override;
    void testOperation() override;
};

#endif // CAMERA_H
