#include "inventory.h"
#include <sstream>
#include <iostream>
/*
std::string intToString(int number)
{
    std::stringstream ss;
    ss << number;
    return ss.str();
}
std::string doubleToString(double value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
} */
inventory::inventory(int c, std::string path)
{
    this->capacity = c;
    this->count = 0;
    this->shelfSizes = NULL;
    this->shelves = NULL;
    this->numShelves = 0;

    if (c <= 0)
    {
        capacity = 0;

        return;
    }

    // shelfSizes = new int[capacity];

    items = new item *[capacity];
    // shelves = new item **[capacity];

    std::ifstream TXT(path.c_str());
    std::string str;

    std::string cost;
    std::string amount;
    std::stringstream ss;
    double Price;
    int Amount;

    std::string newname;
    // Toothpaste#257.65#46.00
    while (std::getline(TXT, str) && (count < capacity))
    {
        newname = str.substr(0, str.find_first_of('#'));
        str = str.substr(str.find_first_of('#') + 1);

        cost = str.substr(0, str.find_first_of('#'));
        std::stringstream ss(cost);
        ss >> Price;
        ss.clear();
        str = str.substr(str.find_first_of('#') + 1);
        amount = str.substr(0, str.find_first_of('.'));
        std::stringstream ss_amount(amount);
        ss_amount >> Amount;

        items[count++] = new item(newname, Price, Amount);

        // std::cout<<items[count-1]->getName()<<items[count-1]->getPrice()<<items[count-1]->getStock()<<std::endl;
    }
};
inventory::~inventory()
{
    if (items)
    {
        for (int i = 0; i < count; ++i)
        {
            delete items[i];
        }
        delete[] items;
        items = NULL;
    }

    if (shelves)
    {
        for (int i = 0; i < numShelves; ++i)
        {
            for (int j = 0; j < shelfSizes[i]; ++j)
            {
                delete shelves[i][j];
            }
            delete[] shelves[i];
        }
        delete[] shelves;
        shelves = NULL;
    }

    if (shelfSizes)
    {
        delete[] shelfSizes;
        shelfSizes = NULL;
    }
};
item **inventory::getItems() { return items; };
item ***inventory::getShelves() { return shelves; };
int inventory::getCount() { return count; };
int inventory::getNumShelves() { return numShelves; };
int *inventory::getShelfSizes() { return shelfSizes; };
bool inventory::addItem(item *newitem)
{
    // std::cout << "Current count: " << count << ", Capacity: " << capacity << std::endl;
    if (newitem == NULL || count >= capacity)
    {
        //  std::cout << "Cannot add item. Full or invalid item." << std::endl;
        return false;
    }

    items[count] = new item(newitem->getName(), newitem->getPrice(), newitem->getStock());
    //  std::cout << "Added item at index " << count << std::endl;
    count++;

    return true;
};
bool inventory::removeItem(int indexToRemove)
{
    bool removed = false;
    if (indexToRemove < 0 || indexToRemove >= count || items[indexToRemove] == NULL)
    {

        return removed;
    };
    // now copy everything except that line
    delete items[indexToRemove];
    // shelfSizes[indexToRemove] = 0;

    // item ***newshelves = new item **[count - 1];//create var with one less memory than what we need,or do we?
    //  item **newitem = new item *[count - 1];
    // int *newshelfSizes = new int[count - 1];
    //  int iholditem = 0;
    for (int i = indexToRemove; i < count - 1; i++)
    {
        items[i] = items[i + 1];
        // shelfSizes[i] = shelfSizes[i + 1];
    }
    //  delete[] shelves;//delete original array
    //  count--; // decrease count of total items

    // shelves = newshelves;//assign new address
    // assign new address ;
    count--;
    items[count] = NULL;
    //  shelfSizes[count] = 0;

    return true;
};
void inventory::stockShelves()
{
    // we should pack the arrays...so lets go
    std::string array[1000];
    std::string name;
    int icheckindexofstrarray;
    int ichecknumberofshelves = 0;
    int ikeeptrackofnumcolumns = 0;
    bool bfound = false;
    for (int icountitems = 0; icountitems < count; icountitems++)
    {
        // we check if square triangle etc
        // 1 how many items on the shelf of the same name//then allocate memory for the items,copy items
        name = items[icountitems]->getName();
        bfound = false;

        for (int i = 0; i < ichecknumberofshelves; i++)
        {
            if (array[i] == name)
            {
                bfound = true;
                break;
                //  ikeeptrackofnumcolumns++;
            }
        }
        if (bfound == false)
        {
            array[ichecknumberofshelves++] = name;
        }
    }

    // now we have number of shelves
    numShelves = ichecknumberofshelves;
    shelves = new item **[ichecknumberofshelves];
    shelfSizes = new int[ichecknumberofshelves];
    for (int i = 0; i < ichecknumberofshelves; ++i)
    {
        shelfSizes[i] = 0;
    }
    for (int i = 0; i < ichecknumberofshelves; i++)
    {
        name = array[i];
        ikeeptrackofnumcolumns = 0;
        for (int j = 0; j < count; j++)
        {
            if (name == items[j]->getName())
            {
                ikeeptrackofnumcolumns++;
            }
        }
        shelves[i] = new item *[ikeeptrackofnumcolumns];
        shelfSizes[i] = ikeeptrackofnumcolumns;
    }

    // now we populate shelves with deep copies

    for (int i = 0; i < ichecknumberofshelves; i++)
    {
        name = array[i];
        int ichechkindex = 0;

        for (int j = 0; j < count; j++)
        {
            if (items[j]->getName() == name)
            {
                shelves[i][ichechkindex++] = new item(items[j]->getName(), items[j]->getPrice(), items[j]->getStock());
            }
        }
    }
};
std::string inventory::generateReport()
{

    int totalstock;
    double avgprice, min, max, totalprice;

    std::string name;
    std::ostringstream str;

    for (int i = 0; i < numShelves; i++)
    {

        min = shelves[i][0]->getPrice();
        max = shelves[i][0]->getPrice();

        totalstock = 0;
        totalprice = 0;
        avgprice = 0;

        name = shelves[i][0]->getName();

        for (int j = 0; j < shelfSizes[i]; j++)
        {

            totalstock += shelves[i][j]->getStock();
            totalprice += shelves[i][j]->getPrice();

            if (min > shelves[i][j]->getPrice())
            {
                min = shelves[i][j]->getPrice();
            }
            if (max < shelves[i][j]->getPrice())
            {
                max = shelves[i][j]->getPrice();
            }
        }
        if (shelfSizes[i] > 0)
            avgprice = totalprice / shelfSizes[i];

        str << "Shelf " << i << ": " << "Item: " << name
            << " Total Stock: " << totalstock
            << " Average Price: " << avgprice
            << " Min Price: " << min
            << " Max Price: " << max << "\n";
    }

    return str.str();
};