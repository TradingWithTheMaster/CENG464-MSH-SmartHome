#ifndef MODE_MANAGER_H
#define MODE_MANAGER_H

#include <string>
#include "LogManager.h"

enum class Mode {
    NORMAL,
    PARTY,
    SLEEP,
    AWAY,
    CUSTOM
};

class ModeManager {
public:
    ModeManager(LogManager* logger = nullptr);

    void setMode(Mode newMode);
    Mode getCurrentMode() const;

    std::string modeToString(Mode m) const;

private:
    Mode currentMode;
    LogManager* logManager;
};

#endif
