#include "../include/StateManager.h"
#include "../include/LogManager.h"
#include <iostream>

StateManager::StateManager(LogManager* logger)
    : log_(logger) {
    if (log_) log_->log("INFO", "StateManager initialized.");
}

StateManager::~StateManager() {
    if (log_) log_->log("INFO", "StateManager shutting down.");
}

void StateManager::changeState(const std::string& state) {
    lastState_ = state;
    if (log_) log_->log("INFO", "State changed to: " + state);
}

void StateManager::displayStatus() {
    std::string s = std::string("System state: ") + lastState_;
    if (log_) log_->log("INFO", "Displaying state: " + lastState_);
    std::cout << s << std::endl;
}

void StateManager::updateSensors() {
    if (log_) log_->log("DEBUG", "Sensors polled. All nominal.");
}
