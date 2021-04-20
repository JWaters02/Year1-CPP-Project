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
    std::ofstream file(fileName + ".txt");

    // If file exists
    if (file.is_open()) {
        file << inputData;
        file.close();
        Logs::log(fileName + " saved successfully.", 10);
    } else {
        Logs::log(fileName + " does not exist!", 12);
    }
}

std::string FileHandler::loadFromFile(std::string fileName) {
    std::ifstream file(fileName + ".txt");
    std::string ret = "";

    // If file exists
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            ret += line;
        }
        file.close();
        Logs::log(fileName + " loaded successfully.", 10);
    } else {
        Logs::log(fileName + " could not be found.", 12);
    }
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
    } else {
        Logs::log(fileName + " could not be found.", 12);
    }
}

void FileHandler::deleteFile(std::string fileName) {
    std::string file = fileName + ".txt";

    if (std::remove(file.c_str()) == 0) {
        // Success
        Logs::log(fileName + " deleted.", 10);
    } else {
        // Failed
        Logs::log(fileName + " could not be found.", 12);
    }
}
//endregion

//region Setters
//endregion

//region Getters
//endregion