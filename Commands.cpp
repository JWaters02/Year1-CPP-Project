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
                      "Commands are NOT capital sensitive, however spaces are still required.\n";
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
    for (int sim = 0; sim < simCount; sim++) {
        if (simIDs[sim] == simID) {
            simulationsRunning[sim].getSimInfo();
        }
    }
}
//endregion

//region Setters
void Commands::setCommand(std::string command) {
    // I would use switch statement here but C++ switch does not accept strings
    if (command == "help") {
        help();
    } else if (command == "quit") {
        quit();
    } else if (command == "pause") {
        pause();
    } else if (command == "list sims") {
        listSimIDs();
    } else if (command == "add sim") {
        addSim();
    } else if (command == "remove sim") {
        removeSim();
    } else if (command.starts_with("list sims")) {
        // Get the ID on the right of the command
        std::string simID;
        listSimInfo(simID);
    } else if (command.starts_with("continue sim")) {
        // Get the ID on the right of the command
        std::string simID;
        continueSim(simID);
    } else if (command.starts_with("pause sim")) {
        // Get the ID on the right of the command
        std::string simID;
        pauseSim(simID);
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
