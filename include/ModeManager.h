#ifndef MODE_MANAGER_H
#define MODE_MANAGER_H

#include <string>

enum class Mode {
    NORMAL,
    PARTY,
    SLEEP,
    AWAY,
    CUSTOM
};

class ModeManager {
public:
    ModeManager();

    void setMode(Mode newMode);
    Mode getCurrentMode() const;

    std::string modeToString(Mode m) const;

private:
    Mode currentMode;
};

#endif
