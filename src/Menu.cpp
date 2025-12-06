#include "../include/Menu.h"
#include "../include/MSHController.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

Menu::Menu(MSHController* controller) {
    this->controller = controller;
    running = true;
}

void Menu::displayWelcome() {
    cout << "===============================" << endl;
    cout << "      MY SWEET HOME (MSH) SYSTEM      " << endl;
    cout << "===============================" << endl;
}

void Menu::displayMainMenu() {
    cout << "\n--- MAIN MENU ---" << endl;
    cout << "[1] Get Home Status" << endl;
    cout << "[2] Add Device" << endl;
    cout << "[3] Remove Device" << endl;
    cout << "[4] Power On Device" << endl;
    cout << "[5] Power Off Device" << endl;
    cout << "[6] Change Mode (Home/Away/Sleep)" << endl;
    cout << "[7] Change State (e.g., Security Trigger)" << endl;
    cout << "[8] Run Scenario Simulation" << endl;
    cout << "[9] About" << endl;
    cout << "[10] Shutdown" << endl;
    cout << "Select Option: ";
}

int Menu::getUserSelection() {
    int choice;
    while (!(cin >> choice) || choice < 1 || choice > 10) {
        cout << "Invalid input. Please enter a number between 1 and 10: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return choice;
}

void Menu::displayMessage(const string& msg) {
    cout << msg << endl;
}

void Menu::run() {
    displayWelcome();
    while (running) {
        showMenu();
        int choice = getUserSelection();
        handleChoice(choice);
    }
}

void Menu::showMenu() {
    displayMainMenu();
}

void Menu::handleChoice(int choice) {
    switch (choice) {
        case 1:
            controller->getHomeStatus();
            break;
        case 2:
            controller->addDevice();
            break;
        case 3:
            controller->removeDevice();
            break;
        case 4:
            controller->powerOnDevice();
            break;
        case 5:
            controller->powerOffDevice();
            break;
        case 6:
            controller->changeMode();
            break;
        case 7:
            controller->changeState();
            break;
        case 8:
            controller->runScenarioSimulation();
            break;
        case 9:
            controller->about();
            break;
        case 10:
            controller->shutdown();
            running = false;
            break;
        default:
            cout << "Invalid selection." << endl;
            break;
    }
}