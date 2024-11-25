#ifndef LIST_CPP
#define LIST_CPP
#include "list.h"

// Your code here
template <class T>
List<T>::List()
{

    head = NULL;
};
template <class T>
List<T>::~List(){

    // leave blank
};
template <class T>
Task<T> *List<T>::getHead()
{

    return this->head;
};

#endif