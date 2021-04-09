/*
 * THIS CLASS MANAGES COMMANDS INPUTTED INTO THE CONSOLE
 * MANAGES PARSING OF COMMANDS
 * */

#include "Commands.h"

//region Constructor
//endregion

//region Functions
void Commands::help() {
    std::string ret = "Help page.\n"
                      "Contactless shopper simulator.\n"
                      "Press spacebar anytime whilst the simulations are running, to input a new command.\n"
                      "Commands syntax: <parameter> denotes required parameter.\n"
                      "Commands are NOT capital sensitive, however spaces are still required.\n"
                      "Aliases still require parameters if specified by the full command.\n"
                      "";
    std::cout << ret << std::endl;
}

void Commands::aliases() {
    std::string ret = "Aliases:\n";
    for (int alias = 0; alias < commandAliases.size(); alias++) {
        ret += commands[alias] + ": " + commandAliases[alias] + "\n";
    }
    std::cout << ret << std::endl;
}

void Commands::quit() {
    exit(0);
}

void Commands::pause() {
    std::cout << "All simulations paused. Enter anything to continue." << std::endl;
    std::string temp;
    std::cin >> temp;
}

void Commands::listSimIDs() {
    std::string ret = "";
    for (int i = 0; i < simIDs.size(); i++) {
        ret += "Simulation ID: " + simIDs[i] + "\n";
    }
    std::cout << ret << std::endl;
}

void Commands::addSim() {
    if (simCount <= MAXID) {
        simCount++;
        std::unique_ptr<Simulation> newSim = std::make_unique<Simulation>(simCount);
        simIDs.push_back(std::to_string(simCount));
        simulationsRunning.push_back(*newSim);
        std::cout << "New simulation added!" << std::endl;
    } else {
        std::cout << "Too many simulations running!" << std::endl;
    }
}

void Commands::removeSim() {
    simIDs.pop_back();
    simulationsRunning.pop_back();
    simCount--;
    std::cout << "Simulation removed from stack." << std::endl;
}

void Commands::pauseSim(std::string simID) {
    for (int sim = 0; sim < simCount; sim++) {
        if (simIDs[sim] == simID) {
            simulationsRunning[sim].pause();
        }
    }
    std::cout << "Selected simulation paused." << std::endl;
}

void Commands::continueSim(std::string simID) {
    for (int sim = 0; sim < simCount; sim++) {
        if (simIDs[sim] == simID) {
            simulationsRunning[sim].resume();
        }
    }
    std::cout << "Selected simulation unpaused." << std::endl;
}

void Commands::listSimInfo(std::string simID) {
    std::cout << "Information for simulation ID " << simID << std::endl;
    for (int sim = 0; sim < simCount; sim++) {
        if (simIDs[sim] == simID) {
            simulationsRunning[sim].getSimInfo();
        }
    }
}

void Commands::addShopper(std::string simID) {

}

void Commands::removeShopper(std::string simID) {

}

void Commands::listShopperInfo(std::string simID, std::string shopperID) {

}

void Commands::listShoppers(std::string simID, std::string shopperID) {

}

void Commands::isIDValid(std::string simID, std::string shopperID, int commandType) {
    bool isNumFlag = true;
    // First, check if the simulation ID inputted is an actual number
    for (int i = 0; i < simID.size(); i++) {
        if (!isdigit(simID[i])) {
            isNumFlag = false;
        }
    }

    // Then, check if the simulation ID is in the ID stack
    if (!std::count(simIDs.begin(), simIDs.end(), simID)) {
        isNumFlag = false;
    }

    // If ID is number, run command
    if (isNumFlag) {
        switch (commandType) {
            case 0:
                listSimInfo(simID);
            case 1:
                continueSim(simID);
            case 2:
                pauseSim(simID);
        }
    } else {
        std::cout << "ID is not a number or command entered incorrectly!" << std::endl;
    }
};
//endregion

//region Setters
void Commands::setCommand(std::string command) {
    // I would use switch statement here but C++ switch does not accept strings
    if (command == "help" || command == "h") {
        help();
    } else if (command == "aliases" || command == "a") {
        aliases();
    } else if (command == "quit" || command == "q") {
        quit();
    } else if (command == "pause" || command == "p") {
        pause();
    } else if (command == "list sims" || command == "ls") {
        listSimIDs();
    } else if (command == "add sim" || command == "as") {
        addSim();
    } else if (command == "remove sim" || command == "rs") {
        removeSim();
    } else if (command.starts_with("list sim info") || command.starts_with("lsi")) {
        // Get the ID on the right of the command
        std::string simID = command.replace(0, 14, "");

        // Check that ID is a digit
        isIDValid(simID, 0);
    } else if (command.starts_with("continue sim") || command.starts_with("cs")) {
        // Get the ID on the right of the command
        std::string simID = command.replace(0, 12, "");

        // Check that ID is a digit
        isIDValid(simID, 1);
    } else if (command.starts_with("pause sim") || command.starts_with("ps")) {
        // Get the ID on the right of the command
        std::string simID = command.replace(0, 10, "");

        // Check that ID is a digit
        isIDValid(simID, 2);
    } else if (command.starts_with("add shopper") || command.starts_with("ash")) {

    } else if (command.starts_with("remove shopper") || command.starts_with("rsh")) {

    } else if (command.starts_with("list shopper info") || command.starts_with("lshi")) {

    } else if (command.starts_with("list shoppers") || command.starts_with("lsh")) {

    }
}
//endregion

//region Getters
std::string Commands::getCommandList() {
    std::string ret = "";
    for (int i = 0; i < commands.size(); i++) {
        ret += commands[i] + "\n";
    }
    return ret;
}

std::string Commands::getShopperIDs() {
    return std::string();
}

std::string Commands::listShoppers() {
    return std::string();
}
//endregion
