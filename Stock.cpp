/*
 * THIS CLASS MANAGES LOGGING OF EVENTS
 * */

#include "Stock.h"

//region Constructor
//endregion

//region Functions
//endregion

//region Setters
/**
 * Sets all items to have random numbers of stock.
 *
 * @return List of items.
 */
std::vector<Item> Stock::setRandomStock() {
    // Get stock of amount of items; names, costs, nums
    std::vector<Item> items;
    for (int item = 0; item < getItemBank().size(); item++) {
        const int ITEMSPERSTOCK = rand() % 50 + 1;
        std::unique_ptr<Item> newItem = std::make_unique<Item>(getItemBank()[item], getItemCostBank()[item], ITEMSPERSTOCK);
        items.push_back(*newItem);
    }
    return items;
}

/**
 * Initialises the stock with a new item.
 *
 * @param itemName Item name.
 * @param itemCost Item cost.
 * @param numItems Number of items to add.
 * @return Item.
 */
Item Stock::setStock(std::string itemName, double itemCost, int numItems) {
    std::unique_ptr<Item> newItem = std::make_unique<Item>(itemName, itemCost, numItems);
    return *newItem;
}
//endregion

//region Getters
std::vector<std::string> Stock::getItemBank() {
    return {"Apple", "Banana", "Cherry",
            "Date", "Elderberry", "Fig",
            "Grape", "Huckleberry", "Kiwi",
            "Lemon", "Mango", "Nectarine",
            "Orange", "Pear", "Quince",
            "Raisin", "Satsuma", "Tomato",
            "Ugli", "Victoria Plum",
            "Watermelon", "Zucchini"};
}

std::vector<double> Stock::getItemCostBank() {
    return {1.2, 0.8, 0.2,
            0.3, 0.6, 1,
            0.1, 1, 1.2,
            0.5, 1.6, 1,
            1, 1.1, 2,
            0.1, 1, 0.7,
            2, 1.5,
            2.3, 5};
}

std::vector<double> Stock::getSupplierItemCostBank() {
    return {1, 0.6, 0.1,
            0.2, 0.4, 0.8,
            0.1, 0.9, 1.1,
            0.2, 1.3, 0.7,
            0.5, 0.9, 1.3,
            0.1, 0.5, 0.5,
            1.6, 1.4,
            2, 3};
}
//endregion

