#include "SecurityManager.h"

SecurityManager::SecurityManager() : armed(false) {}

void SecurityManager::armSystem() {
    armed = true;
}

void SecurityManager::disarmSystem() {
    armed = false;
}

bool SecurityManager::isArmed() const {
    return armed;
}
