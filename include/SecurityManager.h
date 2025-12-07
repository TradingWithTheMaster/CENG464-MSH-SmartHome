#ifndef SECURITY_MANAGER_H
#define SECURITY_MANAGER_H

#include "StateManager.h"
#include "LogManager.h"

class SecurityManager {
public:
    SecurityManager(StateManager* stateManager = nullptr, LogManager* logger = nullptr);

    void armSystem();
    void disarmSystem();
    bool isArmed() const;

    void triggerAlarm();   
    void callPolice();    
private:
    bool armed;
    StateManager* stateManager;
    LogManager* logManager;
};

#endif
