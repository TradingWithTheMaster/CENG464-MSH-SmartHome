#include "MSHController.h"
#include "Menu.h"
#include "LogManager.h"
#include <iostream>

// Entry point of the Smart Home System
int main() {
    LogManager logManager;
    if (!logManager.init("msh_log.txt")) {
        std::cerr << "Warning: Could not open log file.\n";
    }

    // Create controller with logging support
    MSHController controller(&logManager);

    // If your controller has initialize(), keep it. Otherwise remove.
    // controller.initialize();

    // Create and run the menu system
    Menu menu(&controller);
    menu.run();

    // If your controller has cleanup(), keep it. Otherwise remove.
    // controller.cleanup();

    logManager.shutdown();

    std::cout << "Smart Home System Shut Down Gracefully.\n";
    return 0;
}