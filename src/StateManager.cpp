#include "StateManager.h"

StateManager::StateManager(LogManager* logger)
    : currentState(SystemState::IDLE), logManager(logger) {}

void StateManager::setState(SystemState newState) {
    currentState = newState;
    if (logManager)
        logManager->log("System state changed to: " + stateToString(newState));
}

SystemState StateManager::getCurrentState() const {
    return currentState;
}

std::string StateManager::stateToString(SystemState s) const {
    switch (s) {
        case SystemState::IDLE:   return "Idle";
        case SystemState::ACTIVE: return "Active";
        case SystemState::ALERT:  return "Alert";
        case SystemState::ERROR:  return "Error";
        default: return "Unknown";
    }
}
