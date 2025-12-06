#ifndef SECURITY_MANAGER_H
#define SECURITY_MANAGER_H

#include <atomic>
#include <string>

class LogManager;

class SecurityManager {
public:
    explicit SecurityManager(LogManager* logger);
    ~SecurityManager();

    void triggerAlarm(const std::string& reason="Unknown");
    void acknowledgeAlarm();
    bool isAlarmActive() const;
    bool isAlarmAcknowledged() const;

    void detectMotion();
    void callPolice();

private:
    LogManager* log_ = nullptr;
    std::atomic<bool> alarmActive_{false};
    std::atomic<bool> alarmAcknowledged_{false};
};

#endif // SECURITY_MANAGER_H
