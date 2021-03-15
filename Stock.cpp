/*
 * THIS CLASS MANAGES LOGGING OF EVENTS
 * */

#include "Stock.h"

//region Constructor
Stock::Stock(std::vector<std::string>& _items, std::vector<int>& _itemCosts ) {

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
            // TODO: Remove this to commands class
            std::cout << "Item: " << itemsStock[item] << " is out of stock" << std::endl;
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
    for (int item = 0; item < itemsStock.size(); ++item) {
        if (stockToReduce == itemsStock[item]) {
            if ((itemStockCount[item] -= numItems) <= 0) {
                // TODO: Remove this to commands class
                std::cout << "Item: " << itemsStock[item] << " is out of stock" << std::endl;
                break;
            } else {
                itemStockCount[item]--;
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
        for (int item = 0; item < itemsStock.size(); item++) {
            // If current item is selected
            if (itemName == itemsStock[item]) {
                // Decrement stock
                decrementStock(itemName, numItems);

                // Remove item from stock
                itemsStock.erase(itemsStock.begin() + item);
                itemStockCosts.erase(itemStockCosts.begin() + item);
            }
        }
    }
}

std::vector<int> Stock::getItemStockCount() {
    return itemStockCount;
}
//endregion

