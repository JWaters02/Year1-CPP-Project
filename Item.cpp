/*
 * THIS CLASS MANAGES THE ITEMS THAT THE SHOPPERS CARRY
 * CHILD CLASS OF STOCKS?
 * */

#include "Item.h"

//region Constructor
Item::Item(std::string _itemName, double _itemCost, int _numItems)
: itemName(_itemName), itemCost(_itemCost), numItems(_numItems) {

}
//endregion

//region Functions
void Item::addItems(int _numItems) {
    numItems += _numItems;
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

int Item::getNumItems() {
    return numItems;
}
//endregion

