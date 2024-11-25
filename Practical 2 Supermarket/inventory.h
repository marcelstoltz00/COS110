#ifndef INVENTORY_H
#define INVENTORY_H
#include "item.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

class inventory
{
private:
    int capacity;
    int count;
    int *shelfSizes;
    int numShelves;
    item **items;
    item ***shelves;

public:
    inventory(int c, std::string path);
    ~inventory();
    item **getItems();
    item ***getShelves();
    int getCount();
    int getNumShelves();
    int *getShelfSizes();
    bool addItem(item *newitem);
    bool removeItem(int);
    void stockShelves();
    std::string generateReport();
};

#endif //INVENTORY_H