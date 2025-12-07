#include "ModeManager.h"

ModeManager::ModeManager(LogManager* logger)
    : currentMode(Mode::NORMAL), logManager(logger) {}

void ModeManager::setMode(Mode newMode) {
    currentMode = newMode;
    if (logManager)
        logManager->log("Mode changed to: " + modeToString(newMode));
}

Mode ModeManager::getCurrentMode() const {
    return currentMode;
}

std::string ModeManager::modeToString(Mode m) const {
    switch (m) {
        case Mode::NORMAL: return "Normal";
        case Mode::PARTY: return "Party";
        case Mode::SLEEP: return "Sleep";
        case Mode::AWAY: return "Away";
        case Mode::CUSTOM: return "Custom";
        default: return "Unknown";
    }
}
