#include <iostream>
#include <memory>
#include "MainLoop.h"

int main() {
    srand(time(nullptr));

    // MAIN EVENT LOOP
    std::string output = "\nPress space to input new command or nothing to continue program loop.";
    Logs::log(output, 3); // DARK CYAN
    std::unique_ptr<MainLoop> mainLoop = std::make_unique<MainLoop>();
    mainLoop->mainEventLoop();

    return 0;
}
