/*
 * THIS CLASS MANAGES COMMANDS INPUTTED INTO THE CONSOLE
 * MANAGES PARSING OF COMMANDS
 * */

#include "Commands.h"

//region Constructor
//endregion

//region Functions
void Commands::quit() {
    exit(0);
}

void Commands::pause() {
    std::cout << "All simulations paused. Press any key to continue." << std::endl;
    std::string temp;
    std::cin >> temp;
}

void Commands::addSim() {
    if (simCount <= MAXID) {
        simCount++;
        std::unique_ptr<Simulation> newSim = std::make_unique<Simulation>(simCount);
        simIDs.push_back(std::to_string(simCount));
        simulationsRunning.push_back(*newSim);
    } else {
        std::cout << "Too many simulations running!" << std::endl;
    }
}

void Commands::removeSim() {
    simIDs.pop_back();
    simulationsRunning.pop_back();
    simCount--;
}

void Commands::pauseSim(std::string simID) {
    for (int sim = 0; sim < simCount; sim++) {
        if (simIDs[sim] == simID) {
            simulationsRunning[sim].pause();
        }
    }
}

void Commands::continueSim(std::string simID) {
    for (int sim = 0; sim < simCount; sim++) {
        if (simIDs[sim] == simID) {
            simulationsRunning[sim].resume();
        }
    }
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
    if (command == "quit") {
        quit();
    } else if (command == "pause") {
        pause();
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

std::string Commands::getSimIDs() {
    std::string ret = "";
    for (int i = 0; i < simIDs.size(); i++) {
        ret += simIDs[i] + "\n";
    }
    return ret;
}

std::string Commands::getHelp() {
    std::string ret = "Help page.\n"
                      "Contactless shopper simulator.\n"
                      "Press spacebar anytime whilst the simulations are running, to input a new command.\n"
                      "Blah";
    return ret;
}
//endregion
