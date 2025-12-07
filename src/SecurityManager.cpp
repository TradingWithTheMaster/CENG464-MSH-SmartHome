#include "SecurityManager.h"

SecurityManager::SecurityManager(StateManager* stateManager, LogManager* logger)
    : armed(false), stateManager(stateManager), logManager(logger) {}

void SecurityManager::armSystem() {
    armed = true;
    if (logManager)
        logManager->log("Security System Armed");
}

void SecurityManager::disarmSystem() {
    armed = false;
    if (logManager)
        logManager->log("Security System Disarmed");
}

bool SecurityManager::isArmed() const {
    return armed;
}

void SecurityManager::triggerAlarm() {
    if (logManager)
        logManager->log("ALARM TRIGGERED!");

    if (stateManager)
        stateManager->setState(SystemState::ALERT);
}

void SecurityManager::callPolice() {
    if (logManager)
        logManager->log("Police have been notified!");
}
