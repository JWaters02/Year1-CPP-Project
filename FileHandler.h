/*
 * THIS CLASS MANAGES ALL FILE HANDLING EVENTS
 * SAVING AND LOADING FILES
 * */

#ifndef YEAR1_CPP_PROJECT_FILEHANDLER_H
#define YEAR1_CPP_PROJECT_FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

class FileHandler {
public:
    // Functions
    void saveToFile(std::string inputData, std::string fileName);
    std::string loadFromFile(std::string filename);
    void printFileContents(std::string filename);
    void deleteFile(std::string filename);
private:

};

#endif //YEAR1_CPP_PROJECT_FILEHANDLER_H
