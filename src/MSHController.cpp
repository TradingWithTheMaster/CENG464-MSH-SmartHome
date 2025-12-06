#include "../include/MSHController.h"
#include "../include/DeviceManager.h"
#include "../include/ModeManager.h"
#include "../include/StateManager.h"
#include "../include/SecurityManager.h"

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

MSHController::MSHController(LogManager* logManager)
    : m_logManager(logManager)
{
    cout << "MSHController: Initializing components...\n";

    m_deviceManager = std::make_unique<DeviceManager>(m_logManager);
    m_modeManager   = std::make_unique<ModeManager>(m_logManager);
    m_stateManager  = std::make_unique<StateManager>(m_logManager);

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
    string name;
    cout << "Device name to add: ";
    getline(cin, name);

    if (name.empty()) {
        cout << "No name entered.\n";
        return;
    }

    m_deviceManager->addDevice(name);
    m_logManager->log("INFO", "addDevice: " + name);
}

void MSHController::removeDevice() {
    string name;
    cout << "Device name to remove: ";
    getline(cin, name);

    if (name.empty()) {
        cout << "No name entered.\n";
        return;
    }

    m_deviceManager->removeDevice(name);
    m_logManager->log("INFO", "removeDevice: " + name);
}

void MSHController::changeMode() {
    string mode;
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
    string st;
    cout << "Enter new state: ";
    getline(cin, st);

    if (st.empty()) {
        cout << "No state entered.\n";
        return;
    }

    m_stateManager->changeState(st);
    m_logManager->log("INFO", "changeState: " + st);
}

void MSHController::getHomeStatus() {
    m_logManager->log("INFO", "getHomeStatus called.");

    cout << "Mode: " << m_modeManager->getMode() << "\n";
    cout << "Devices: " << m_deviceManager->getStatus() << "\n";
    m_stateManager->displayStatus();
}

void MSHController::runScenarioSimulation() {
    m_logManager->log("ALERT", "Starting scenario simulation.");

    cout << "Simulation: smoke alarm in 3s...\n";
    this_thread::sleep_for(chrono::seconds(3));

    m_logManager->log("EVENT", "Smoke detector activated.");
    cout << "!!! ALARM !!! Press Enter to acknowledge (10s)\n";

    bool acknowledged = false;

    thread ackThread([&]() {
        string s;
        getline(cin, s);
        acknowledged = true;
    });

    for (int i = 0; i < 10; i++) {
        if (acknowledged) break;
        this_thread::sleep_for(chrono::seconds(1));
    }

    if (ackThread.joinable())
        ackThread.detach();

    if (acknowledged) {
        m_logManager->log("INFO", "User acknowledged alarm.");
        cout << "Alarm acknowledged.\n";
    } else {
        m_logManager->log("ALERT", "No acknowledgement. Escalating.");
        m_deviceManager->setPowerState("AllLights", true);
        m_logManager->log("INFO", "AllLights turned ON.");
        m_logManager->log("ALERT", "Police called.");
    }

    m_deviceManager->simulateLightFailure("LivingRoomLight");
    m_logManager->log("INFO", "Simulation complete.");
}

void MSHController::about() {
    cout << "MSH System V1.0 - CENG464\n";
}

void MSHController::shutdown() {
    cout << "Shutting down system...\n";
    m_logManager->log("SYSTEM", "Shutdown requested.");
}