/*
* HANDLES THE MAIN EVENT LOOP
*/

#include "MainLoop.h"

void MainLoop::setTickSpeed(int _tickSpeed) {
    tickSpeed = _tickSpeed;
}

void MainLoop::mainEventLoop() {
    std::unique_ptr<Commands> commands = std::make_unique<Commands>();
    bool quit = false;
    while (!quit) {
        int count = 0;
        while (count < tickSpeed / 2) {
            Sleep(1);
            // If key pressed, pause simulation
            // TODO: Change for any key pressed
            if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
                Sleep(tickSpeed / 2);

                // Display list of commands and what the user wishes to do
                std::cout << "\nList of commands:\n" << commands->getCommandList();

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