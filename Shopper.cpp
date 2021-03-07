/*
 * THIS CLASS MANAGES THE SHOPPERS
 * */

#include "Shopper.h"

//region Constructor
Shopper::Shopper(double _totalSpent, std::vector<std::string> _itemsPurchased) {
    history.totalSpent = _totalSpent;
    history.itemsPurchased = _itemsPurchased;

    setName();
    setHeight();
    setWeight();
    setAge();
    setID();
}
//endregion

//region Functions
// Allows manager to give items with values to shopper if they wish
void Shopper::giveShopperItem(std::string itemName, double itemCost) {
    // TODO: Incorporate with item objects
}
//endregion

//region Setters
void Shopper::setName() {
    int _numRandomNames = nameBank.size();
    std::string selectedName = nameBank[rand() % _numRandomNames];
    name = selectedName;
};

void Shopper::setHeight() {
    height = rand() % (MAXHEIGHT - MINHEIGHT) + MINHEIGHT;

}

void Shopper::setWeight() {
    weight = rand() % (MAXWEIGHT - MINWEIGHT) + MINWEIGHT;
}

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

// This allows the toggling of the shopper if it is inside the store or not
bool Shopper::setIsInStore(bool _isInStore) {
    isInStore = _isInStore;
    if (isInStore) {
        return false;
    } else {
        return true;
    }
}
//endregion

//region Getters
bool Shopper::getIsInStore() const {
    return isInStore;
}

std::string Shopper::getName() {
    return name;
}

int Shopper::getHeight() {
    return height;
}

int Shopper::getWeight() {
    return weight;
}

int Shopper::getAge() {
    return age;
}

int Shopper::getID() {
    return ID;
}

std::string Shopper::getItemNames() {
    // TODO: Return this.items.names
    return std::string();
}

double Shopper::getItemCosts() {
    // TODO: Return this.items.costs
    return 0;
}
//endregion

