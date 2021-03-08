/*
 * THIS CLASS MANAGES LOGGING OF EVENTS
 * */

#include "Stock.h"

//region Constructor
Stock::Stock(std::vector<std::string>& _items, std::vector<int>& _itemCosts )
: itemsStock(_items), itemStockCosts(_itemCosts) {

}
//endregion

//region Functions
bool Stock::isItemInStock(std::string itemName) {
    int itemCounter = 0;
    for (int item = 0; item < itemsStock.size(); item++) {
        if (itemName == itemsStock[item]) {
            itemCounter++;
        }
        // If the item exists in stock, but there is none left
        if (itemStockCount[item] == 0) {
            std::cout << "Item is out of stock" << std::endl;
            return false;
        }
    }
    if (itemCounter != 1) {
        std::cout << "Item does not exist" << std::endl;
        return false;
    }
    return true;
}
//endregion

//region Setters
//endregion

//region Getters
// Get the requested item from stock
std::string Stock::getItemFromItemsStock(std::string itemName, int numItems) {
    // If item is in stock
    if (isItemInStock(itemName)) {
        for (int item = 0; item < itemsStock.size(); item++) {
            // If current item is selected
            if (itemName == itemsStock[item]) {
                // Remove item from stock
                if ((itemStockCount[item] -= numItems) < 0) {
                    int maxItemsCanRemove = itemStockCount[item];

                } else {
                    itemStockCount[item] -= numItems;
                }

                itemsStock.erase(itemsStock.begin() + item);
                itemStockCosts.erase(itemStockCosts.begin() + item);
                return "";
            }
        }
    }
}

std::vector<int> Stock::getItemStockCount() {
    return itemStockCount;
}
//endregion

