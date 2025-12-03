#ifndef MSH_CONTROLLER_H
#define MSH_CONTROLLER_H

#include <memory> // Needed for std::unique_ptr (Smart Pointers)

// Include the Manager headers
#include "LogManager.h"        // Existing file
#include "DeviceManagerBase.h" // New interface
#include "ModeManagerBase.h"   // New interface
#include "StateManagerBase.h"  // New interface

class MSHController {
public:
    // Basic class structure
    MSHController(); 
    void run();
    virtual ~MSHController() = default;

private:
    // The four required pointers to the Manager Systems
    std::unique_ptr<LogManager> m_logManager;
    std::unique_ptr<DeviceManagerBase> m_deviceManager;
    std::unique_ptr<ModeManagerBase> m_modeManager;
    std::unique_ptr<StateManagerBase> m_stateManager;
};

#endif // MSH_CONTROLLER_H