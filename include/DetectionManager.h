#ifndef DETECTION_MANAGER_H
#define DETECTION_MANAGER_H

#include "SecurityManager.h"
#include "LogManager.h"

class DetectionManager {
public:
    DetectionManager(SecurityManager* security = nullptr, LogManager* logger = nullptr);

    void detectMotion();     
    void triggerAlarm();     
    void callPolice();      

private:
    SecurityManager* securityManager;
    LogManager* logManager;
    int detectionCount;
};

#endif
