#ifndef MODE_MANAGER_H
#define MODE_MANAGER_H

#include "ModeManagerBase.h"
#include <string>

class LogManager;

class ModeManager : public ModeManagerBase {
public:
    explicit ModeManager(LogManager* logger);
    ~ModeManager() override;

    void changeMode(const std::string& mode) override;
    std::string getMode() override;

private:
    LogManager* log_ = nullptr;
    std::string currentMode_ = "Home";
};

#endif // MODE_MANAGER_H
