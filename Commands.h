/*
 * THIS CLASS MANAGES COMMANDS INPUTTED INTO THE CONSOLE
 * MANAGES PARSING OF COMMANDS
 * */


#ifndef YEAR1_CPP_PROJECT_COMMANDS_H
#define YEAR1_CPP_PROJECT_COMMANDS_H

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include <memory>
#include <functional>
#include <algorithm>
#include "Simulation.h"
#include "FileHandler.h"

class Commands {
public:
    // Constructor
    Commands();

    // Functions
    void help();
    void commandList();
    void aliases();
    void quit();
    void pause();
    void saveSimulations();
    void loadSimulations();
    void deleteFile();
    void printFile();
    void listSimIDs();
    void addSim();
    void removeSim();
    void listSimInfo(std::vector<std::string>& IDTypes);
    void pauseSim(std::vector<std::string>& IDTypes);
    void continueSim(std::vector<std::string>& IDTypes);
    void addShopper(std::vector<std::string>& IDTypes);
    void removeShopper(std::vector<std::string>& IDTypes);
    void listShopperInfo(std::vector<std::string>& IDTypes);
    void listShoppers(std::vector<std::string>& IDTypes);

    // Setters
    void setCommand(std::string command);

    // Getters
    std::string getCommandList();
    void getSimInfo();
private:
    // Functions
    bool isIDValid(std::vector<std::string>& IDTypes);
    std::vector<std::string> splitCommand(std::string command, char delimeter);
    bool isNumber(const std::string& string);
    std::vector<std::string> parseActualCommand(std::string command);
    bool isCommandValid(std::string command);

    // Getters
    std::string getFileName();

    // Consts
    const int MAXID = 10; // Max of 10 simulations

    // Vars
    std::vector<std::string> commands = {"help", "commands", "aliases", "quit", "pause",
                                         "save program", "load program", "delete file",
                                         "print file", "list sims",
                                         "add sim", "remove sim", "list sim info <sim ID>",
                                         "continue sim <sim ID>", "pause sim <sim ID>",
                                         "add shopper <sim ID>", "remove shopper <sim ID>",
                                         "list shopper info <sim ID> <shopper ID>",
                                         "list shoppers <sim ID>"};
    std::vector<std::string> commandAliases = {"h", "c", "a", "q", "p", "ls", "as", "rs",
                                               "sp", "lp", "df", "pf", "lsi <sim ID>",
                                               "cs <sim ID>", "ps <sim ID>", "ash <sim ID>",
                                               "rsh <sim ID>", "lshi <sim ID> <shopper ID>",
                                               "lsh <sim ID>"};
    using funcPair = std::pair<std::string, std::function<void(std::vector<std::string>&)>>;
    std::vector<funcPair> commandFunc {
        std::make_pair("help", [this](std::vector<std::string>&){help();}),
        std::make_pair("h", [this](std::vector<std::string>&){help();}),
        std::make_pair("commands", [this](std::vector<std::string>&){commandList();}),
        std::make_pair("c", [this](std::vector<std::string>&){commandList();}),
        std::make_pair("aliases", [this](std::vector<std::string>&){aliases();}),
        std::make_pair("a", [this](std::vector<std::string>&){aliases();}),
        std::make_pair("quit", [this](std::vector<std::string>&){quit();}),
        std::make_pair("q", [this](std::vector<std::string>&){quit();}),
        std::make_pair("pause", [this](std::vector<std::string>&){pause();}),
        std::make_pair("p", [this](std::vector<std::string>&){pause();}),
        std::make_pair("save program", [this](std::vector<std::string>&){saveSimulations();}),
        std::make_pair("sp", [this](std::vector<std::string>&){saveSimulations();}),
        std::make_pair("load program", [this](std::vector<std::string>&){loadSimulations();}),
        std::make_pair("lp", [this](std::vector<std::string>&){loadSimulations();}),
        std::make_pair("delete file", [this](std::vector<std::string>&){deleteFile();}),
        std::make_pair("df", [this](std::vector<std::string>&){deleteFile();}),
        std::make_pair("print file", [this](std::vector<std::string>&){printFile();}),
        std::make_pair("pf", [this](std::vector<std::string>&){printFile();}),
        std::make_pair("list sims", [this](std::vector<std::string>&){listSimIDs();}),
        std::make_pair("ls", [this](std::vector<std::string>&){listSimIDs();}),
        std::make_pair("add sim", [this](std::vector<std::string>&){addSim();}),
        std::make_pair("as", [this](std::vector<std::string>&){addSim();}),
        std::make_pair("remove sim", [this](std::vector<std::string>&){removeSim();}),
        std::make_pair("rs", [this](std::vector<std::string>&){removeSim();}),
        std::make_pair("list sim info ", [this](std::vector<std::string>& IDTypes){listSimInfo(IDTypes);}),
        std::make_pair("lsi ", [this](std::vector<std::string>& IDTypes){listSimInfo(IDTypes);}),
        std::make_pair("continue sim ", [this](std::vector<std::string>& IDTypes){continueSim(IDTypes);}),
        std::make_pair("cs ", [this](std::vector<std::string>& IDTypes){continueSim(IDTypes);}),
        std::make_pair("pause sim ", [this](std::vector<std::string>& IDTypes){pauseSim(IDTypes);}),
        std::make_pair("ps ", [this](std::vector<std::string>& IDTypes){pauseSim(IDTypes);}),
        std::make_pair("add shopper ", [this](std::vector<std::string>& IDTypes){addShopper(IDTypes);}),
        std::make_pair("ash ", [this](std::vector<std::string>& IDTypes){addShopper(IDTypes);}),
        std::make_pair("remove shopper ", [this](std::vector<std::string>& IDTypes){removeShopper(IDTypes);}),
        std::make_pair("rsh ", [this](std::vector<std::string>& IDTypes){removeShopper(IDTypes);}),
        std::make_pair("list shopper info ", [this](std::vector<std::string>& IDTypes){listShopperInfo(IDTypes);}),
        std::make_pair("lshi ", [this](std::vector<std::string>& IDTypes){listShopperInfo(IDTypes);}),
        std::make_pair("list shoppers ", [this](std::vector<std::string>& IDTypes){listShoppers(IDTypes);}),
        std::make_pair("lsh ", [this](std::vector<std::string>& IDTypes){listShoppers(IDTypes);}),
    };
    std::vector<std::string> simIDs;
    int simCount = 0;
    std::vector<Simulation> simulationsRunning;
};

#endif //YEAR1_CPP_PROJECT_COMMANDS_H
