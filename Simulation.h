/*
 * MANAGES EVERY INDIVIDUAL SIMULATION THAT IS BEING RUN
 */

#ifndef YEAR1_CPP_PROJECT_SIMULATION_H
#define YEAR1_CPP_PROJECT_SIMULATION_H

#include <vector>
#include <iostream>
#include <string>
#include <windows.h>
#include <memory>
#include "Shopper.h"

class Simulation {
public:
    // Constructor
    Simulation(int _simID);

    // Functions
    void pause();
    void resume();
    void addShopper();
    void removeShopper();
    void listShopperInfo(std::string shopperID);
    void listShoppers();
    void orderItems(std::string itemName, int numItems);
    void giveShopperItem(int ID, std::string itemName, double itemCost, int numItems);
    void simulateShoppers();

    // Setters
    void setPaused(std::string _isPaused);
    void setStock(std::string itemName, double itemCost, int numItems);
    void setShopper(std::string ID, std::string name, int age, int weight, int height, std::string isInStore);

    // Getters
    std::string getPaused();
    std::vector<Item>& getStock();
    std::vector<Shopper> getShoppers();
    double getMoneyInAccount();
    void getSimInfo();

    // Vars
    std::vector<std::string> shopperIDs;
private:
    // Setters
    void setRandomStock();

    // Consts
    static const int MAXID = 10; // Max of 10 shoppers per sim

    // Vars
    bool isPaused = false;
    int simID;
    int shopperCount = 0;
    std::vector<Shopper> shoppersRunning;
    std::vector<Item> stock;
    double moneyInAccount = 50; // Start with $50
};


#endif //YEAR1_CPP_PROJECT_SIMULATION_H
