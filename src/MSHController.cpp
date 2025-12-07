#include "../include/MSHController.h"
#include "../include/DeviceManager.h"
#include "../include/ModeManager.h"
#include "../include/StateManager.h"
#include "../include/SecurityManager.h"
#include "../include/DetectionManager.h"
#include "../include/LogManager.h"
#include <conio.h>

#include <iostream>
#include <thread>
#include <chrono>
#include <limits>

using namespace std;

MSHController::MSHController(LogManager* logManager)
    : m_logManager(logManager)
{
    cout << "MSHController: Initializing components...\n";

    m_deviceManager    = std::make_unique<DeviceManager>();   // ✅ simple constructor
    m_modeManager      = std::make_unique<ModeManager>(m_logManager);
    m_stateManager     = std::make_unique<StateManager>(m_logManager);
    m_securityManager  = std::make_unique<SecurityManager>(m_logManager);
    m_detectionManager = std::make_unique<DetectionManager>(m_securityManager.get(), m_logManager);

    if (m_logManager)
        m_logManager->log("INFO", "MSHController initialized.");
}

void MSHController::initialize() {
    if (m_logManager)
        m_logManager->log("INFO", "System initialization complete.");
}

void MSHController::cleanup() {
    if (m_logManager)
        m_logManager->log("INFO", "System cleanup complete.");
}

void MSHController::addDevice() {
    string type, name;

    cout << "Enter device type (Light/Camera/TV/Detector): ";
    cin >> type;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter device name: ";
    getline(cin, name);

    if (type.empty() || name.empty()) {
        cout << "Invalid input.\n";
        return;
    }

    m_deviceManager->addDevice(type, name);
    m_logManager->log("INFO", "addDevice: " + type + " " + name);
}

void MSHController::removeDevice() {
    string name;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Device name to remove: ";
    getline(cin, name);

    if (name.empty()) {
        cout << "No name entered.\n";
        return;
    }

    m_deviceManager->removeDevice(name);
    m_logManager->log("INFO", "removeDevice: " + name);
}

void MSHController::powerOnDevice() {
    string name;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Device to power ON: ";
    getline(cin, name);

    if (name.empty()) {
        cout << "No device entered.\n";
        return;
    }

    m_deviceManager->powerOnDevice(name);
    m_logManager->log("INFO", "powerOnDevice: " + name);
}

void MSHController::powerOffDevice() {
    string name;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Device to power OFF: ";
    getline(cin, name);

    if (name.empty()) {
        cout << "No device entered.\n";
        return;
    }

    m_deviceManager->powerOffDevice(name);
    m_logManager->log("INFO", "powerOffDevice: " + name);
}

void MSHController::changeMode() {
    string mode;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter mode (Home/Away/Sleep): ";
    getline(cin, mode);

    if (mode.empty()) {
        cout << "No mode entered.\n";
        return;
    }

    m_modeManager->changeMode(mode);
    m_logManager->log("INFO", "changeMode: " + mode);
}

void MSHController::changeState() {
    string state;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter new state: ";
    getline(cin, state);

    if (state.empty()) {
        cout << "No state entered.\n";
        return;
    }

    m_stateManager->changeState(state);
    m_logManager->log("INFO", "changeState: " + state);
}

void MSHController::getHomeStatus() {
    m_logManager->log("INFO", "getHomeStatus called.");

    cout << "Mode: " << m_modeManager->getMode() << "\n";

    cout << "\nDevices:\n";
    m_deviceManager->listDevices();   // ✅ simple device listing

    cout << "\nSystem State:\n";
    m_stateManager->displayStatus();

    cout << "\nAlarm Active: " << (m_securityManager->isAlarmActive() ? "Yes" : "No") << "\n";
    cout << "Alarm Acknowledged: " << (m_securityManager->isAlarmAcknowledged() ? "Yes" : "No") << "\n";
}

void MSHController::runScenarioSimulation() {
    m_logManager->log("ALERT", "Starting scenario simulation.");

    cout << "Simulation: smoke alarm in 3s...\n";
    this_thread::sleep_for(chrono::seconds(3));

    m_detectionManager->triggerAlarm();
    cout << "!!! ALARM !!! Press Enter to acknowledge (10s)\n";

    bool acknowledged = false;

    for (int i = 0; i < 10; i++) {
        if (_kbhit()) {
            _getch();
            acknowledged = true;
            break;
        }

        cout << "Waiting... " << (10 - i) << "s remaining\n";
        this_thread::sleep_for(chrono::seconds(1));
    }

    if (acknowledged) {
        cout << "\nAlarm acknowledged by user.\n";
        m_securityManager->acknowledgeAlarm();
        m_logManager->log("INFO", "User acknowledged alarm.");
    } else {
        cout << "\nNo response detected.\n";
        cout << "Escalating emergency protocol...\n";

        cout << "Turning ON all lights...\n";
        // ✅ simple version: turn on each device manually
        m_deviceManager->powerOnDevice("LivingRoomLight");

        cout << "Contacting police...\n";
        m_detectionManager->callPolice();

        cout << "Simulating light failure...\n";
        // ✅ simple version: just turn it off
        m_deviceManager->powerOffDevice("LivingRoomLight");

        m_logManager->log("ALERT", "Escalation triggered.");
    }

    cout << "\nSimulation complete.\n";
    m_logManager->log("INFO", "Simulation complete.");
}

void MSHController::about() {
    cout << "MSH System V1.0 - CENG464\n";
}

void MSHController::shutdown() {
    cout << "Shutting down system...\n";
    m_logManager->log("SYSTEM", "Shutdown requested.");
}
