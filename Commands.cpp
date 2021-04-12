/*
 * THIS CLASS MANAGES COMMANDS INPUTTED INTO THE CONSOLE
 * MANAGES PARSING OF COMMANDS
 * */

#include "Commands.h"

//region Constructor
Commands::Commands() {
    std::sort(commandFunc.begin(), commandFunc.end(),
              [](const funcPair& a, const funcPair& b){return (a.first.length() > b.first.length());});
};
//endregion

//region Functions
void Commands::help() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10); // GREEN
    std::cout << "Help page:" << std::endl;

    SetConsoleTextAttribute(hConsole, 7); // DEFAULT
    std::string ret = "Contactless shopper simulator.\n"
                      "Press spacebar anytime whilst the simulations are running, to input a new command.\n"
                      "Commands syntax: <parameter> denotes required parameter.\n"
                      "Commands are NOT capital sensitive, however spaces are still required.\n"
                      "Aliases still require parameters if specified by the full command.\n"
                      "E.g. to list simulation 3, commands could be 'list sim 3' or 'ls 3'";
    std::cout << ret << std::endl;
}

void Commands::commandList() {
    std::string ret = "";
    for (int i = 0; i < commands.size(); i++) {
        ret += commands[i] + "\n";
    }
    std::cout << ret << std::endl;
}

void Commands::aliases() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout << "Aliases:\n";
    for (int command = 0; command < commandAliases.size(); command++) {
        SetConsoleTextAttribute(hConsole, 7); // DEFAULT
        std::cout << commands[command] << ": ";
        SetConsoleTextAttribute(hConsole, 12); // RED
        std::cout << commandAliases[command] << std::endl;
    }
}

void Commands::quit() {
    exit(0);
}

void Commands::pause() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12); // RED
    std::cout << "All simulations paused. Enter anything to continue." << std::endl;
    std::string temp;
    SetConsoleTextAttribute(hConsole, 7); // DEFAULT
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
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (simCount <= MAXID) {
        simCount++;
        std::unique_ptr<Simulation> newSim = std::make_unique<Simulation>(simCount);
        simIDs.push_back(std::to_string(simCount));
        simulationsRunning.push_back(*newSim);
        SetConsoleTextAttribute(hConsole, 12); // RED
        std::cout << "New simulation added!" << std::endl;
        SetConsoleTextAttribute(hConsole, 7); // DEFAULT
    } else {
        SetConsoleTextAttribute(hConsole, 12); // RED
        std::cout << "Too many simulations running!" << std::endl;
        SetConsoleTextAttribute(hConsole, 7); // DEFAULT
    }
}

void Commands::removeSim() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    simIDs.pop_back();
    simulationsRunning.pop_back();
    simCount--;
    SetConsoleTextAttribute(hConsole, 12); // RED
    std::cout << "Simulation removed from stack." << std::endl;
    SetConsoleTextAttribute(hConsole, 7); // DEFAULT

}

void Commands::pauseSim(std::vector<std::string>& IDTypes) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (isIDValid(IDTypes)) {
        for (int sim = 0; sim < simCount; sim++) {
            if (simIDs[sim] == IDTypes[0]) {
                simulationsRunning[sim].pause();
            }
        }
        SetConsoleTextAttribute(hConsole, 12); // RED
        std::cout << "Selected simulation paused." << std::endl;
        SetConsoleTextAttribute(hConsole, 7); // DEFAULT
    }
}

void Commands::continueSim(std::vector<std::string>& IDTypes) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (isIDValid(IDTypes)) {
        for (int sim = 0; sim < simCount; sim++) {
            if (simIDs[sim] == IDTypes[0]) {
                simulationsRunning[sim].resume();
            }
        }
        SetConsoleTextAttribute(hConsole, 12); // RED
        std::cout << "Selected simulation unpaused." << std::endl;
        SetConsoleTextAttribute(hConsole, 7); // DEFAULT
    }
}

void Commands::listSimInfo(std::vector<std::string>& IDTypes) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (isIDValid(IDTypes)) {
        SetConsoleTextAttribute(hConsole, 12); // RED
        std::cout << "Information for simulation ID " << IDTypes[0] << std::endl;
        SetConsoleTextAttribute(hConsole, 7); // DEFAULT
        for (int sim = 0; sim < simCount; sim++) {
            if (simIDs[sim] == IDTypes[0]) {
                simulationsRunning[sim].getSimInfo();
            }
        }
    }
}

void Commands::addShopper(std::vector<std::string>& IDTypes) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (isIDValid(IDTypes)) {
        for (int sim = 0; sim < simCount; sim++) {
            if (simIDs[sim] == IDTypes[0]) {
                simulationsRunning[sim].addShopper();
            }
        }
        SetConsoleTextAttribute(hConsole, 12); // RED
        std::cout << "Shopper added to simulation " << IDTypes[0] << "'s stack" <<  std::endl;
        SetConsoleTextAttribute(hConsole, 7); // DEFAULT
    }
}

void Commands::removeShopper(std::vector<std::string>& IDTypes) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (isIDValid(IDTypes)) {
        for (int sim = 0; sim < simCount; sim++) {
            if (simIDs[sim] == IDTypes[0]) {
                simulationsRunning[sim].removeShopper();
            }
        }
        SetConsoleTextAttribute(hConsole, 12); // RED
        std::cout << "Shopper remove from simulation " << IDTypes[0] << "'s stack" << std::endl;
        SetConsoleTextAttribute(hConsole, 7); // DEFAULT
    }
}

void Commands::listShopperInfo(std::vector<std::string>& IDTypes) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (isIDValid(IDTypes)) {
        SetConsoleTextAttribute(hConsole, 12); // RED
        std::cout << "Information for shopper ID " << IDTypes[1] << " in simulation ID " << IDTypes[0] << std::endl;
        SetConsoleTextAttribute(hConsole, 7); // DEFAULT
        for (int sim = 0; sim < simCount; sim++) {
            if (simIDs[sim] == IDTypes[0]) {
                simulationsRunning[sim].listShopperInfo(IDTypes[1]);
            }
        }
    }
}

void Commands::listShoppers(std::vector<std::string>& IDTypes) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (isIDValid(IDTypes)) {
        SetConsoleTextAttribute(hConsole, 12); // RED
        std::cout << "Shoppers in simulation ID " << IDTypes[0] << ":" << std::endl;
        SetConsoleTextAttribute(hConsole, 7); // DEFAULT
        for (int sim = 0; sim < simCount; sim++) {
            if (simIDs[sim] == IDTypes[0]) {
                simulationsRunning[sim].listShoppers();
            }
        }
    }
}

bool Commands::isIDValid(std::vector<std::string>& IDTypes) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12); // RED
    bool isNumValid = true;
    bool isSimIDValid = true;
    bool isShopperIDValid = true;
    std::string simID = "";
    if (IDTypes.size() == 0) {
        isNumValid = false;
    } else if (IDTypes.size() == 1) {
        simID = IDTypes[0];
    } else if (IDTypes.size() == 2) {
        simID = IDTypes[0];
        std::string shopperID = IDTypes[1];

        // Check if the shopper ID inputted is an actual number
        for (int i = 0; i < shopperID.size(); i++) {
            if (!isdigit(shopperID[i])) {
                isShopperIDValid = false;
                break;
            }
        }
        // Then, check if the shopper ID is in the ID stack
        if (!std::count(simulationsRunning[std::stoi(simID)].shopperIDs.begin(),
                        simulationsRunning[std::stoi(simID)].shopperIDs.end(), shopperID)) {
            isShopperIDValid = false;
        }
    } else {
        isNumValid = false;
    }
    
    // Check if the simulation ID inputted is an actual number
    for (int i = 0; i < simID.size(); i++) {
        if (!isdigit(simID[i])) {
            isSimIDValid = false;
            break;
        }
    }
    // Check if the simulation ID is in the ID stack
    if (!std::count(simIDs.begin(), simIDs.end(), simID)) {
        isSimIDValid = false;
    }

    if (!isNumValid) {
        std::cout << "ID is not a number or command entered incorrectly!" << std::endl;
        return false;
    } else if (!isSimIDValid) {
        std::cout << "Simulation ID is not a number or command entered incorrectly!" << std::endl;
        return false;
    } else if (!isShopperIDValid) {
        std::cout << "Shopper ID is not a number or command entered incorrectly!" << std::endl;
        return false;
    }
    SetConsoleTextAttribute(hConsole, 7); // DEFAULT
    return true;
}

std::vector<std::string> Commands::splitCommand(std::string command, std::string delimeter) {
    std::vector<std::string> ret;
    while (command.size()) {
        int index = command.find(delimeter);
        if (index != std::string::npos) {
            ret.push_back(command.substr(0, index));
            command = command.substr(index + delimeter.size());
            if (command.size() == 0) {
                ret.push_back(command);
            } else {
                ret.push_back(command);
                command = "";
            }
        }
    }
    return ret;
}
//endregion

//region Setters
void Commands::setCommand(std::string command) {
    for (int i = 0; i < commandFunc.size(); i++) {
        if (command.starts_with(commandFunc[i].first)) {
            command.replace(0, commandFunc[i].first.length(), "");
            std::vector<std::string> IDTypes = splitCommand(command, " ");
            commandFunc[i].second(IDTypes);
            break;
        }
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

void Commands::getSimInfo() {
    for (int sim = 0; sim < simCount; sim++) {
        simulationsRunning[sim].getSimInfo();
    }
}
//endregion
