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

class Item {
public:
    Item(std::string itemName, double itemCost, int numItems);

    // Functions
    void addItems(int _numItems);
    void decrementStock(int itemsPickedUp);

    // Getters
    std::string getItemName();
    double getItemCost();
    int getNumItems();
private:
    // Vars
    std::string itemName;
    double itemCost;
    int numItems;
};


#endif //YEAR1_CPP_PROJECT_ITEM_H
