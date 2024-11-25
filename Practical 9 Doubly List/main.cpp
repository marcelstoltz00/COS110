#include <iostream>
#include "DoublyList.h"

int main()
{
   
  

    DoublyList<int> list;
    DoublyNode<int> newnode(10);
    std::cout << "New node data: " << newnode.getData() << std::endl;
    std::cout << "New node as string: " << newnode.toString() << std::endl;

    list.insert(10, 1);
    list.insert(20, 2);
    list.insert(30, 3);
    std::cout << "first " << list.toString() << std::endl;

    list.insert(40, 100);
    std::cout << "second " << list.toString() << std::endl;

    list.insert(15, -2);
    std::cout << "third " << list.toString() << std::endl;

    list.insert(5, -1);
    std::cout << list.toString() << std::endl;

    list.insert(50, 0);
    std::cout << list.toString() << std::endl;

    int count20 = list.contains(20);
    std::cout << "Count of 20: " << count20 << std::endl;

    int count50 = list.contains(50);
    std::cout << "Count of 50: " << count50 << std::endl;

    int removed = list.remove(20);
    std::cout << "Removed 20: " << removed << std::endl;

    removed = list.remove(100);
    std::cout << "Attempted to remove 100 (not in list): " << removed << std::endl;

    DoublyList<int> copiedList = list;
    std::cout << "Copied list: " << copiedList.toString() << std::endl;

    DoublyList<int> lists;
    lists.insert(10, 1);
    lists.insert(20, 2);
    lists.insert(30, 100);
    lists.insert(40, -1);
    lists.insert(15, -3);
    lists.insert(5, 0);
    lists.insert(50, 1);
    lists.insert(10, 0);
    lists.insert(20, 1);
    lists.insert(30, 2);
    lists.insert(40, 100);
    lists.insert(50, 200);
    lists.insert(60, -1);
    lists.insert(70, -3);
    lists.insert(80, -100);

    std::cout << "Final list: " << lists.toString();

    return 0;
}
