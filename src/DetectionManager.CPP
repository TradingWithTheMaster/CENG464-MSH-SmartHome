#include "../include/DetectionManager.h"
#include "../include/SecurityManager.h"
#include "../include/LogManager.h"

DetectionManager::DetectionManager(SecurityManager* security, LogManager* logger)
    : security_(security), log_(logger), detectionCount_(0) {}

DetectionManager::~DetectionManager() {}

void DetectionManager::detectMotion() {
    detectionCount_++;

    if (log_)
        log_->log("INFO", "Motion detected! Count = " + std::to_string(detectionCount_));

    if (security_)
        security_->triggerAlarm("Motion detected");
}

void DetectionManager::triggerAlarm() {
    if (log_)
        log_->log("ALERT", "DetectionManager: Triggering alarm...");

    if (security_)
        security_->triggerAlarm("Forced alarm trigger");
}

void DetectionManager::callPolice() {
    if (log_)
        log_->log("ALERT", "DetectionManager: Calling police...");

    if (security_)
        security_->callPolice();
}