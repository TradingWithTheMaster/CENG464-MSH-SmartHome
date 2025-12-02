#include <iostream>
#include "../include/MSHController.h"

int main() {
    // 1. Get the Singleton instance of the Controller
    MSHController* app = MSHController::getInstance();

    // 2. Initialize the system (Logs, Devices, Managers)
    app->init();

    // 3. Start the main run loop
    app->run();

    return 0;
}