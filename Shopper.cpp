/*
 * THIS CLASS MANAGES THE SHOPPERS
 * */

#include "Shopper.h"

//region Constructor
Shopper::Shopper(int _shopperID) : shopperID(_shopperID) {
    setName();
    setHeight();
    setWeight();
    setAge();
}
//endregion

//region Functions
// Allows manager to give items with values to shopper if they wish
Item Shopper::giveShopperItem(const std::string& itemName, double itemCost, int numItems) {
    return Item(itemName, itemCost, numItems);
}

// All automatically generated items
Item Shopper::generateShopperItem() {
    int numRandomItems = itemBank.size();
    std::string itemName = itemBank[rand() % numRandomItems];
    int itemCost = itemCostBank[rand() % numRandomItems];
    int numItems = rand() % MAXITEMSPERITEM;
    return Item(itemName, itemCost, numItems);
}

// If manager does not give items, shopper will just pre generate certain number of items
std::vector<Item> Shopper::generateShopperItemList() {
    int itemsInBasket = rand() % MAXITEMSFORBASKET;
    std::vector<Item> basket;
    for (int items = 0; items < itemsInBasket; items++) {
        basket.push_back(generateShopperItem());
    }
    return basket;
}

// This allows the toggling of the shopper if it is inside the store or not
void Shopper::toggleIsInStore() {
    if (isInStore) {
        isInStore = false;
    } else {
        isInStore = true;
    }
}
//endregion

//region Setters
// Sets random name from name bank
void Shopper::setName() {
    int numRandomNames = nameBank.size();
    name = nameBank[rand() % numRandomNames];
};

// Sets random height between min and max heights
void Shopper::setHeight() {
    height = rand() % (MAXHEIGHT - MINHEIGHT) + MINHEIGHT;
}

// Sets random weight between min and max weights
void Shopper::setWeight() {
    weight = rand() % (MAXWEIGHT - MINWEIGHT) + MINWEIGHT;
}

// Sets random age between 0 and max age
void Shopper::setAge() {
    age = rand() % MAXAGE;
}
//endregion

//region Getters
bool Shopper::getIsInStore() const {
    return isInStore;
}

std::string Shopper::getName() const {
    return name;
}

int Shopper::getHeight() const {
    return height;
}

int Shopper::getWeight() const {
    return weight;
}

int Shopper::getAge() const {
    return age;
}

int Shopper::getID() const {
    return shopperID;
}

std::string Shopper::getItemsInBasketNames() {
    // TODO: Return this.items.names
    return std::string();
}

double Shopper::getItemInBasketCosts() {
    // TODO: Return this.items.costs
    return 0;
}

void Shopper::getShopperInfo() {
    std::cout << "SHOPPER INFO LALALALA" << std::endl;
}
//endregion

