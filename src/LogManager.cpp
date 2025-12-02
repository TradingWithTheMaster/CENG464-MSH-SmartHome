#include "../include/LogManager.h"

LogManager::LogManager() {
    // Open the log file in append mode
    logFile.open("system_log.txt", std::ios::app);
    if (logFile.is_open()) {
        log("INFO", "System Log Initialized.");
    }
}

LogManager::~LogManager() {
    if (logFile.is_open()) {
        log("INFO", "System Log Closed.");
        logFile.close();
    }
}

void LogManager::log(const std::string& level, const std::string& message) {
    if (logFile.is_open()) {
        // Get current timestamp
        std::time_t now = std::time(nullptr);
        char timestamp[20];
        std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

        // Write to file: [TIME] [LEVEL] Message
        logFile << "[" << timestamp << "] [" << level << "] " << message << std::endl;
    }
}