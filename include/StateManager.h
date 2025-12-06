#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "StateManagerBase.h"
#include <string>

class LogManager;

class StateManager : public StateManagerBase {
public:
    explicit StateManager(LogManager* logger);
    ~StateManager() override;

    void changeState(const std::string& state) override;
    void displayStatus() override;
    void updateSensors() override;

private:
    LogManager* log_ = nullptr;
    std::string lastState_ = "OK";
};

#endif // STATE_MANAGER_H
