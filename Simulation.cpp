/*
 * MANAGES EVERY INDIVIDUAL SIMULATION THAT IS BEING RUN
 */

#include "Simulation.h"

//region Constructor
Simulation::Simulation(int _simID) : simID(_simID) {

}

//region Functions
void Simulation::pause() {
    isPaused = true;
}

void Simulation::resume() {
    isPaused = false;
}

void Simulation::addShopper() {

}

void Simulation::removeShopper() {

}

void Simulation::listShopperInfo(std::string shopperID) {

}

void Simulation::listShoppers() {

}
//endregion

//region Setters

//endregion

//endregion

//region Getters
void Simulation::getSimInfo() {
    if (!isPaused) {
        std::cout << "SIMULATION " << simID << " HAS RUN, WOOO!" << std::endl;
    }
}
//endregion
