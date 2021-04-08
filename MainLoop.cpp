/*
* HANDLES THE MAIN EVENT LOOP
*/

#include "MainLoop.h"

void MainLoop::setTickSpeed(int _tickSpeed) {
    tickSpeed = _tickSpeed;
}

void MainLoop::mainEventLoop() {
    // MAIN EVENT LOOP
    bool quit = false;
    while (!quit) {
        // Checking for key press which stops loop
        std::cout << "main loop restarts" << std::endl;
        int count = 0;
        while (count < tickSpeed / 2) {
            Sleep(1);
            // If key pressed, pause simulation
            // TODO: Change for any key pressed
            if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
                std::cout << "user pressed space!" << std::endl;
                Sleep(tickSpeed / 2);

                // Display list of commands and what the user wishes to do
                std::unique_ptr<Commands> commands = std::make_unique<Commands>();
                std::cout << "List of commands:\n" << commands->getCommandList() << std::endl;

                // User inputs command
                std::string command = "";
                std::getline(std::cin, command);

                // Sanitise to make sure it is all lower case
                for (int i = 0; i < command.length(); i++) {
                    command[i] = tolower(command[i]);
                }

                // Run command
                commands->setCommand(command);

                break;
            }
            Sleep(1);
            count++;
        }

        // Run simulations
    }
}