#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <string>
#include "LogManager.h"

enum class SystemState {
    IDLE,
    ACTIVE,
    ALERT,
    ERROR
};

class StateManager {
public:
    StateManager(LogManager* logger = nullptr);

    void setState(SystemState newState);
    SystemState getCurrentState() const;

    std::string stateToString(SystemState s) const;

private:
    SystemState currentState;
    LogManager* logManager;
};

#endif
