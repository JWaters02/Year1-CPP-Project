/*
 * THIS CLASS MANAGES THE ITEMS THAT THE SHOPPERS CARRY
 * CHILD CLASS OF STOCKS?
 * */

#ifndef YEAR1_CPP_PROJECT_ITEM_H
#define YEAR1_CPP_PROJECT_ITEM_H

#include <iostream>
#include <vector>
#include <random>
#include <memory>
#include "Stock.h"

class Item {
public:
    Item(std::string itemName, double itemCost);

    // Functions
    static bool isValidName(std::string name);

    // Getters
    std::string getItemName();
    double getItemCost();
private:
    // Vars
    std::string itemName;
    double itemCost;
};


#endif //YEAR1_CPP_PROJECT_ITEM_H
