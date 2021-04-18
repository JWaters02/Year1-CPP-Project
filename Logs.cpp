/*
 * THIS CLASS MANAGES LOGGING OF EVENTS
 * CHILD CLASS OF EVERY OTHER CLASS
 * */

#include "Logs.h"

//region Constructor
//endregion

//region Functions
void Logs::log(const std::string output, const int colour, const bool fixed) {
    /*
     * RED = 12
     * DARK CYAN = 3
     * GREEN = 10
     * DEFAULT = 7
     */
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colour);
    if (fixed) {
        setPrecision(2);
        std::cout << std::fixed << output << std::endl;
    } else {
        std::cout << output << std::endl;
    }
    SetConsoleTextAttribute(hConsole, 7); // DEFAULT
}
//endregion

//region Setters
void Logs::setPrecision(int precision) {
    std::cout.precision(precision);
}
//endregion

//region Getters
//endregion