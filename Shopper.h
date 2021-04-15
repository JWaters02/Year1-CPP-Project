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
    Shopper(int _shopperID, bool _isRandomObject, std::string _name = "", int _height = 100, int _weight = 50, int _age = 35);

    // Functions
    Item giveShopperItem(const std::string& itemName, double itemCost, int numItems);
    void toggleIsInStore();

    // Getters
    std::string getName() const;
    int getHeight() const;
    int getWeight() const;
    int getAge() const;
    int getID() const;
    bool getIsInStore() const;
    static std::string getItemsInBasketNames();
    static double getItemInBasketCosts();
    void getShopperInfo();
private:
    // Functions
    Item generateShopperItem();
    std::vector<Item> generateShopperItemList();

    // Setters
    void setName();
    void setHeight();
    void setWeight();
    void setAge();

    // Consts
    static const int MAXHEIGHT = 240;
    static const int MINHEIGHT = 90;
    static const int MAXWEIGHT = 200;
    static const int MINWEIGHT = 15;
    static const int MAXAGE = 90;
    static const int MAXITEMSPERITEM = 20;
    static const int MAXITEMSFORBASKET = 50;

    // Vars
    int shopperID;
    std::string name;
    std::vector<std::string> nameBank = {"Joshua", "Joe", "Ben",
                                         "Charlie", "Dodo", "Elizabeth",
                                         "Freddo", "Georgina", "Hardie",
                                         "Isabelle", "Kale", "Luna",
                                         "Monsa", "Meep", "Nick",
                                         "Oscar", "Papa", "Quebec",
                                         "Roger", "Susan", "Thomas",
                                         "Ugra", "Victor", "Wolfie",
                                         "Xray", "Yankee", "Zulu"};
    std::vector<std::string> itemBank = {"Apple", "Chrocolate"};
    std::vector<int> itemCostBank = {3, 3};
    int height{};
    int weight{};
    int age{};
    struct currentItemsInBasket {
        double costOfItems;
        std::vector<std::string> items; // TODO: Use item objects
    };
    bool isInStore = true;
};

#endif //YEAR1_CPP_PROJECT_SHOPPER_H
