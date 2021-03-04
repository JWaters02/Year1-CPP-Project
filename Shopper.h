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

    bool setIsInStore(bool _isInStore);
    bool getIsInStore() const;

    // Getters
    std::string getName();
    int getHeight();
    int getWeight();
    int getAge();
    int getID();

    // Purchase history is taken from a pre-existing shopper when created
    struct purchaseHistory {
        double totalSpent;
        std::vector<std::string> itemsPurchased; // TODO: Use item objects from stock class
    } history;
private:
    // Setters
    std::string setName();
    int setHeight();
    int setWeight();
    int setAge();
    int setID();

    // Consts
    const int MAXHEIGHT = 240;
    const int MINHEIGHT = 90;
    const int MAXWEIGHT = 200;
    const int MINWEIGHT = 15;
    const int MAXAGE = 120;
    const int MAXID = 10000;

    std::string name;
    std::vector<std::string> nameBank; // TODO: Get names from files class
    std::vector<int> IDs; // TODO: Get IDs from files class
    int height;
    int weight;
    int age;
    int ID;
    struct currentItemsInBasket {
        double costOfItems;
        std::vector<std::string> items; // TODO: Use item objects from stock class
    };
    bool isInStore;
};


#endif //YEAR1_CPP_PROJECT_SHOPPER_H
