#include "DetectionManager.h"

DetectionManager::DetectionManager(SecurityManager* security, LogManager* logger)
    : securityManager(security), logManager(logger), detectionCount(0) {}

void DetectionManager::detectMotion() {
    detectionCount++;

    if (logManager)
        logManager->log("Motion detected! Count = " + std::to_string(detectionCount));

    if (securityManager && securityManager->isArmed()) {
        triggerAlarm();
    }
}

void DetectionManager::triggerAlarm() {
    if (logManager)
        logManager->log("DetectionManager: Triggering alarm...");

    if (securityManager)
        securityManager->triggerAlarm();
}

void DetectionManager::callPolice() {
    if (logManager)
        logManager->log("DetectionManager: Calling police...");

    if (securityManager)
        securityManager->callPolice();
}
