#ifndef MODE_MANAGER_BASE_H
#define MODE_MANAGER_BASE_H

#include <string>

class ModeManagerBase {
public:
    virtual ~ModeManagerBase() = default;
    virtual void changeMode(const std::string& mode) = 0;
    virtual std::string getMode() = 0;
};

#endif // MODE_MANAGER_BASE_H