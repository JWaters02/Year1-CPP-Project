#include <iostream>
#include <memory>
#include "MainLoop.h"

int main() {
    srand(time(nullptr));

    // MAIN EVENT LOOP
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 3); // DARK CYAN
    std::cout << "\nPress space to input new command or nothing to continue program loop." << std::endl;
    SetConsoleTextAttribute(hConsole, 7); // DEFAULT
    std::unique_ptr<MainLoop> mainLoop = std::make_unique<MainLoop>();
    mainLoop->mainEventLoop();

    return 0;
}
