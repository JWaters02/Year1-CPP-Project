/*
 * 2 FILES:
 *    SIMULATION DATA
 *    RANDOM NAMES (SO CAN BE EDITED)
 * */

#include "FileHandler.h"

//region Constructor
//endregion

//region Functions
void FileHandler::saveToFile(std::string inputData, std::string fileName) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::ofstream file(fileName + ".txt");

    // If file exists
    if (file.is_open()) {
        file << inputData;
        file.close();
        SetConsoleTextAttribute(hConsole, 10); // GREEN
        std::cout << fileName << " saved successfully." << std::endl;
    }
    SetConsoleTextAttribute(hConsole, 7); // DEFAULT
}

std::string FileHandler::loadFromFile(std::string fileName) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::ifstream file(fileName + ".txt");
    std::string ret = "";

    // If file exists
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            ret += line;
        }
        file.close();
        SetConsoleTextAttribute(hConsole, 10); // GREEN
        std::cout << fileName << " loaded successfully." << std::endl;
    } else {
        SetConsoleTextAttribute(hConsole, 12); // RED
        std::cout << fileName << " could not be found." << std::endl;
    }
    SetConsoleTextAttribute(hConsole, 7); // DEFAULT
    return ret;
}

void FileHandler::printFileContents(std::string fileName) {
    std::ifstream file(fileName + ".txt");

    // If file exists
    if (file.is_open()) {
        std::string ret = "";
        std::string line;
        while (std::getline(file, line)) {
            ret += line;
        }
        file.close();

        std::cout << ret << std::endl;
    }
}

void FileHandler::deleteFile(std::string fileName) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::string file = fileName + ".txt";

    if (std::remove("file.txt") == 0) { // TODO: Fix
        // Success
        SetConsoleTextAttribute(hConsole, 10); // GREEN
        std::cout << fileName << " deleted." << std::endl;
    } else {
        // Failed
        SetConsoleTextAttribute(hConsole, 12); // RED
        std::cout << fileName << " could not be found." << std::endl;
    }
    SetConsoleTextAttribute(hConsole, 7); // DEFAULT
}
//endregion

//region Setters
//endregion

//region Getters
//endregion