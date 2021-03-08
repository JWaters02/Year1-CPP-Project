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
//endregion

//region Setters
//endregion

//region Getters
std::string Stock::getItemFromItemsStock(std::string itemName) {
    // If item is valid
    if (Item::isValidName(itemName)) {
        for (int item = 0; item < itemsStock.size(); item++) {
            if (itemName == itemsStock[item]) {
                itemsStock.erase(itemsStock.begin() + item);
                break;
            }
        }
    }
}

int Stock::getItemCostFromItemStockCosts() {
    return 0;
}
//endregion

