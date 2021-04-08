#include <iostream>
#include <memory>
#include <Windows.h>
#include "MainLoop.h"

void testingShopperClass() {
    std::vector<std::string> itemsPurchased = {"Apples", "Bananas", "Cherries"};
    std::unique_ptr<Shopper> shopper1 = std::make_unique<Shopper>();
    std::cout << "Name: " << shopper1->getName()
    << ", ID: " << shopper1->getID()
    << ", Age: " << shopper1->getAge()
    << ", Weight: " << shopper1->getWeight()
    << ", Height: " << shopper1->getHeight()
    << ", Is in store? " << shopper1->getIsInStore()
    << std::endl;
}

int main() {
    srand(time(nullptr));
    std::cout << "test" << std::endl;
    //testingShopperClass();

    std::unique_ptr<MainLoop> mainLoop = std::make_unique<MainLoop>();
    mainLoop->mainEventLoop();

    return 0;
}
