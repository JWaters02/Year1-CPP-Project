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
#include <Windows.h>
#include <string>
#include "Item.h"
#include "Logs.h"

class Shopper {
public:
    Shopper(int _shopperID, bool _isRandomObject, std::string _name = "", int _height = 100, int _weight = 50, int _age = 35);

    // Functions
    Item giveShopperItem(const std::string& itemName, double itemCost, int numItems);
    void simulateShopper();

    // Getters
    std::string getName() const;
    int getHeight() const;
    int getWeight() const;
    int getAge() const;
    int getID() const;
    void getShopperInfo();
private:
    // Functions
    Item generateShopperItem(int numItems, std::string itemName, double itemCost);
    void pickupItem();
    void dropItem();
    void checkout();

    // Setters
    void setName();
    void setHeight();
    void setWeight();
    void setAge();

    // Consts
    static const int MAXHEIGHT = 240;
    static const int MINHEIGHT = 90;
    static const int MAXWEIGHT = 100;
    static const int MINWEIGHT = 15;
    static const int MAXAGE = 90;

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
    std::vector<std::string> itemBank = {"Apple", "Banana", "Cherry",
                                         "Date", "Elderberry", "Fig",
                                         "Grape", "Huckleberry", "Kiwi",
                                         "Lemon", "Mango", "Nectarine",
                                         "Orange", "Pear", "Quince",
                                         "Raisin", "Satsuma", "Tomato",
                                         "Ugli", "Victoria Plum",
                                         "Watermelon", "Zucchini"};
    std::vector<double> itemCostBank = {1.2, 0.8, 0.2,
                                        0.3, 0.6, 1,
                                        0.1, 1, 1.2,
                                        0.5, 1.6, 1,
                                        1, 1.1, 2,
                                        0.1, 1, 0.7,
                                        2, 1.5,
                                        2.3, 5};
    std::vector<Item> basket;
    int height;
    int weight;
    int age;
    bool isInStore = true;
};

#endif //YEAR1_CPP_PROJECT_SHOPPER_H
