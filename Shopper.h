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

class Shopper {
public:
    Shopper(double _totalSpent, std::vector<std::string> _itemsPurchased);

    // Functions
    void giveShopperItem(std::string itemName, double itemCost);

    // Setters
    bool setIsInStore(bool _isInStore);

    // Getters
    std::string getName();
    int getHeight();
    int getWeight();
    int getAge();
    int getID();
    bool getIsInStore() const;
    std::string getItemNames();
    double getItemCosts();

    // Purchase history is taken from a pre-existing shopper when created
    struct purchaseHistory {
        double totalSpent;
        std::vector<std::string> itemsPurchased; // TODO: Use item objects
    } history;
private:
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
    static const int MAXID = 10000;

    // Vars
    std::string name;
    std::vector<std::string> nameBank = {"Joshua", "Joe"}; // TODO: Get names from files class
    std::vector<int> IDs = {4783748, 333}; // TODO: Get IDs from files class
    std::vector<std::string> itemBank = {"Apple", "Chrocolate"}; // TODO: Get items from files class (or object from stocks?)
    int height;
    int weight;
    int age;
    int ID;
    struct currentItemsInBasket {
        double costOfItems;
        std::vector<std::string> items; // TODO: Use item objects
    };
    bool isInStore = false;
};

#endif //YEAR1_CPP_PROJECT_SHOPPER_H
