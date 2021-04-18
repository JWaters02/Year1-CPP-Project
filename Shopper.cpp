/*
 * THIS CLASS MANAGES THE SHOPPERS
 * */

#include "Shopper.h"

//region Constructor
Shopper::Shopper(int _shopperID, bool _isRandomObject, std::string _name, int _height, int _weight, int _age)
: shopperID(_shopperID) {
    if (_isRandomObject) {
        setName();
        setHeight();
        setWeight();
        setAge();
    } else {
        name = _name;
        height = _height;
        weight = _weight;
        age = _age;
        // TODO: Add any other vars like items
    }
}
//endregion

//region Functions
// Allows manager to give items with values to shopper if they wish
Item Shopper::giveShopperItem(const std::string& itemName, double itemCost, int numItems) {
    return Item(itemName, itemCost, numItems);
}

Item Shopper::generateShopperItem(int numItems, std::string itemName, double itemCost) {
    return Item(itemName, itemCost, numItems);
}

void Shopper::pickupItem() {
    const int ITEMSTOPICKUP = rand() % 10 + 1;
    const int PICKITEM = rand() % itemBank.size();
    std::string itemName = itemBank[PICKITEM];
    double itemCost = itemCostBank[PICKITEM];
    std::string plural = "";
    bool canAddItem = true;

    // Find if the item already exists in the basket
    for (int item = 0; item < basket.size(); item++) {
        if (basket[item].getItemName() == itemName) {
            basket[item].addItems(ITEMSTOPICKUP);
            canAddItem = false;
        }
    }
    if (canAddItem) {
        // Item does not exist in basket
        basket.push_back(generateShopperItem(ITEMSTOPICKUP, itemName, itemCost));
    }

    if (ITEMSTOPICKUP > 1) {
        plural = "s";
    }
    std::string output = "Shopper " + std::to_string(shopperID) + " has picked up " + std::to_string(ITEMSTOPICKUP)
            + " " + basket[basket.size() - 1].getItemName() + plural + ".";
    Logs::log(output, 10); // GREEN
}

void Shopper::dropItem() {
    if (basket.size() > 0) {
        const int ITEMTODROP = rand() % (basket.size());

        std::string output = "Shopper " + std::to_string(shopperID) + " has dropped their "
                + basket[ITEMTODROP].getItemName() + "s.";
        Logs::log(output, 10); // GREEN

        basket.erase(basket.begin() + ITEMTODROP);
    } else {
        std::string output = "Shopper " + std::to_string(shopperID) + " has no items to drop!";
        Logs::log(output, 12); // RED
    }
}

void Shopper::checkout() {
    double total = 0;
    for (int i = 0; i < basket.size(); i++) {
        total += basket[i].getItemCost() * basket[i].getNumItems();
    }

    std::string output = "Shopper " + std::to_string(shopperID) + " has checked out with a value of $"
            + std::to_string(total) + "0, and has left the store!";
    Logs::log(output, 10, true); // GREEN

    isInStore = false;

    // TODO: Use items to get from stocks
}

// This is what drives the changing of every variable in shopper during event loop
void Shopper::simulateShopper() {
    if (isInStore) {
        const int ACTION = rand() % 100;
        const int CHANCETOPICKUP = 80;
        const int CHANCETODROP = CHANCETOPICKUP + 15;
        const int CHANCETOCHECKOUT = CHANCETODROP + 5;

        // Weighting on certain conditions
        if (ACTION >= 0 && ACTION < CHANCETOPICKUP) {
            // Pick up an item
            pickupItem();
        } else if (ACTION >= CHANCETOPICKUP && ACTION < CHANCETODROP) {
            // Drop an item
            dropItem();
        } else if (ACTION >= CHANCETODROP && ACTION < CHANCETOCHECKOUT) {
            // Checkout
            checkout();
        }
    } else {
        std::string output = "Shopper " + std::to_string(shopperID) + " is not in the store!";
        Logs::log(output, 12); // RED
    }
}
//endregion

//region Setters
void Shopper::setName() {
    name = nameBank[rand() % nameBank.size()];
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
//endregion

//region Getters
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

void Shopper::getShopperInfo() {
    std::string output = "Name: " + getName()
            + "\nID: " + std::to_string(getID())
            + "\nAge: " + std::to_string(getAge())
            + "\nWeight: " + std::to_string(getWeight()) + "kg"
            + "\nHeight: " + std::to_string(getHeight()) + "cm";
    Logs::log(output, 7, true);

    output = "Items in basket: ";
    for (int item = 0; item < basket.size(); item++) {
        std::cout << basket[item].getItemName()
        << " x" << basket[item].getNumItems()
        << ", costing: $" << std::fixed
        << basket[item].getItemCost() * basket[item].getNumItems()
        << "." << std::endl;
    }
}
//endregion

