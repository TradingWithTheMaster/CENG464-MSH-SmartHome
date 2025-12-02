#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

// Forward declaration
class MSHController; 

class Menu {
public:
    void displayMainMenu();
    void displayWelcome();
    int getUserSelection();
    void displayMessage(const std::string& msg);
};

#endif