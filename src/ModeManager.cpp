#include "../include/ModeManager.h"
#include "../include/LogManager.h"

ModeManager::ModeManager(LogManager* logger)
	: log_(logger) {
	if (log_) log_->log("INFO", "ModeManager initialized (Home mode).");
}

ModeManager::~ModeManager() {
	if (log_) log_->log("INFO", "ModeManager shutting down.");
}

void ModeManager::changeMode(const std::string& mode) {
	currentMode_ = mode;
	if (log_) log_->log("INFO", "Mode changed to: " + mode);
}

std::string ModeManager::getMode() {
	return currentMode_;
}

