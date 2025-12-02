#ifndef MSHCONTROLLER_H
#define MSHCONTROLLER_H

// Forward declarations to avoid circular dependencies
class DeviceManager;
class LogManager;
class ModeManager;
class StateManager;
class SecurityManager;
class DetectionManager;

class MSHController {
private:
    // Singleton Instance
    static MSHController* instance;

    // Pointers to Subsystems (Facade Pattern)
    DeviceManager* deviceMgr;
    LogManager* logMgr;
    ModeManager* modeMgr;
    StateManager* stateMgr;
    SecurityManager* securityMgr;
    DetectionManager* detectionMgr;

    // Private Constructor for Singleton
    MSHController();

public:
    // Singleton Accessor
    static MSHController* getInstance();

    // Core System Functions
    void init();
    void run();
    void shutdown();
    
    // Facade Methods (Routing menu commands to managers)
    void processMenuOption(int option);
};

#endif // MSHCONTROLLER_H