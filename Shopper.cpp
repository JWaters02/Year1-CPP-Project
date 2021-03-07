/*
 * THIS CLASS MANAGES THE SHOPPERS
 * */

#include "Shopper.h"

//region Constructor
Shopper::Shopper() {
    setName();
    setHeight();
    setWeight();
    setAge();
    setID();
}
//endregion

//region Functions
// Allows manager to give items with values to shopper if they wish
void Shopper::giveShopperItem(const std::string& itemName, double itemCost) {
    // TODO: Incorporate with item objects
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
    int _numRandomNames = nameBank.size();
    name = nameBank[rand() % _numRandomNames];
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

// Needs to make sure it does not share the same ID with other shoppers
void Shopper::setID() {
    bool isNewID = true;
    int possibleID;
    while (isNewID) {
        possibleID = rand() % MAXID;
        for (int i = 0; i < IDs.size(); i++) {
            if (possibleID == IDs[i]) {
                isNewID = false;
                break;
            }
        }
    }
    ID = possibleID;
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
    return ID;
}

std::string Shopper::getItemsInBasketNames() {
    // TODO: Return this.items.names
    return std::string();
}

double Shopper::getItemInBasketCosts() {
    // TODO: Return this.items.costs
    return 0;
}
//endregion

