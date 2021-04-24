/*
 * MANAGES EVERY INDIVIDUAL SIMULATION THAT IS BEING RUN
 */

#include "Simulation.h"

//region Constructor
Simulation::Simulation(int _simID) : simID(_simID) {
    setRandomStock();
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
    // If there is space on the stack for more shoppers
    if (shopperCount <= MAXID) {
        shopperCount++;
        shopperIDs.push_back(std::to_string(shopperCount));
        shoppersRunning.emplace_back(shopperCount, stock, true);
        Logs::log("New shopper added!", 10);
    } else {
        Logs::log("Too many shoppers running!", 12);
    }
}

void Simulation::removeShopper() {
    // If there are actually any shoppers to remove
    if (shopperCount > 0) {
        shopperIDs.pop_back();
        shoppersRunning.pop_back();
        shopperCount--;
        Logs::log("Shopper removed from stack.", 10);
    } else {
        Logs::log("There are no shoppers to remove.", 12);
    }
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

void Simulation::orderItems(std::string itemName, int numItems) {
    for (int item = 0; item < stock.size(); item++) {
        if (stock[item].getItemName() == itemName) {
            moneyInAccount -= Stock::getSupplierItemCostBank()[item] * numItems;
            stock[item].addItems(numItems);
            Logs::log("More " + stock[item].getItemName() + "s have been ordered!", 10);
            if (moneyInAccount < 0) {
                Logs::precisionLog("This simulation is in debt! Your simulation account has: \x9C", moneyInAccount,
                                   "!", 12);
            } else {
                Logs::precisionLog("Your simumlation account has: \x9C", moneyInAccount, "!", 10);
            }
        }
    }
}

void Simulation::giveShopperItem(int ID, std::string itemName, double itemCost, int numItems) {
    shoppersRunning[ID - 1].giveShopperItem(itemName, itemCost, numItems);
}

void Simulation::simulateShoppers() {
    if (!isPaused) {
        if (shopperCount > 0) {
            std::cout << "SIMULATION " << simID << ":" << std::endl;
        }

        for (int shopper = 0; shopper < shopperCount; shopper++) {
            bool checkout;
            shoppersRunning[shopper].simulateShopper(checkout);
            if (checkout) {
                // Work out money gained to simulation
                moneyInAccount += shoppersRunning[shopper].getMoneyMade();
            }
        }

        if (moneyInAccount < 0 && shopperCount > 0) {
            Logs::precisionLog("This simulation is in debt! Your simulation account has: \x9C", moneyInAccount,
                               "!", 12);
        } else if (moneyInAccount > 0 && shopperCount > 0) {
            Logs::precisionLog("Your simumlation account has: \x9C", moneyInAccount, "!", 10);
        }
    }
}
//endregion

//region Setters
void Simulation::setPaused(std::string _isPaused) {
    if (_isPaused == "1") isPaused = true;
    else isPaused = false;
}

void Simulation::setMoneyInAccount(double money) {
    moneyInAccount = money;
}

void Simulation::setStock(std::string itemName, double itemCost, int numItems) {
    stock.push_back(Stock::setStock(itemName, itemCost, numItems));
}

void Simulation::setShopper(std::string ID, std::string name, int age, int weight, int height, std::string isInStore) {
    bool _isInStore;
    if (isInStore == "1") _isInStore = true;
    else _isInStore = false;
    shoppersRunning.emplace_back(std::stoi(ID), stock, false, name, height, weight, age, _isInStore);
    shopperIDs.push_back(ID);
    shopperCount++;
}

void Simulation::setRandomStock() {
    stock = Stock::setRandomStock();
}
//endregion

//region Getters
std::string Simulation::getPaused() {
    if (isPaused) return "1";
    else return "0";
}

std::vector<Item>& Simulation::getStock() {
    return stock;
}

std::vector<Shopper> Simulation::getShoppers() {
    return shoppersRunning;
}

double Simulation::getMoneyInAccount() {
    return moneyInAccount;
}

void Simulation::getSimInfo() {
    Logs::log( "No. shoppers: " + std::to_string(shopperCount)
        + "\nPaused? " + getPaused() + "\nStocks: ", 7);
    for (int item = 0; item < stock.size(); item++) {
        std::string output = stock[item].getItemName() + " x" + std::to_string(stock[item].getNumItems());
        Logs::log(output, 7);
    }
    if (moneyInAccount < 0) {
        Logs::precisionLog("Money in account: \x9C", moneyInAccount, ".", 12);
    } else {
        Logs::precisionLog("Money in account: \x9C", moneyInAccount, ".", 10);
    }
}
//endregion
