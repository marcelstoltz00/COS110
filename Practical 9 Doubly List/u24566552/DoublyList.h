#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <string>
#include "DoublyNode.h"
template <class T>
class DoublyList
{
private:
    DoublyNode<T> *head;
    DoublyNode<T> *tail;

public:
    DoublyList();
    DoublyList(const DoublyList<T> &other);
    ~DoublyList();
    std::string toString();
    void insert(T data, int position);
    int contains(T data);
    int remove(T data);
};

#include "DoublyList.cpp"
#endif // DOUBLYLIST_H
