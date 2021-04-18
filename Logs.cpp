/*
 * THIS CLASS MANAGES LOGGING OF EVENTS
 * CHILD CLASS OF EVERY OTHER CLASS
 * */

#include "Logs.h"

//region Constructor
//endregion

//region Functions
void Logs::log(const std::string output, const int colour) {
    /*
     * RED = 12
     * DARK CYAN = 3
     * GREEN = 10
     * DEFAULT = 7
     */
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colour);
    std::cout << output << std::endl;
    SetConsoleTextAttribute(hConsole, 7); // DEFAULT
}

void Logs::precisionLog(const std::string output1, const double fixedNum, const std::string output2, const int colour) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colour);
    std::cout.precision(2);
    std::cout << output1 << std::fixed << fixedNum << output2 << std::endl;
    SetConsoleTextAttribute(hConsole, 7); // DEFAULT
}
//endregion

//region Setters
//endregion

//region Getters
//endregion