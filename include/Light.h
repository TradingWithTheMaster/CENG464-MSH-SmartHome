#ifndef LIGHT_H
#define LIGHT_H

#include "Device.h"

class Light : public Device {
public:
    Light(const std::string& name);
    ~Light();
};

#endif
