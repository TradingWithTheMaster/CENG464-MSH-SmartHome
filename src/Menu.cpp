#include "../include/Menu.h"
#include "../include/MSHController.h"
#include <iostream>
#include <string>
#include <limits> 

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
	// consume leftover newline
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return choice;
}

void Menu::displayMessage(const string& msg) {
	cout << ">> SYSTEM INFO: " << msg << endl;
}

void Menu::run(MSHController* controller) {
	displayWelcome();
	bool running = true;
	while (running) {
		displayMainMenu();
		int choice = getUserSelection();
		if (controller) running = controller->processCommand(choice);
		else { displayMessage("No controller attached. Exiting."); running = false; }
	}
}

