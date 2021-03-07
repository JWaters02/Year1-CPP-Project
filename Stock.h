/*
 * THIS CLASS MANAGES ITEM STOCKS
 * GETS STOCKS OF ITEMS FROM FILE
 * */

#ifndef YEAR1_CPP_PROJECT_STOCK_H
#define YEAR1_CPP_PROJECT_STOCK_H

#include <iostream>
#include <vector>

class Stock {
public:
    Stock(std::vector<std::string>&& _items, std::vector<int>&& _itemCosts);
private:
    std::vector<std::string> items;
    std::vector<int> itemCosts;
};

#endif //YEAR1_CPP_PROJECT_STOCK_H
