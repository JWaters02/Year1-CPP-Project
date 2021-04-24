#include <iostream>
#include <memory>
#include "MainLoop.h"

int main() {
    srand(time(nullptr));

    // MAIN EVENT LOOP
    Logs::log("\nPress shift to input new command or nothing to continue program loop.", 3); // DARK CYAN
    std::unique_ptr<MainLoop> mainLoop = std::make_unique<MainLoop>();
    mainLoop->mainEventLoop();

    return 0;
}
