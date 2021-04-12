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

    // Getters
    void getSimInfo();

    // Vars
    std::vector<std::string> shopperIDs;
private:
    // Vars
    bool isPaused = false;
    int simID;
    int shopperCount = 0;
    std::vector<Shopper> shoppersRunning;
};


#endif //YEAR1_CPP_PROJECT_SIMULATION_H