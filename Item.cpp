/*
 * THIS CLASS MANAGES THE ITEMS THAT THE SHOPPERS CARRY
 * CHILD CLASS OF STOCKS?
 * */

#include "Item.h"

//region Constructor
Item::Item(std::string _itemName, double _itemCost) {
    itemName = _itemName;
    itemCost = _itemCost;

    checkName();

    // TODO: Reduce 1 from item in stocks class
}
//endregion

//region Functions
// If item name that doesn't exist has been inputted
void Item::checkName() {
    int itemCounter = 0;
    for (int i = 0; i < items.size(); i++) {
        if (itemName == items[i]) {
            itemCounter++;
        }
    }
    if (itemCounter != 1) {
        // TODO: Item does not exist - how do I output this?
        std::cout << "Item does not exist" << std::endl;
    }
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

