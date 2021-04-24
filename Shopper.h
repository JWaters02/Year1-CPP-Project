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
#include "Stock.h"

class Shopper {
public:
    Shopper(int _shopperID, std::vector<Item>& _stock, bool _isRandomObject,
            std::string _name = "", int _height = 100, int _weight = 50, int _age = 35, bool _isInStore = true);

    // Functions
    void giveShopperItem(const std::string itemName, double itemCost, int numItems);
    void simulateShopper(bool& doesCheckout);

    // Setters
    void setID(int newID);

    // Getters
    std::string getName() const;
    int getHeight() const;
    int getWeight() const;
    int getAge() const;
    int getID() const;
    std::string getIsInStore();
    std::vector<Item> getBasket();
    double getMoneyMade();
    void getShopperInfo();
private:
    // Functions
    Item generateShopperItem(const std::string itemName, const double itemCost, const int numItems);
    void pickupItem();
    void dropItem();
    void checkout();

    // Setters
    void setName();
    void setHeight();
    void setWeight();
    void setAge();
    void setItemBank();
    void setItemCostBank();

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
    std::vector<std::string> itemBank;
    std::vector<double> itemCostBank;
    std::vector<Item> basket;
    std::vector<Item> stock;
    int height;
    int weight;
    int age;
    bool isInStore = true;
};

#endif //YEAR1_CPP_PROJECT_SHOPPER_H
