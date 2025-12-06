#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <string>

enum class SystemState {
    IDLE,
    ACTIVE,
    ALERT,
    ERROR
};

class StateManager {
public:
    StateManager();

    void setState(SystemState newState);
    SystemState getCurrentState() const;

    std::string stateToString(SystemState s) const;

private:
    SystemState currentState;
};

#endif
