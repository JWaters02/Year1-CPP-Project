#include <iostream>
#include <memory>
#include "Shopper.h"
#include "Item.h"

void testingShopperClass() {
    std::vector<std::string> itemsPurchased = {"Apples", "Bananas", "Cherries"};
    std::unique_ptr<Shopper> shopper1 = std::make_unique<Shopper>(24.2, itemsPurchased);
    std::cout << "Age: " << shopper1->getAge() << " is in store?" << shopper1->getIsInStore() <<
        " Name: " << shopper1->getName() << std::endl;
}

int main() {
    srand(time(nullptr));
    std::cout << "test" << std::endl;
    testingShopperClass();

    // TODO: Move to commands class
    std::cout << "Pls input item" << std::endl;
    std::string item;
    std::cin >> item;
    while (!Item::isValidName(item)) {
        std::cout << "Pls input NEW item" << std::endl;
        std::cin >> item;
    }

    return 0;
}
