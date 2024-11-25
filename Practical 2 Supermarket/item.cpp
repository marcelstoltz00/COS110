#include "item.h"
#include <string>

item::item(std::string Name, double Price, int Stock)
{
    this->name = Name;
    this->price = Price;
    this->stock = Stock;
};
item::~item() {

    // nothing to deconstruct
};
std::string item::getName()
{
    return name;
};
double item::getPrice()
{
    return price;
};
int item::getStock()
{
    return stock;
};
