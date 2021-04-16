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

// All automatically generated items
Item Shopper::generateShopperItem(int numItems, std::string itemName) {
    double itemCost = itemCostBank[rand() % itemBank.size()];
    return Item(itemName, itemCost, numItems);
}

void Shopper::pickupItem() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int ITEMSTOPICKUP = rand() % 10 + 1;
    std::string itemName = itemBank[rand() % itemBank.size()];
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
        basket.push_back(generateShopperItem(ITEMSTOPICKUP, itemName));
    }


    if (ITEMSTOPICKUP > 1) {
        plural = "s";
    }
    SetConsoleTextAttribute(hConsole, 10); // GREEN
    std::cout << "Shopper " << shopperID << " has picked up " << ITEMSTOPICKUP
    << " " << basket[basket.size() - 1].getItemName() << plural << "." << std::endl;
    SetConsoleTextAttribute(hConsole, 7); // DEFAULT
}

void Shopper::dropItem() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int ITEMTODROP = rand() % (basket.size());

    SetConsoleTextAttribute(hConsole, 10); // GREEN
    std::cout << "Shopper " << shopperID << " has dropped their "
    << basket[ITEMTODROP].getItemName() << "s." << std::endl;
    SetConsoleTextAttribute(hConsole, 7); // DEFAULT

    basket.erase(basket.begin() + ITEMTODROP);
}

void Shopper::checkout() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    double total = 0;
    for (int i = 0; i < basket.size(); i++) {
        total += basket[i].getItemCost() * basket[i].getNumItems();
    }

    SetConsoleTextAttribute(hConsole, 10); // GREEN
    std::cout.precision(2);
    std::cout << "Shopper " << shopperID << " has checked out with a value of $"
    << std::fixed << total << ", and has left the store!" << std::endl;
    SetConsoleTextAttribute(hConsole, 7); // DEFAULT

    isInStore = false;
}

// This is what drives the changing of every variable in shopper during event loop
void Shopper::simulateShopper() {
    if (isInStore) {
        const int ACTION = rand() % 100;
        const int CHANCETOPICKUP = 60;
        const int CHANCETODROP = CHANCETOPICKUP + 30;
        const int CHANCETOCHECKOUT = CHANCETODROP + 10;

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
    }
}
//endregion

//region Setters
void Shopper::setName() {
    int numRandomNames = nameBank.size();
    name = nameBank[rand() % numRandomNames];
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
    std::cout.precision(2);

    std::cout << "Name: " << getName()
    << "\nID: " << getID()
    << "\nAge: " << getAge()
    << "\nWeight: " << getWeight() << "kg"
    << "\nHeight: " << getHeight() << "cm"
    << std::endl;

    std::cout << "Items in basket: " << std::endl;
    for (int item = 0; item < basket.size(); item++) {
        std::cout << basket[item].getItemName()
        << " x" << basket[item].getNumItems()
        << ", costing: $" << std::fixed
        << basket[item].getItemCost() * basket[item].getNumItems()
        << "." << std::endl;
    }
}
//endregion

