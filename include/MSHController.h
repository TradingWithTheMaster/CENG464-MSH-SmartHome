#ifndef MSH_CONTROLLER_H
#define MSH_CONTROLLER_H

#include <memory>
#include <string>

#include "LogManager.h"
#include "DeviceManagerBase.h"
#include "ModeManagerBase.h"
#include "StateManagerBase.h"

class MSHController {
public:
    // NEW: constructor accepts LogManager*
    MSHController(LogManager* logManager);

    // Main control loop is now handled by Menu, not here
    void initialize();
    void cleanup();

    // Actions invoked by Menu
    void addDevice();
    void removeDevice();
    void changeMode();
    void changeState();
    void getHomeStatus();
    void runScenarioSimulation();   // renamed from runSimulation()
    void about();
    void shutdown();

private:
    LogManager* m_logManager;  // no unique_ptr — owned by main

    std::unique_ptr<DeviceManagerBase> m_deviceManager;
    std::unique_ptr<ModeManagerBase>   m_modeManager;
    std::unique_ptr<StateManagerBase>  m_stateManager;
};

#endif