/*
 * THIS CLASS MANAGES THE SHOPPERS
 * EACH SHOPPER HAS ITS OWN RANDOM SET OF VALUES WHEN INSTANTIATED
 * SHOPPER IS NEVER CHANGED?
 * THEREFORE IS NOT REQUIRED TO BE INSTANTIATED WITH DIFFERENT VALUES
 * */

#ifndef YEAR1_CPP_PROJECT_SHOPPER_H
#define YEAR1_CPP_PROJECT_SHOPPER_H

#include <iostream>
#include <vector>
#include <random>
#include "Item.h"

class Shopper {
public:
    Shopper();

    // Functions
    Item giveShopperItem(const std::string& itemName, double itemCost, int numItems);
    void toggleIsInStore();

    // Getters
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] int getHeight() const;
    [[nodiscard]] int getWeight() const;
    [[nodiscard]] int getAge() const;
    [[nodiscard]] int getID() const;
    [[nodiscard]] bool getIsInStore() const;
    static std::string getItemsInBasketNames();
    static double getItemInBasketCosts();
private:
    // Functions
    Item generateShopperItem();
    std::vector<Item> generateShopperItemList();

    // Setters
    void setName();
    void setHeight();
    void setWeight();
    void setAge();
    void setID();

    // Consts
    static const int MAXHEIGHT = 240;
    static const int MINHEIGHT = 90;
    static const int MAXWEIGHT = 200;
    static const int MINWEIGHT = 15;
    static const int MAXAGE = 120;
    static const int MAXID = 100;
    static const int MAXITEMSPERITEM = 20;
    static const int MAXITEMSFORBASKET = 50;

    // Vars
    std::string name;
    std::vector<std::string> nameBank = {"Joshua", "Joe"}; // TODO: Get names from files class
    std::vector<int> IDs = {4783748, 333}; // TODO: Get IDs from files class
    std::vector<std::string> itemBank = {"Apple", "Chrocolate"}; // TODO: Get items from files class (or object from stocks?)
    std::vector<int> itemCostBank = {3, 3};
    int height{};
    int weight{};
    int age{};
    int ID{};
    struct currentItemsInBasket {
        double costOfItems;
        std::vector<std::string> items; // TODO: Use item objects
    };
    bool isInStore = true;
};

#endif //YEAR1_CPP_PROJECT_SHOPPER_H
