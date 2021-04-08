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

void Commands::pause(int pauseLength) {
    Sleep(pauseLength);
}

void Commands::addSim() {
    simCount++;
    std::unique_ptr<Simulation> newSim = std::make_unique<Simulation>(simCount);
    simIDs.push_back(std::to_string(simCount));
//    simulationsRunning.push_back(newSim);
}

void Commands::removeSim(int simID) {

}

void Commands::pauseSim(int simID) {

}

void Commands::continueSim(int simID) {

}
//endregion

//region Setters
void Commands::setCommand(std::string command) {
    if (command == "quit") {
        quit();
    } else if (command.starts_with("pause")) {

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
