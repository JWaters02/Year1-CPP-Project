/*
 * MANAGES EVERY INDIVIDUAL SIMULATION THAT IS BEING RUN
 */

#ifndef YEAR1_CPP_PROJECT_SIMULATION_H
#define YEAR1_CPP_PROJECT_SIMULATION_H

#include <iostream>

class Simulation {
public:
    // Constructor
    Simulation(int _simID);

    // Functions
    void pause();
    void resume();

    // Getters
    void getSimInfo();

    // Vars

private:
    // Vars
    int simID;
};


#endif //YEAR1_CPP_PROJECT_SIMULATION_H
