/*
 * THIS CLASS MANAGES COMMANDS INPUTTED INTO THE CONSOLE
 * MANAGES PARSING OF COMMANDS
 * */

#include "Shopper.h"

//region Constructor
Shopper::Shopper(double _totalSpent, std::vector<std::string> _itemsPurchased) {
    history.totalSpent = _totalSpent;
    history.itemsPurchased = _itemsPurchased;
}
//endregion

//region Setters
std::string Shopper::setName() {
    int _numRandomNames = nameBank.size();
    std::string selectedName = nameBank[rand() % _numRandomNames];
    return selectedName;
};

int Shopper::setHeight() {
    return rand() % (MAXHEIGHT - MINHEIGHT) + MINHEIGHT;
}

int Shopper::setWeight() {
    return rand() % (MAXWEIGHT - MINWEIGHT) + MINWEIGHT;
}

int Shopper::setAge() {
    return rand() % MAXAGE;
}

// Needs to make sure it does not share the same ID with other shoppers
int Shopper::setID() {
    bool isNewID = true;
    int possibleID;
    while (isNewID) {
        possibleID = rand() % MAXID;
        for (int i = 0; i < IDs.size(); i++) {
            if (possibleID == IDs[i]) {
                isNewID = false;
            }
        }
    }
    return possibleID;
}

bool Shopper::setIsInStore(bool _isInStore) {
    isInStore = _isInStore;
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
//endregion

