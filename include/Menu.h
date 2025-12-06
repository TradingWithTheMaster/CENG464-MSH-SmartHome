#ifndef MENU_H
#define MENU_H

#include <string>
class MSHController;

class Menu {
public:
    Menu(MSHController* controller);
    void displayMainMenu();
    void displayWelcome();
    int getUserSelection();
    void displayMessage(const std::string& msg);
    void run();

private:
    MSHController* controller;
    bool running;

    void showMenu();
    void handleChoice(int choice);
};

#endif