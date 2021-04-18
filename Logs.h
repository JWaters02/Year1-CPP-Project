/*
 * THIS CLASS MANAGES LOGGING OF EVENTS
 * CHILD CLASS OF EVERY OTHER CLASS
 * */

#ifndef YEAR1_CPP_PROJECT_LOGS_H
#define YEAR1_CPP_PROJECT_LOGS_H

#include <iostream>
#include <Windows.h>

class Logs {
public:
    static void log(const std::string output, const int colour, const bool fixed = false);
private:
    static void setPrecision(int precision);
};

#endif //YEAR1_CPP_PROJECT_LOGS_H
