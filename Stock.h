/*
 * THIS CLASS MANAGES ITEM STOCKS
 * GETS STOCKS OF ITEMS FROM FILE
 * */

#ifndef YEAR1_CPP_PROJECT_STOCK_H
#define YEAR1_CPP_PROJECT_STOCK_H

#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
#include "Item.h"

class Stock {
public:
    // Setters
    static std::vector<Item> setRandomStock();
    static Item setStock(std::string itemName, double itemCost, int numItems);

    // Getters
    static std::vector<std::string> getItemBank();
    static std::vector<double> getItemCostBank();
};

#endif //YEAR1_CPP_PROJECT_STOCK_H
