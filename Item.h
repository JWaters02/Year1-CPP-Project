/*
 * THIS CLASS MANAGES THE ITEMS THAT THE SHOPPERS CARRY
 * CHILD CLASS OF STOCKS?
 * */

#ifndef YEAR1_CPP_PROJECT_ITEM_H
#define YEAR1_CPP_PROJECT_ITEM_H

#include <iostream>
#include <vector>
#include <random>

class Item {
public:
    Item(std::string itemName, double itemCost);

    // Functions
    void checkName();

    // Getters
    std::string getItemName();
    double getItemCost();
private:
    // Vars
    std::string itemName;
    double itemCost;
    std::vector<std::string> items; // TODO: Get items from files class (or object from stocks?)
};


#endif //YEAR1_CPP_PROJECT_ITEM_H
