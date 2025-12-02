#include "../include/Menu.h"

using namespace std;

void Menu::displayWelcome() {
    cout << "========================================" << endl;
    cout << "      MY SWEET HOME (MSH) SYSTEM        " << endl;
    cout << "========================================" << endl;
}

void Menu::displayMainMenu() {
    cout << "\n--- MAIN MENU ---" << endl;
    cout << "[1] Get Home Status" << endl;
    cout << "[2] Add Device" << endl;
    cout << "[3] Remove Device" << endl;
    cout << "[4] Power On Device" << endl;
    cout << "[5] Power Off Device" << endl;
    cout << "[6] Change Mode" << endl;
    cout << "[7] Change State" << endl;
    cout << "[8] Manual" << endl;
    cout << "[9] About" << endl;
    cout << "[10] Shutdown" << endl;
    cout << "Select Option: ";
}

int Menu::getUserSelection() {
    int choice;
    cin >> choice;
    return choice;
}

void Menu::displayMessage(const string& msg) {
    cout << ">> SYSTEM INFO: " << msg << endl;
}