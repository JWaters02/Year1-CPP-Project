/*
* HANDLES THE MAIN EVENT LOOP
*/

#include "MainLoop.h"

void MainLoop::setTickSpeed(int _tickSpeed) {
    tickSpeed = _tickSpeed;
}

void MainLoop::mainEventLoop() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::unique_ptr<Commands> commands = std::make_unique<Commands>();
    while (true) {
        int count = 0;
        while (count < tickSpeed / 2) {
            Sleep(1);
            // If key pressed, pause simulation
            // TODO: Change for any key pressed (or find better solution)
            if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
                Sleep(tickSpeed / 2);

                // Display list of commands and what the user wishes to do
                SetConsoleTextAttribute(hConsole, 3); // DARK CYAN
                std::cout << "\nType 'commands' for list of commands.\nEnter command:" << std::endl;
                SetConsoleTextAttribute(hConsole, 7); // DEFAULT

                // User inputs command
                std::string command = "";
                std::getline(std::cin, command);

                // Sanitise to make sure it is all lower case
                for (int i = 0; i < command.length(); i++) {
                    command[i] = tolower(command[i]);
                }

                //Run command
                commands->setCommand(command);

                // TODO: Fix bug on pf or df that puts another space in buffer or something

                SetConsoleTextAttribute(hConsole, 3); // DARK CYAN
                std::cout << "\nPress space to input new command or nothing to continue program loop." << std::endl;
                SetConsoleTextAttribute(hConsole, 7); // DEFAULT
                break;
            }
            Sleep(1);
            count++;
        }

        // Run simulations
        // commands->getSimInfo();
        commands->simulateShoppers();
        std::cout << std::endl;
    }
}