#include "../include/SecurityManager.h"
#include "../include/LogManager.h"
#include <thread>
#include <chrono>

SecurityManager::SecurityManager(LogManager* logger)
    : log_(logger) {
    if (log_) log_->log("INFO", "SecurityManager initialized.");
}

SecurityManager::~SecurityManager() {
    if (log_) log_->log("INFO", "SecurityManager shutting down.");
}

void SecurityManager::triggerAlarm(const std::string& reason) {
    alarmActive_.store(true);
    alarmAcknowledged_.store(false);
    if (log_) log_->log("ALERT", std::string("Alarm triggered: ") + reason);
}

void SecurityManager::acknowledgeAlarm() {
    alarmAcknowledged_.store(true);
    if (log_) log_->log("INFO", "Alarm acknowledged by user.");
}

bool SecurityManager::isAlarmActive() const {
    return alarmActive_.load();
}

bool SecurityManager::isAlarmAcknowledged() const {
    return alarmAcknowledged_.load();
}

void SecurityManager::detectMotion() {
    if (log_) log_->log("EVENT", "Motion detected by camera.");
}

void SecurityManager::callPolice() {
    if (log_) log_->log("ALERT", "Calling police due to security breach.");
}
