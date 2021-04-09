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
    void aliases();
    void quit();
    void pause();
    void listSimIDs();
    void addSim();
    void removeSim();
    void listSimInfo(std::string simID);
    void pauseSim(std::string simID);
    void continueSim(std::string simID);
    void addShopper(std::string simID);
    void removeShopper(std::string simID);
    void listShopperInfo(std::string simID, std::string shopperID);
    void listShoppers(std::string simID, std::string shopperID);

    // Setters
    void setCommand(std::string command);

    // Getters
    std::string getCommandList();
    std::string getShopperIDs();
    std::string listShoppers();
private:
    // Functions
    void isIDValid(std::string simID, std::string shopperID, int commandType);

    // Consts
    const int MAXID = 10; // Max of 10 simulations

    // Vars
    std::vector<std::string> commands = {"help", "aliases", "quit", "pause", "list sims",
                                         "add sim", "remove sim", "list sim info <sim ID>",
                                         "continue sim <sim ID>", "pause sim <sim ID>",
                                         "add shopper <sim ID>", "remove shopper <sim ID>",
                                         "list shopper info <sim ID> <shopper ID>",
                                         "list shoppers <sim ID>"};
    std::vector<std::string> commandAliases = {"h", "a", "q", "p", "ls", "as", "rs", "lsi <sim ID>",
                                               "cs <sim ID>", "ps <sim ID>", "ash <sim ID>",
                                               "rsh <sim ID>", "lshi <sim ID> <shopper ID>",
                                               "lsh <sim ID>"};
    std::vector<std::string> simIDs;
    int simCount = 0;
    std::vector<Simulation> simulationsRunning;
};

#endif //YEAR1_CPP_PROJECT_COMMANDS_H
