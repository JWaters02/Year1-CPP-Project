/*
 * THIS CLASS MANAGES LOGGING OF EVENTS
 * */

#include "Stock.h"

namespace items {
    static std::vector<std::string> stock;
    static std::vector<int> stockCount;
    static std::vector<int> stockCosts;
}

//region Constructor
Stock::Stock(std::vector<std::string>& _items, std::vector<int>& _itemCosts ) {

}
//endregion

//region Functions
bool Stock::isItemInStock(std::string itemName) {
    int itemCounter = 0;
    for (int item = 0; item < items::stock.size(); item++) {
        if (itemName == items::stock[item]) {
            itemCounter++;
        }
        // If the item exists in stock, but there is none left
        if (items::stockCount[item] == 0) {
            // TODO: Remove this to commands class
            std::cout << "Item: " << items::stock[item] << " is out of stock" << std::endl;
            return false;
        }
    }
    if (itemCounter != 1) {
        // TODO: Remove this to commands class
        std::cout << "Item: " << itemName << " does not exist" << std::endl;
        return false;
    }
    return true;
}

void Stock::decrementStock(std::string stockToReduce, int numItems) {
    for (int item = 0; item < items::stock.size(); ++item) {
        if (stockToReduce == items::stock[item]) {
            if ((items::stockCount[item] -= numItems) <= 0) {
                // TODO: Remove this to commands class
                std::cout << "Item: " << items::stock[item] << " is out of stock" << std::endl;
                break;
            } else {
                items::stockCount[item]--;
                break;
            }
        }
    }
}
//endregion

//region Setters
//endregion

//region Getters
// Get the requested item from stock
void Stock::getItemFromItemsStock(std::string itemName, int numItems) {
    // If item is in stock
    if (isItemInStock(itemName)) {
        for (int item = 0; item < items::stock.size(); item++) {
            // If current item is selected
            if (itemName == items::stock[item]) {
                // Decrement stock
                decrementStock(itemName, numItems);

                // Remove item from stock
                items::stock.erase(items::stock.begin() + item);
                items::stockCosts.erase(items::stockCosts.begin() + item);
            }
        }
    }
}

std::vector<int> Stock::getItemStockCount() {
    return items::stockCount;
}
//endregion

