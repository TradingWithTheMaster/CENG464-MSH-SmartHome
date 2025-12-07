#ifndef DETECTION_MANAGER_H
#define DETECTION_MANAGER_H

#include "SecurityManager.h"
#include "LogManager.h"

class DetectionManager {
public:
    DetectionManager(SecurityManager* securityManager, LogManager* logger);

    void triggerAlarm();
    void callPolice();

private:
    SecurityManager* m_securityManager;
    LogManager* m_logger;
};

#endif
