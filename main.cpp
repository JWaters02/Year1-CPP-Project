#include <iostream>
#include "Shopper.h"

void testingShopperClass() {
    std::vector<std::string> itemsPurchased = {"Apples", "Bananas", "Cherries"};
    Shopper* shopper1 = new Shopper(24.2, itemsPurchased);
    std::cout << shopper1->getAge() << shopper1->getIsInStore();
}

int main() {
    std::cout << "test" << std::endl;
    testingShopperClass();
    return 0;
}
