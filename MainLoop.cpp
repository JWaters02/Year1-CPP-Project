/*
* HANDLES THE MAIN EVENT LOOP
*/

#include "MainLoop.h"

void MainLoop::mainEventLoop() {
    std::unique_ptr<Commands> commands = std::make_unique<Commands>();
    while (true) {
        int count = 0;
        while (count < commands->tickSpeed / 2) {
            Sleep(1);
            // If key pressed, pause simulation
            if (GetAsyncKeyState(VK_SHIFT) & 0x8000) {
                Sleep(commands->tickSpeed / 2);

                // Display list of commands and what the user wishes to do
                Logs::log("\nType 'commands' for list of commands.\nEnter command:", 3);

                // User inputs command
                std::string command = "";
                std::getline(std::cin, command);

                // Sanitise to make sure it is all lower case
                for (int i = 0; i < command.length(); i++) {
                    command[i] = tolower(command[i]);
                }

                //Run command
                commands->setCommand(command);

                Logs::log("\nPress shift to input new command or nothing to continue program loop.", 3);
                break;
            }
            Sleep(1);
            count++;
        }

        // Run simulations
        commands->simulateShoppers();
    }
}