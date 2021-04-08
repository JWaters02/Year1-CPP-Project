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
        std::cout << "main loop restarts" << std::endl;
        int count = 0;
        while (count < tickSpeed / 2) {
            Sleep(1);
            if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
                std::cout << "user pressed space!" << std::endl;
                Sleep(tickSpeed / 2);

                // Display list of commands and what the user wishes to do


                break;
            }
            Sleep(1);
            count++;
        }
        // Generate simulations
    }
}