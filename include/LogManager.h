#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <string>
#include <fstream>
#include <iostream>
#include <ctime>

class LogManager {
private:
    std::ofstream logFile;

public:
    LogManager();
    ~LogManager();

    // Core function to log messages
    void log(const std::string& level, const std::string& message);
};

#endif