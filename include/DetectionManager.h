#ifndef DETECTION_MANAGER_H
#define DETECTION_MANAGER_H

#include <string>

class LogManager;
class SecurityManager;

class DetectionManager {
public:
    DetectionManager(SecurityManager* security, LogManager* logger);
    ~DetectionManager();

    void detectMotion();          // Called when motion is detected
    void triggerAlarm();          // Forces alarm
    void callPolice();            // Escalation

private:
    SecurityManager* security_ = nullptr;
    LogManager* log_ = nullptr;
    int detectionCount_ = 0;
};

#endif // DETECTION_MANAGER_H