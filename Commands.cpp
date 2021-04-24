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

//region Public Functions
void Commands::help() {
    std::string output = "Help page:";
    Logs::log(output, 10);

    output = "Contactless shopper simulator.\n"
             "Press spacebar anytime whilst the simulations are running, to input a new command.\n"
             "Commands syntax: <parameter> denotes required parameter.\n"
             "Commands are NOT capital sensitive, however spaces are still required.\n"
             "Aliases still require parameters if specified by the full command.\n"
             "E.g. to list simulation 3, commands could be 'list sim 3' or 'ls 3'";
    Logs::log(output, 7);
}

void Commands::commandList() {
    for (int command = 0; command < commands.size(); command++) {
        Logs::log(commands[command].first, 7);
    }
}

void Commands::aliases() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout << "Aliases:\n";
    for (int command = 0; command < commands.size(); command++) {
        SetConsoleTextAttribute(hConsole, 7); // DEFAULT
        std::cout << commands[command].first << ": ";
        SetConsoleTextAttribute(hConsole, 12); // RED
        std::cout << commands[command].second << std::endl;
    }
    SetConsoleTextAttribute(hConsole, 7); // DEFAULT
}

void Commands::quit() {
    exit(0);
}

void Commands::pause() {
    Logs::log("All simulations paused. Enter anything to continue.", 10);
    std::string temp;
    std::cin >> temp;
}

void Commands::saveSimulations() {
    /*
     * 1,0,55.2#apple,4,23+banana,1,50#1,joshua,19,45,180,1~apple,1.2,3+banana,0.8,4:2,joe,21,55,175,1~watermelon,2.3,1
     * # = Main separator
     * , = Separator
     * + = Looping separator
     * : = Item -> shoppers separator
     * ~ = Shopper -> item separator
     */
    if (simCount == 0) {
        Logs::log("There are no simulations to save!", 12);
    } else {
        std::string totalOutput = "";
        // Loop through simulation IDs
        for (int sim = 0; sim < simCount; sim++) {
            std::string line = "";
            line += std::to_string(sim + 1) + ","
                    + simulationsRunning[sim].getPaused() + ","
                    + std::to_string(simulationsRunning[sim].getMoneyInAccount()) + "#";

            // Loop through stocks
            for (int stock = 0; stock < simulationsRunning[sim].getStock().size(); stock++) {
                line += simulationsRunning[sim].getStock()[stock].getItemName()
                        + "," + truncateDouble(simulationsRunning[sim].getStock()[stock].getItemCost())
                        + "," + std::to_string(simulationsRunning[sim].getStock()[stock].getNumItems());
                if (stock == simulationsRunning[sim].getStock().size()-1) {
                    // Use main separator
                    line += "#";
                } else {
                    // Use looping separator
                    line += "+";
                }
            }

            if (simulationsRunning[sim].getShoppers().size() == 0) {
                Logs::log("Sim: " + simIDs[sim] + " has no shoppers to save!", 12);
                line.replace(line.size() - 1, line.size(), "");
            } else {
                // Loop through shoppers
                for (int shopper = 0; shopper < simulationsRunning[sim].getShoppers().size(); shopper++) {
                    line += std::to_string(simulationsRunning[sim].getShoppers()[shopper].getID())
                            + "," + simulationsRunning[sim].getShoppers()[shopper].getName()
                            + "," + std::to_string(simulationsRunning[sim].getShoppers()[shopper].getAge())
                            + "," + std::to_string(simulationsRunning[sim].getShoppers()[shopper].getWeight())
                            + "," + std::to_string(simulationsRunning[sim].getShoppers()[shopper].getHeight())
                            + "," + simulationsRunning[sim].getShoppers()[shopper].getIsInStore();

                    if (simulationsRunning[sim].getShoppers()[shopper].getBasket().size() == 0) {
                        Logs::log("Sim: " + simIDs[sim]+ ", shopper: "
                        + std::to_string(simulationsRunning[sim].getShoppers()[shopper].getID())
                        + " has no items to save!", 12);
                        line.replace(line.size() - 2, line.size() - 1, "");
                    } else {
                        line += "~";
                        // Loop through items in basket
                        for (int item = 0; item < simulationsRunning[sim].getShoppers()[shopper].getBasket().size(); item++) {
                            line += simulationsRunning[sim].getShoppers()[shopper].getBasket()[item].getItemName()
                                    + "," + truncateDouble(simulationsRunning[sim].getShoppers()[shopper].getBasket()[item].getItemCost())
                                    + "," + std::to_string(simulationsRunning[sim].getShoppers()[shopper].getBasket()[item].getNumItems())
                                    + "+";
                        }
                    }
                    if (shopper != simulationsRunning[sim].getShoppers().size() - 1) {
                        // Use item -> shoppers separator
                        line.replace(line.size() - 1, line.size(), ":");
                    } else {
                        line.replace(line.size() - 1, line.size(), "");
                    }
                }
            }
            if (sim == simCount - 1) {
                totalOutput += line;
            } else {
                totalOutput += line + "\n";
            }
        }
        FileHandler::saveToFile(totalOutput, getFileName());

        Logs::log("Save file:", 10);
        Logs::log(totalOutput, 7);
    }
}

void Commands::loadSimulations() {
    /*
     * 1,0,55.2#apple,4,23+banana,1,50#1,joshua,19,45,180,1~apple,1.2,3+banana,0.8,4:2,joe,21,55,175,1~watermelon,2.3,1
     * # = Main separator
     * , = Separator
     * + = Looping separator
     * : = Shoppers separator
     * ~ = Shopper -> item separator
     */
    std::vector<std::string> lines = FileHandler::loadFromFile(getFileName());
    std::vector<std::string> _simIDs;
    std::vector<Simulation> _simulationsRunning;
    int _simCount = 0;

    // Loop through each simulation (line)
    for (int line = 0; line < lines.size(); line++) {
        // Split each line into their primary elements
        std::vector<std::string> simulationElement = splitCommand(lines[line], '#');

        // First, split sim info details and capture
        std::vector<std::string> simInfo = splitCommand(simulationElement[0], ',');
        _simIDs.push_back(simInfo[0]);
        _simCount++;
        std::unique_ptr<Simulation> _simulation = std::make_unique<Simulation>(std::stoi(simInfo[0]));
        _simulation->setPaused(simInfo[1]);
        _simulation->setMoneyInAccount(std::stod(simInfo[2]));

        // Next, split stock info into individual stocks
        std::vector<std::string> stockInfo = splitCommand(simulationElement[1], '+');
        // Loop through each item stock
        for (int stock = 0; stock < stockInfo.size(); stock++) {
            // Split each item stock into individual parameters
            std::vector<std::string> stockType = splitCommand(stockInfo[stock], ',');
            _simulation->setStock(stockType[0],
                                  std::stod(stockType[1]),
                                  std::stoi(stockType[2]));
        }

        // Check if any shoppers exist
        if (simulationElement.size() < 3) {
            Logs::log("No shoppers exist in simulation " + simInfo[0] + ".", 12);
        } else {
            // Next, shoppers from sim info and stocks
            std::vector<std::string> shoppers = splitCommand(simulationElement[2], ':');
            // Loop through shoppers
            for (int shopper = 0; shopper < shoppers.size(); shopper++) {
                // Split the shoppers up
                std::vector<std::string> shopperAndItem = splitCommand(shoppers[shopper], '~');
                // Split the shopper details up
                std::vector<std::string> shopperDetails = splitCommand(shopperAndItem[0], ',');
                // Give shopper details to sim
                _simulation->setShopper(shopperDetails[0],
                                        shopperDetails[1],
                                        std::stoi(shopperDetails[2]),
                                        std::stoi(shopperDetails[3]),
                                        std::stoi(shopperDetails[4]),
                                        shopperDetails[5]);

                // Check if items exist
                if (shopperAndItem.size() < 2) {
                    Logs::log("Shopper " + shopperDetails[0] + " in sim " + simInfo[0] + " does not contain any items.", 12);
                } else {
                    // Split the items up
                    std::vector<std::string> items = splitCommand(shopperAndItem[1], '+');
                    // Loop through the items
                    for (int item = 0; item < items.size(); item++) {
                        // Split item into item details
                        std::vector<std::string> itemDetails = splitCommand(items[item], ',');

                        // Give item details to shopper
                        _simulation->giveShopperItem(std::stoi(shopperDetails[0]),
                                                     itemDetails[0],
                                                     std::stod(itemDetails[1]),
                                                     std::stoi(itemDetails[2]));
                    }
                }
            }
        }
        // Push simulation into sims stack
        _simulationsRunning.push_back(*_simulation);
    }
    simulationsRunning = _simulationsRunning;
    simIDs = _simIDs;
    simCount = _simCount;
}

void Commands::deleteFile() {
    FileHandler::deleteFile(getFileName());
}

void Commands::printFile() {
    FileHandler::printFileContents(getFileName());
}

void Commands::changeTickSpeed() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 3); // DARK CYAN
    std::cout << "Please enter new tickspeed (milliseconds):" << std::endl;
    std::string _tickSpeed;
    std::cin >> _tickSpeed;
    SetConsoleTextAttribute(hConsole, 7); // DEFAULT

    if (isNumber(_tickSpeed)) {
        tickSpeed = std::stoi(_tickSpeed);
        Logs::log("Tickspeed changed to " + _tickSpeed + "!", 10);
    } else {
        Logs::log("Please input a valid number!", 12);
    }
}

void Commands::listSimIDs() {
    std::string ret = "";
    for (int i = 0; i < simIDs.size(); i++) {
        ret += "Simulation ID: " + simIDs[i] + "\n";
    }
    std::cout << ret << std::endl;
}

void Commands::addSim() {
    // If there is space on the stack for more simulations
    if (simCount <= MAXID) {
        simCount++;
        simIDs.push_back(std::to_string(simCount));
        simulationsRunning.emplace_back(simCount);
        Logs::log("New simulation added!", 10);
    } else {
        Logs::log("Too many simulations running!", 12);
    }
}

void Commands::removeSim() {
    // If there are actually any sims to remove
    if (simCount > 0) {
        simIDs.pop_back();
        simulationsRunning.pop_back();
        simCount--;
        Logs::log("Simulation removed from stack.", 10);
    } else {
        Logs::log("There are no simulations to remove.", 12);
    }
}

void Commands::listTotalMoneyMade() {
    double totalMoneyMade = 0;
    for (int sim = 0; sim < simCount; sim++) {
        totalMoneyMade += simulationsRunning[sim].getMoneyInAccount();
    }
    if (totalMoneyMade < 0) {
        Logs::precisionLog("Total money made over all simulations: \x9C", totalMoneyMade,
                           ". You should consider increasing your prices!", 12);
    } else {
        Logs::precisionLog("Total money made over all simulations: \x9C", totalMoneyMade, ".", 10);
    }
}

void Commands::pauseSim(std::vector<std::string>& IDTypes) {
    if (isIDValid(IDTypes)) {
        for (int sim = 0; sim < simCount; sim++) {
            if (simIDs[sim] == IDTypes[0]) {
                simulationsRunning[sim].pause();
            }
        }
        Logs::log("Selected simulation paused.", 10);
    }
}

void Commands::continueSim(std::vector<std::string>& IDTypes) {
    if (isIDValid(IDTypes)) {
        for (int sim = 0; sim < simCount; sim++) {
            if (simIDs[sim] == IDTypes[0]) {
                simulationsRunning[sim].resume();
            }
        }
        Logs::log("Selected simulation unpaused.", 10);
    }
}

void Commands::listSimInfo(std::vector<std::string>& IDTypes) {
    if (isIDValid(IDTypes)) {
        Logs::log("Information for simulation ID " + IDTypes[0], 10);
        for (int sim = 0; sim < simCount; sim++) {
            if (simIDs[sim] == IDTypes[0]) {
                simulationsRunning[sim].getSimInfo();
            }
        }
    }
}

void Commands::addShopper(std::vector<std::string>& IDTypes) {
    if (isIDValid(IDTypes)) {
        for (int sim = 0; sim < simCount; sim++) {
            if (simIDs[sim] == IDTypes[0]) {
                simulationsRunning[sim].addShopper();
            }
        }
    }
}

void Commands::removeShopper(std::vector<std::string>& IDTypes) {
    if (isIDValid(IDTypes)) {
        for (int sim = 0; sim < simCount; sim++) {
            if (simIDs[sim] == IDTypes[0]) {
                simulationsRunning[sim].removeShopper();
            }
        }
    }
}

void Commands::listShopperInfo(std::vector<std::string>& IDTypes) {
    if (isIDValid(IDTypes)) {
        Logs::log("Information for shopper ID " + IDTypes[1] + " in simulation ID " + IDTypes[0], 10);
        for (int sim = 0; sim < simCount; sim++) {
            if (simIDs[sim] == IDTypes[0]) {
                simulationsRunning[sim].listShopperInfo(IDTypes[1]);
            }
        }
    }
}

void Commands::listShoppers(std::vector<std::string>& IDTypes) {
    if (isIDValid(IDTypes)) {
        Logs::log("Shoppers in simulation ID " + IDTypes[0] + ":", 10);
        for (int sim = 0; sim < simCount; sim++) {
            if (simIDs[sim] == IDTypes[0]) {
                simulationsRunning[sim].listShoppers();
            }
        }
    }
}

void Commands::orderItems(std::vector<std::string> &IDTypes) {
    if (isIDValid(IDTypes)) {
        Logs::log("Please input the item name you wish to order: ", 3);
        std::string itemName;
        std::cin >> itemName;
        Logs::log("Please input the number of this item you wish to order: ", 3);
        int numItems;
        std::cin >> numItems;

        for (int sim = 0; sim < simCount; sim++) {
            if (simIDs[sim] == IDTypes[0]) {
                simulationsRunning[sim].orderItems(itemName, numItems);
            }
        }
    }
}

void Commands::simulateShoppers() {
    for (int sim = 0; sim < simCount; sim++) {
        simulationsRunning[sim].simulateShoppers();
    }
}
//endregion

//region Private Functions
bool Commands::endsWith(std::string& string, std::string& ending) {
    if (string.length() >= ending.length()) {
        return (0 == string.compare(string.length() - ending.length(), ending.length(), ending));
    } else return false;
}

std::string Commands::truncateDouble(double num) {
    std::string str = std::to_string(num);
    std::string ending = ".";
    str.erase(str.find_last_not_of('0') + 1, std::string::npos);
    if (endsWith(str, ending)) {
        str.replace(str.length() - 1, str.length(), "");
    }
    return str;
}

bool Commands::isIDValid(std::vector<std::string>& IDTypes) {
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
        // Check if there are any sims running
        if (simIDs.size() > 0) {
            // Check if the shopper ID is in the ID stack
            if (!std::count(simulationsRunning[std::stoi(simID)-1].shopperIDs.begin(),
                            simulationsRunning[std::stoi(simID)-1].shopperIDs.end(),
                            shopperID)) {
                isShopperIDValid = false;
            }
        } else {
            isShopperIDValid = false;
            isSimIDValid = false;
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
        Logs::log("ID is not a number or command entered incorrectly!", 12);
        return false;
    } else if (!isSimIDValid) {
        Logs::log("Simulation ID is not a number or command entered incorrectly!", 12);
        return false;
    } else if (!isShopperIDValid) {
        Logs::log("Shopper ID is not a number or command entered incorrectly!", 12);
        return false;
    }
    return true;
}

std::vector<std::string> Commands::splitCommand(std::string string, char delimeter) {
    std::string line;
    std::vector<std::string> ret;
    std::stringstream ss(string);
    while (std::getline(ss, line, delimeter)) {
        ret.push_back(line);
    }
    return ret;
}

bool Commands::isNumber(const std::string &string) {
    std::string::const_iterator iterator = string.begin();
    while (iterator != string.end() && std::isdigit(*iterator)) {
        iterator++;
    }
    return !string.empty() && iterator == string.end();
}

std::vector<std::string> Commands::parseActualCommand(std::string command) {
    std::vector<std::string> actualCommand = splitCommand(command, ' ');
    bool trailingRequired = false;

    // Remove any trailing numbers
    for (int j = 0; j < actualCommand.size(); j++) {
        if (isNumber(actualCommand[j])) {
            actualCommand[j] = "NULL";
            trailingRequired = true;
        }
    }
    for (int j = actualCommand.size(); j --> 0;) {
        if (actualCommand[j] == "NULL") {
            actualCommand.erase(std::remove(
                    actualCommand.begin(), actualCommand.end(), actualCommand[j]), actualCommand.end()
            );
            break;
        }
    }

    // Add trailing space
    if (trailingRequired) {
        actualCommand[actualCommand.size()-1] += " ";
    }

    return actualCommand;
}

bool Commands::isCommandValid(std::string command) {
    // Check if string even contains space
    for (int i = 0; i < commandFunc.size(); i++) {
        std::vector<std::string> actualCommand = parseActualCommand(command);

        switch (actualCommand.size()) {
            case 0:
                return false;
            case 1:
                if (actualCommand[0] == commandFunc[i].first) {
                    return true;
                }
                break;
            case 2:
                if (actualCommand[0] + " " + actualCommand[1] == commandFunc[i].first) {
                    return true;
                }
                break;
            case 3:
                if (actualCommand[0] + " " + actualCommand[1] + " " + actualCommand[2] == commandFunc[i].first) {
                    return true;
                }
                break;
        }
    }
    return false;
}
//endregion

//region Setters
void Commands::setCommand(std::string command) {
    // Check command is valid
    if (isCommandValid(command)) {
        for (int i = 0; i < commandFunc.size(); i++) {
            if (command.starts_with(commandFunc[i].first)) {
                command.replace(0, commandFunc[i].first.length(), "");
                std::vector<std::string> IDTypes = splitCommand(command, ' ');
                commandFunc[i].second(IDTypes);
                break;
            }
        }
    } else {
        Logs::log("Command does not exist!", 12);
    }
}
//endregion

//region Getters
std::string Commands::getFileName() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 3); // DARK CYAN
    std::cout << "Please enter a filename:" << std::endl;
    std::string fileName;
    std::cin >> fileName;
    SetConsoleTextAttribute(hConsole, 7); // DEFAULT

    return fileName;
}
//endregion
