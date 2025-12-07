#include "../include/DetectionManager.h"
#include <iostream>

DetectionManager::DetectionManager(SecurityManager* securityManager, LogManager* logger)
    : m_securityManager(securityManager), m_logger(logger) {}

void DetectionManager::triggerAlarm() {
    std::cout << "DetectionManager: Alarm triggered!\n";
    if (m_logger) m_logger->log("ALERT", "Alarm triggered by DetectionManager.");
    m_securityManager->activateAlarm();
}

void DetectionManager::callPolice() {
    std::cout << "DetectionManager: Police have been notified.\n";
    if (m_logger) m_logger->log("ALERT", "Police notified by DetectionManager.");
    m_securityManager->callPolice();
}
