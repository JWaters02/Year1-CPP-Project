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

    // Getters
    std::string getItemFromItemsStock(std::string itemName, int numItems);
    std::vector<int> getItemStockCount();
private:
    // Functions
    bool isItemInStock(std::string itemName);

    std::vector<std::string> itemsStock;
    std::vector<int> itemStockCount;
    std::vector<int> itemStockCosts;
};

#endif //YEAR1_CPP_PROJECT_STOCK_H
