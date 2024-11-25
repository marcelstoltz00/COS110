#ifndef DOUBLYLIST_CPP
#define DOUBLYLIST_CPP

#include "DoublyList.h"

template <class T>
DoublyList<T>::DoublyList()
{

    tail = NULL;
    head = NULL;
};
template <class T>
DoublyList<T>::DoublyList(const DoublyList<T> &other)
{
    if (other.head == NULL)
    {
        head = NULL;
        tail = NULL;
        return;
    }

    head = new DoublyNode<T>(other.head->getData());
    DoublyNode<T> *looker = other.head->next;
    DoublyNode<T> *impl = head;
    impl->prev = NULL;

    while (looker != NULL)
    {
        DoublyNode<T> *newnode = new DoublyNode<T>(looker->getData());
        impl->next = newnode;
        newnode->prev = impl;
        impl = impl->next;
        looker = looker->next;
    }
    tail = impl;
    tail->next = NULL;
};
template <class T>
DoublyList<T>::~DoublyList()
{

    while (tail != NULL)
    {
        DoublyNode<T> *tailss = tail->prev;

        delete tail;
        tail = tailss;
    }

    head = NULL;
    tail = NULL;
};
template <class T>
std::string DoublyList<T>::toString()
{
    std::string str = "";

    DoublyNode<T> *current = head;

    while (current != NULL)
    {
        str = str + current->toString();
        if (current->next != NULL)
        {

            str = str + "->";
        }
        current = current->next;
    }

    return str;
};
template <class T>
void DoublyList<T>::insert(T data, int position) {
    if (position == 0) {
        return;
    }

    int Count = 0;
    DoublyNode<T>* current = head;

    while (current != NULL) {
        Count++;
        current = current->next;
    }

    int pos;
    if (position < 0) {
        pos = Count + position +2;
        if (pos < 0) {
            pos = 1; 
        }
    } else {
        pos = position;
    }

    DoublyNode<T>* newest = new DoublyNode<T>(data);

    if (pos > Count) {
        if (tail != NULL) {
            tail->next = newest;
            newest->prev = tail;
            tail = newest;
        } else {
            head = tail = newest;
        }
    } else if (pos > 0) {
        current = head;
        int index = 1;

        while (current != NULL && index < pos) {
            current = current->next;
            index++;
        }

        if (current != NULL) {
            newest->next = current;
            newest->prev = current->prev;
            if (current->prev != NULL) {
                current->prev->next = newest;
            } else {
                head = newest;
            }
            current->prev = newest;
        }
    } else { 
        if (head != NULL) {
            head->prev = newest;
            newest->next = head;
            head = newest;
        } else {
            head = tail = newest;
        }
    }
}

template <class T>
int DoublyList<T>::contains(T data)
{

    int num = 0;

    DoublyNode<T> *current = head;

    while (current != NULL)
    {
        if (current->getData() == data)
            num++;
        current = current->next;
    }

    return num;
};
template <class T>
int DoublyList<T>::remove(T data)
{
    int num = 0;

    DoublyNode<T> *current = head;

    while (current != NULL)
    {

        if (current->getData() == data)
        {
            DoublyNode<T> *old = current;

            if (current->prev != NULL)
                current->prev->next = current->next;
            else
                head = current->next;

            if (current->next != NULL)
                current->next->prev = current->prev;
            else
                tail = current->prev;

            current = current->next;
            delete old;
            num++;
        }
        else
        {
            current = current->next;
        }
    }

    return num;
};

#endif // DOUBLYLIST_CPP
