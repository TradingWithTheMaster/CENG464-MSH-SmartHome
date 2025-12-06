#include "LogManager.h"
#include <ctime>
#include <iostream>

LogManager::LogManager()
    : initialized(false) {
}

LogManager::~LogManager() {
    if (logFile.is_open()) {
        logFile << "[SYSTEM] Log manager shutting down.\n";
        logFile.close();
    }
}

bool LogManager::init(const std::string &fileName) {
    if (initialized) {
        return true;
    }

    logFile.open(fileName.c_str(), std::ios::out | std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file: " << fileName << "\n";
        initialized = false;
        return false;
    }

    initialized = true;

    std::time_t now = std::time(0);
    char *dt = std::ctime(&now);
    if (dt == 0) {
        logFile << "=========================\n";
        logFile << "[SYSTEM] MSH started.\n";
        logFile << "=========================\n";
    } else {
        logFile << "=========================\n";
        logFile << "[SYSTEM] MSH started at: " << dt;
        logFile << "=========================\n";
    }

    return true;
}

void LogManager::log(const std::string &message) {
    if (!initialized || !logFile.is_open()) {
        return;
    }

    std::time_t now = std::time(0);
    char *dt = std::ctime(&now);

    if (dt != 0) {
        for (char *p = dt; *p != '\0'; ++p) {
            if (*p == '\n') {
                *p = '\0';
                break;
            }
        }
    }

    logFile << "[" << (dt ? dt : "UNKNOWN_TIME") << "] " << message << "\n";
    logFile.flush();
}

void LogManager::log(const std::string &level, const std::string &message) {
    if (!initialized || !logFile.is_open()) {
        return;
    }

    std::time_t now = std::time(0);
    char *dt = std::ctime(&now);

    if (dt != 0) {
        for (char *p = dt; *p != '\0'; ++p) {
            if (*p == '\n') {
                *p = '\0';
                break;
            }
        }
    }

    logFile << "[" << (dt ? dt : "UNKNOWN_TIME") << "] "
            << "[" << level << "] "
            << message << "\n";

    logFile.flush();
}

void LogManager::shutdown() {
    if (initialized && logFile.is_open()) {
        logFile << "[SYSTEM] MSH shutting down.\n";
        logFile.close();
    }
    initialized = false;
}