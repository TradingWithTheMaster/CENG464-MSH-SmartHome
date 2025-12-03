#ifndef DEVICE_MANAGER_BASE_H
#define DEVICE_MANAGER_BASE_H

class DeviceManagerBase {
public:
    // A virtual destructor is critical for proper cleanup when using pointers to base classes
    virtual ~DeviceManagerBase() = default; 

    // Add pure virtual methods (functions = 0) here later, but for now, the skeleton is enough.
};

#endif // DEVICE_MANAGER_BASE_H