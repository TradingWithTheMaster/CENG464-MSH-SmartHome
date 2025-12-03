#ifndef MODE_MANAGER_BASE_H
#define MODE_MANAGER_BASE_H

class ModeManagerBase {
public:
    // Virtual destructor is necessary when using base class pointers
    virtual ~ModeManagerBase() = default; 

};

#endif // MODE_MANAGER_BASE_H