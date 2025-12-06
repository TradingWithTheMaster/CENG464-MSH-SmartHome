#include "../include/MSHController.h"
#include "../include/Menu.h"
#include "../include/LogManager.h"
#include "../include/DeviceManager.h"
#include "../include/ModeManager.h"
#include "../include/StateManager.h"
#include "../include/SecurityManager.h"

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

MSHController::MSHController() {
    cout << "MSHController: Initializing components...\n";
    m_logManager.reset(new LogManager());

    // instantiate managers
    m_deviceManager = std::unique_ptr<DeviceManagerBase>(new DeviceManager(m_logManager.get()));
    m_modeManager = std::unique_ptr<ModeManagerBase>(new ModeManager(m_logManager.get()));
    m_stateManager = std::unique_ptr<StateManagerBase>(new StateManager(m_logManager.get()));

    // menu is not owned here; we'll create a Menu on the stack in run()
    m_logManager->log("INFO", "MSHController initialized.");
}

MSHController::~MSHController() {
    if (m_logManager) m_logManager->log("INFO", "MSHController shutting down.");
    cout << "MSHController: cleaned up.\n";
}

void MSHController::addDevice() {
    string name;
    cout << "Device name to add: ";
    getline(cin, name);
    if (name.empty()) { cout << "No name entered.\n"; return; }
    if (m_deviceManager) m_deviceManager->addDevice(name);
    if (m_logManager) m_logManager->log("INFO", "addDevice: " + name);
}

void MSHController::removeDevice() {
    string name;
    cout << "Device name to remove: ";
    getline(cin, name);
    if (name.empty()) { cout << "No name entered.\n"; return; }
    if (m_deviceManager) m_deviceManager->removeDevice(name);
    if (m_logManager) m_logManager->log("INFO", "removeDevice: " + name);
}

void MSHController::changeMode() {
    string mode;
    cout << "Enter mode (Home/Away/Sleep): ";
    getline(cin, mode);
    if (mode.empty()) { cout << "No mode entered.\n"; return; }
    if (m_modeManager) m_modeManager->changeMode(mode);
    if (m_logManager) m_logManager->log("INFO", "changeMode: " + mode);
}

void MSHController::changeState() {
    string st;
    cout << "Enter new state: ";
    getline(cin, st);
    if (st.empty()) { cout << "No state entered.\n"; return; }
    if (m_stateManager) m_stateManager->changeState(st);
    if (m_logManager) m_logManager->log("INFO", "changeState: " + st);
}

void MSHController::getHomeStatus() {
    if (m_logManager) m_logManager->log("INFO", "getHomeStatus called.");
    if (m_modeManager) cout << "Mode: " << m_modeManager->getMode() << "\n";
    if (m_deviceManager) cout << "Devices: " << m_deviceManager->getStatus() << "\n";
    if (m_stateManager) m_stateManager->displayStatus();
}

void MSHController::runSimulation() {
    if (m_logManager) m_logManager->log("ALERT", "Starting simulation.");
    cout << "Simulation: smoke alarm in 3s...\n";
    this_thread::sleep_for(chrono::seconds(3));

    if (m_logManager) m_logManager->log("EVENT", "Smoke detector activated.");
    // For demo purposes, we just log and wait for potential user acknowledgement
    cout << "!!! ALARM !!! Press Enter to acknowledge (10s)\n";

    bool acknowledged = false;
    // spawn a thread to read Enter
    thread ackThread([&]() {
        string s; getline(cin, s); if (!s.empty() || s.empty()) acknowledged = true;
    });

    for (int i=0;i<10;i++) {
        if (acknowledged) break;
        this_thread::sleep_for(chrono::seconds(1));
    }
    if (ackThread.joinable()) ackThread.detach();

    if (acknowledged) {
        if (m_logManager) m_logManager->log("INFO", "User acknowledged alarm.");
        cout << "Alarm acknowledged.\n";
    } else {
        if (m_logManager) m_logManager->log("ALERT", "No acknowledgement. Escalating: motion -> lights -> police.");
        // simulate motion
        if (m_deviceManager) m_deviceManager->setPowerState("AllLights", true);
        if (m_logManager) m_logManager->log("INFO", "AllLights turned ON.");
        if (m_logManager) m_logManager->log("ALERT", "Police called.");
    }

    if (m_deviceManager) m_deviceManager->simulateLightFailure("LivingRoomLight");
    if (m_logManager) m_logManager->log("INFO", "Simulation complete.");
}

bool MSHController::processCommand(int choice) {
    switch (choice) {
        case 1: getHomeStatus(); break;
        case 2: addDevice(); break;
        case 3: removeDevice(); break;
        case 4: {
            string name; cout << "Device to power ON: "; getline(cin, name); if (!name.empty() && m_deviceManager) m_deviceManager->setPowerState(name, true); break;
        }
        case 5: {
            string name; cout << "Device to power OFF: "; getline(cin, name); if (!name.empty() && m_deviceManager) m_deviceManager->setPowerState(name, false); break;
        }
        case 6: changeMode(); break;
        case 7: changeState(); break;
        case 8: runSimulation(); break;
        case 9: cout << "MSH System V1.0 - CENG464\n"; break;
        case 10: return false;
        default: cout << "Invalid option.\n"; break;
    }
    return true;
}

void MSHController::run() {
    Menu menu;
    menu.run(this);
}
