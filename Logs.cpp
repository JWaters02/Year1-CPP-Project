/*
 * THIS CLASS MANAGES LOGGING OF EVENTS
 * CHILD CLASS OF EVERY OTHER CLASS
 * */

#include "Logs.h"

//region Constructor
//endregion

//region Functions
/**
 * Outputs string in the colour specified.
 *
 * @param output String to output.
 * @param colour Colour of output.
 */
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

/**
 * Outputs string in the colour specified, but sets console prescion for outputted a truncated double.
 *
 * @param output1 String to output before the double.
 * @param fixedNum Double to output.
 * @param output2 String to output after the double.
 * @param colour Colour of output.
 */
void Logs::precisionLog(const std::string output1, const double fixedNum, const std::string output2, const int colour) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colour);
    std::cout.precision(2);
    std::cout << output1 << std::fixed << fixedNum << output2 << std::endl;
    SetConsoleTextAttribute(hConsole, 7); // DEFAULT
}

/**
 * Fixes the cin not consuming the newline so fixes a getline() bug when entering a command.
 */
void Logs::dummyGetLineFix() {
    std::string dummyGetline = "";
    std::getline(std::cin, dummyGetline);
}
//endregion

//region Setters
//endregion

//region Getters
//endregion