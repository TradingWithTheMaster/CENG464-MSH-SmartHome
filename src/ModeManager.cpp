#include "ModeManager.h"

ModeManager::ModeManager() : currentMode(Mode::NORMAL) {}

void ModeManager::setMode(Mode newMode) {
    currentMode = newMode;
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
