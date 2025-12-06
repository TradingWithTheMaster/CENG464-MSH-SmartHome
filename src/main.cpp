#include <iostream>            // 1. Standard libraries first
#include "MSHController.h"     // 2. Then your main controller header

// The entry point of the entire application
int main() {
    std::cout << "Initializing Smart Home System components...\n";

    // Create the main controller instance (The 'Driver')
    MSHController controller;

    // Start the main execution loop
    try {
        controller.run(); 
    } catch (const std::exception& e) {
        std::cerr << "A CRITICAL error occurred and the system shut down: " << e.what() << "\n";
        return 1; // Indicate failure
    } catch (...) {
        std::cerr << "An unknown critical error occurred.\n";
        return 1;
    }

    std::cout << "Smart Home System Shut Down Gracefully.\n";
    return 0; // Indicate success
}