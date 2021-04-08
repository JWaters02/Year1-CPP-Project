/*
 * THIS CLASS MANAGES COMMANDS INPUTTED INTO THE CONSOLE
 * MANAGES PARSING OF COMMANDS
 * */


#ifndef YEAR1_CPP_PROJECT_COMMANDS_H
#define YEAR1_CPP_PROJECT_COMMANDS_H

#include <vector>
#include <iostream>
#include <string>
#include <windows.h>
#include <memory>
#include "Simulation.h"

class Commands {
public:
    // Functions
    void quit();
    void pause(int pauseLength);

    void addSim();
    void removeSim(int simID);
    void pauseSim(int simID);
    void continueSim(int simID);

    // Setters
    void setCommand(std::string command);

    // Getters
    std::string getCommandList();
    std::string getSimIDs();
    std::string getShopperIDs();
    std::string listShoppers();
    std::string getHelp();

    // Vars

private:
    // Consts
    const int MAXID = 10; // Max of 10 simulations

    // Vars
    std::vector<std::string> commands = {"help", "quit", "pause <length of pause, ms>", "log",
                                         "add sim", "remove sim <ID>", "list sims <ID>",
                                         "continue sim <ID>", "pause sim <ID>"};
    std::vector<std::string> simIDs;
    int simCount = 0;
    std::vector<Simulation> simulationsRunning;
};

#endif //YEAR1_CPP_PROJECT_COMMANDS_H
