/*
 * THIS CLASS MANAGES THE SHOPPERS
 * */

#include "Shopper.h"

//region Constructor
Shopper::Shopper(int _shopperID, std::vector<Item>& _stock, bool _isRandomObject,
                 std::string _name, int _height, int _weight, int _age, bool _isInStore)
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
        isInStore = _isInStore;
        setItemBank();
        setItemCostBank();
    }
}
//endregion

//region Functions
/**
 * Allows file handler to give items with values to shoppers manually.
 *
 * @param itemName Item name.
 * @param itemCost Item cost.
 * @param numItems Number of items.
 */
void Shopper::giveShopperItem(const std::string itemName, double itemCost, int numItems) {
    basket.push_back(Item(itemName, itemCost, numItems));
}

/**
 * Generates a new item for the shopper.
 *
 * @param itemName Item name.
 * @param itemCost Item cost.
 * @param numItems Number of items.
 * @return Item.
 */
Item Shopper::generateShopperItem(const std::string itemName, const double itemCost, const int numItems) {
    return Item(itemName, itemCost, numItems);
}

/**
 * Processing for when the shopper picks up and item.
 */
void Shopper::pickupItem() {
    const int ITEMSTOPICKUP = rand() % 10 + 1;
    const int PICKITEM = rand() % itemBank.size();
    std::string itemName = itemBank[PICKITEM];
    double itemCost = itemCostBank[PICKITEM];
    std::string plural = "";
    bool canAddItem = true;

    if (ITEMSTOPICKUP > stock[PICKITEM].getNumItems()) {
        Logs::log("Shopper " + std::to_string(shopperID) + " failed to pickup "
            + itemName + " as it is out of stock!", 12);
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
        Logs::log(output, 10);
    }
}

/**
 * Processing for when the shopper drops an item.
 */
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
        Logs::log(output, 10);

        basket.erase(basket.begin() + ITEMTODROP);
    } else {
        Logs::log("Shopper " + std::to_string(shopperID) + " has no items to drop!", 12);
    }
}

/**
 * Processing for when the shopper checks out from the store.
 */
void Shopper::checkout() {
    double total = 0;
    for (int i = 0; i < basket.size(); i++) {
        total += basket[i].getItemCost() * basket[i].getNumItems();
    }

    std::string output1 = "Shopper " + std::to_string(shopperID) + " has checked out with a value of \x9C";
    std::string output2 = ", and has left the store!";
    Logs::precisionLog(output1, total, output2,10);

    isInStore = false;
}

/**
 * This is what drives the changing of every variable in shopper during event loop.
 *
 * @param doesCheckout Passthrough that changes if the shopper decides to checkout from the store.
 */
void Shopper::simulateShopper(bool& doesCheckout) {
    doesCheckout = false;
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
            doesCheckout = true;
        }
    } else {
        Logs::log("Shopper " + std::to_string(shopperID) + " is not in the store!", 12);
    }
}
//endregion

//region Setters
void Shopper::setID(int newID) {
    shopperID = newID;
}

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

std::string Shopper::getIsInStore() {
    if (isInStore) return "1";
    else return "0";
}

std::vector<Item> Shopper::getBasket() {
    return basket;
}

double Shopper::getMoneyMade() {
    double total = 0;
    for (int i = 0; i < basket.size(); i++) {
        total += basket[i].getItemCost() * basket[i].getNumItems();
    }
    return total;
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
                                  + ", costing: \x9C";
            std::string output2 = ".";
            const double cost = basket[item].getItemCost() * basket[item].getNumItems();
            Logs::precisionLog(output1, cost, output2, 7);
        }
    } else {
        Logs::log("This shopper is not in the store.", 12);
    }
}
//endregion

