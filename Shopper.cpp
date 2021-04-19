/*
 * THIS CLASS MANAGES THE SHOPPERS
 * */

#include "Shopper.h"

//region Constructor
Shopper::Shopper(int _shopperID, std::vector<Item>& _stock, bool _isRandomObject,
                 std::string _name, int _height, int _weight, int _age)
: shopperID(_shopperID), stock(_stock) {
    if (_isRandomObject) {
        setName();
        setHeight();
        setWeight();
        setAge();
        setItemBank();
        setItemCostBank();
    } else {
        name = _name;
        height = _height;
        weight = _weight;
        age = _age;
    }
    // TODO: Add ability to change item costs
}
//endregion

//region Functions
// Allows manager (or file handler) to give items with values to shopper if they wish
void Shopper::giveShopperItem(const std::string itemName, double itemCost, int numItems) {
    basket.push_back(Item(itemName, itemCost, numItems));
}

Item Shopper::generateShopperItem(const std::string itemName, const double itemCost, const int numItems) {
    return Item(itemName, itemCost, numItems);
}

void Shopper::pickupItem() {
    const int ITEMSTOPICKUP = rand() % 10 + 1;
    const int PICKITEM = rand() % itemBank.size();
    std::string itemName = itemBank[PICKITEM];
    double itemCost = itemCostBank[PICKITEM];
    std::string plural = "";
    bool canAddItem = true;

    if (ITEMSTOPICKUP > stock[PICKITEM].getNumItems()) {
        Logs::log("Shopped failed to pickup " + itemName + " as it is out of stock!", 12);
    } else {
        // Decrement stock
        stock[PICKITEM].decrementStock(ITEMSTOPICKUP);

        // Find if the item already exists in the basket
        for (int item = 0; item < basket.size(); item++) {
            if (basket[item].getItemName() == itemName) {
                basket[item].addItems(ITEMSTOPICKUP);
                canAddItem = false;
                break;
            }
        }
        if (canAddItem) {
            // Item does not exist in basket
            basket.push_back(generateShopperItem(itemName, itemCost, ITEMSTOPICKUP));
        }

        if (ITEMSTOPICKUP > 1) {
            plural = "s";
        }
        std::string output = "Shopper " + std::to_string(shopperID) + " has picked up " + std::to_string(ITEMSTOPICKUP)
                             + " " + basket[basket.size() - 1].getItemName() + plural + ".";
        Logs::log(output, 10); // GREEN
    }
}

void Shopper::dropItem() {
    if (basket.size() > 0) {
        const int ITEMTODROP = rand() % (basket.size());

        // Increase stock
        for (int item = 0; item < stock.size(); item++) {
            if (stock[item].getItemName() == basket[ITEMTODROP].getItemName()) {
                stock[item].addItems(basket[ITEMTODROP].getNumItems());
            }
        }

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

    std::string output1 = "Shopper " + std::to_string(shopperID) + " has checked out with a value of $";
    std::string output2 = ", and has left the store!";
    Logs::precisionLog(output1, total, output2,10); // GREEN

    isInStore = false;
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

void Shopper::setItemBank() {
    itemBank = Stock::getItemBank();
}

void Shopper::setItemCostBank() {
    itemCostBank = Stock::getItemCostBank();
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
            + "\nWeight: " + std::to_string(getWeight()) + " kg"
            + "\nHeight: " + std::to_string(getHeight()) + " cm";
    Logs::log(output, 7);

    if (isInStore) {
        std::cout << "Items in basket: " << std::endl;
        for (int item = 0; item < basket.size(); item++) {
            std::string output1 = basket[item].getItemName()
                                  + " x" + std::to_string(basket[item].getNumItems())
                                  + ", costing: $";
            std::string output2 = ".";
            const double cost = basket[item].getItemCost() * basket[item].getNumItems();
            Logs::precisionLog(output1, cost, output2, 7);
        }
    } else {
        Logs::log("This shopper is not in the store.", 12); // RED
    }
}
//endregion

