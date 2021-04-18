/*
 * MANAGES EVERY INDIVIDUAL SIMULATION THAT IS BEING RUN
 */

#include "Simulation.h"

//region Constructor
Simulation::Simulation(int _simID) : simID(_simID) {

}
//endregion

//region Functions
void Simulation::pause() {
    isPaused = true;
}

void Simulation::resume() {
    isPaused = false;
}

void Simulation::addShopper() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // If there is space on the stack for more shoppers
    if (shopperCount <= MAXID) {
        shopperCount++;
        std::unique_ptr<Shopper> newShopper = std::make_unique<Shopper>(shopperCount, true);
        shopperIDs.push_back(std::to_string(shopperCount));
        shoppersRunning.push_back(*newShopper);
        SetConsoleTextAttribute(hConsole, 10); // GREEN
        std::cout << "New shopper added!" << std::endl;
    } else {
        SetConsoleTextAttribute(hConsole, 12); // RED
        std::cout << "Too many shoppers running!" << std::endl;
    }
    SetConsoleTextAttribute(hConsole, 7); // DEFAULT
}

void Simulation::removeShopper() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // If there are actually any shoppers to remove
    if (shopperCount > 0) {
        shopperIDs.pop_back();
        shoppersRunning.pop_back();
        shopperCount--;
        SetConsoleTextAttribute(hConsole, 10); // GREEN
        std::cout << "Shopper removed from stack." << std::endl;
    } else {
        SetConsoleTextAttribute(hConsole, 12); // RED
        std::cout << "There are no shoppers to remove." << std::endl;
    }
    SetConsoleTextAttribute(hConsole, 7); // DEFAULT
}

void Simulation::listShopperInfo(std::string shopperID) {
    for (int shopper = 0; shopper < shopperCount; shopper++) {
        if (shopperIDs[shopper] == shopperID) {
            shoppersRunning[shopper].getShopperInfo();
        }
    }
}

void Simulation::listShoppers() {
    std::string ret = "";
    for (int i = 0; i < shopperIDs.size(); i++) {
        ret += "Shopper ID: " + shopperIDs[i] + "\n";
    }
    std::cout << ret << std::endl;
}

void Simulation::simulateShoppers() {
    if (!isPaused) {
        if (shopperCount > 0) {
            std::cout << "SIMULATION " << simID << ":" << std::endl;
        }
        for (int shopper = 0; shopper < shopperCount; shopper++) {
            shoppersRunning[shopper].simulateShopper();
        }
    }
}
//endregion

//region Setters

//endregion

//region Getters
void Simulation::getSimInfo() {
    std::cout << "No. shoppers: " << shopperCount
    << "\nPaused? " << isPaused << std::endl;
}
//endregion
