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
    void help();
    void quit();
    void pause();
    void listSimIDs();
    void addSim();
    void removeSim();
    void pauseSim(std::string simID);
    void continueSim(std::string simID);
    void listSimInfo(std::string simID);

    // Setters
    void setCommand(std::string command);

    // Getters
    std::string getCommandList();
    std::string getShopperIDs();
    std::string listShoppers();
private:
    // Consts
    const int MAXID = 10; // Max of 10 simulations

    // Vars
    std::vector<std::string> commands = {"help", "quit", "pause", "list sims",
                                         "add sim", "remove sim", "list sim info <sim ID>",
                                         "continue sim <sim ID>", "pause sim <sim ID>",
                                         ""};
    std::vector<std::string> simIDs;
    int simCount = 0;
    std::vector<Simulation> simulationsRunning;
};

#endif //YEAR1_CPP_PROJECT_COMMANDS_H
