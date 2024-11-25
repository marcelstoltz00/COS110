#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <sstream>
#include <iostream>
class item
{
private:
    std::string name;
    double price;
    int stock;

public:
    item(std::string, double, int);
    ~item();
    std::string getName();
    double getPrice();
    int getStock();
};

#endif //ITEM_H