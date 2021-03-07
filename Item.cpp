/*
 * THIS CLASS MANAGES THE ITEMS THAT THE SHOPPERS CARRY
 * CHILD CLASS OF STOCKS?
 * */

#include "Item.h"

namespace itemGlobals {
    std::vector<std::string> items = {"Apples", "Bananas"};; // TODO: Get items from files class (or object from stocks?)
}

//region Constructor
Item::Item(std::string _itemName, double _itemCost)
: itemName(_itemName), itemCost(_itemCost) {
    // TODO: Reduce 1 from item in stocks class
}
//endregion

//region Functions
// If item name that doesn't exist has been inputted
bool Item::isValidName(std::string item) {
    int itemCounter = 0;
    for (int i = 0; i < itemGlobals::items.size(); i++) {
        if (item == itemGlobals::items[i]) {
            itemCounter++;
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
std::string Item::getItemName() {
    return itemName;
}

double Item::getItemCost() {
    return itemCost;
}
//endregion

