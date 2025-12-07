#ifndef TV_H
#define TV_H

#include "Device.h"

class TV : public Device {
public:
    TV(const std::string& name);
    ~TV();
};

#endif
