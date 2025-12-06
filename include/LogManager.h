#ifndef LOG_MANAGER_H
#define LOG_MANAGER_H

#include <string>
#include <fstream>

class LogManager {
public:
    LogManager();
    ~LogManager();

    bool init(const std::string &fileName);
    void log(const std::string &message);
    void log(const std::string &level, const std::string &message);
    void shutdown();

private:
    std::ofstream logFile;
    bool initialized;
};

#endif