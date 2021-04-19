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
    // Functions

    // Setters
    static std::vector<Item> setStock();

    // Getters
    static std::vector<std::string> getItemBank();
    static std::vector<double> getItemCostBank();
private:
    // Functions

    // Vars
    std::vector<std::string> itemBank;
    std::vector<double> itemCostBank;
};

#endif //YEAR1_CPP_PROJECT_STOCK_H
