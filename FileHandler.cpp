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
    }
}

std::string FileHandler::loadFromFile(std::string filename) {
    std::ifstream file(filename + ".txt");
    std::string ret = "";

    // If file exists
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            ret += line;
        }
        file.close();
    }
    return ret;
}

void FileHandler::printFileContents(std::string filename) {
    std::ifstream file(filename + ".txt");

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

void FileHandler::deleteFile(std::string filename) {
//    if (std::remove(filename) != 0) {
//        // Failed
//    } else {
//        // Success
//    }
}
//endregion

//region Setters
//endregion

//region Getters
//endregion