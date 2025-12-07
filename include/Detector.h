#ifndef DETECTOR_H
#define DETECTOR_H

#include "Device.h"

class Detector : public Device {
public:
    Detector(const std::string& name);
    ~Detector();
};

#endif
