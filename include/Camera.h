#ifndef CAMERA_H
#define CAMERA_H

#include "Device.h"

class Camera : public Device {
public:
    Camera(const std::string& name);
    ~Camera();
};

#endif
