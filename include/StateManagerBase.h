#ifndef STATE_MANAGER_BASE_H
#define STATE_MANAGER_BASE_H

#include <string>

class StateManagerBase {
public:
    virtual ~StateManagerBase() = default;
    virtual void changeState(const std::string& state) = 0;
    virtual void displayStatus() = 0;
    virtual void updateSensors() = 0;
};

#endif // STATE_MANAGER_BASE_H