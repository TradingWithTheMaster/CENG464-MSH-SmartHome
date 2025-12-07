#ifndef MSH_CONTROLLER_H
#define MSH_CONTROLLER_H

#include <memory>
#include <string>

#include "DeviceManager.h"
#include "ModeManager.h"
#include "StateManager.h"
#include "SecurityManager.h"
#include "DetectionManager.h"
#include "LogManager.h"

class MSHController {
public:
    MSHController(LogManager* logManager);

    void initialize();
    void cleanup();

    void addDevice();
    void removeDevice();
    void changeMode();
    void changeState();
    void getHomeStatus();
    void runScenarioSimulation();
    void about();
    void shutdown();
    void powerOnDevice();
    void powerOffDevice();

private:
    LogManager* m_logManager;

    std::unique_ptr<DeviceManager>   m_deviceManager;
    std::unique_ptr<ModeManager>     m_modeManager;
    std::unique_ptr<StateManager>    m_stateManager;
    std::unique_ptr<SecurityManager> m_securityManager;
    std::unique_ptr<DetectionManager> m_detectionManager;
};

#endif
