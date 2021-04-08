/*
 * THIS CLASS MANAGES ITEM STOCKS
 * GETS STOCKS OF ITEMS FROM FILE
 * */

#ifndef YEAR1_CPP_PROJECT_STOCK_H
#define YEAR1_CPP_PROJECT_STOCK_H

#include <iostream>
#include <vector>
#include <cmath>
#include "Item.h"

class Stock {
public:
    Stock(std::vector<std::string>& _items, std::vector<int>& _itemCosts);

    // Functions

    // Getters
    static void getItemFromItemsStock(std::string itemName, int numItems);
    std::vector<int> getItemStockCount();
private:
    // Functions
    static bool isItemInStock(std::string itemName);
    static void decrementStock(std::string stockToReduce, int numItems);
};

#endif //YEAR1_CPP_PROJECT_STOCK_H
