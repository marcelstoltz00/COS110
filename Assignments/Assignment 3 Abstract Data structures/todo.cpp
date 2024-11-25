#ifndef TODO_CPP
#define TODO_CPP
#include "todo.h"

// Your code here

template <class T>
Todo<T>::Todo() : List<T>()
{

    tail = NULL;
};
template <class T>
Todo<T>::~Todo()
{

    // deall all tasks
    if (!this->getHead())
    {
        return;
    }
    Task<T> *kop = this->getHead();

    while (kop != NULL)
    {
        Task<T> *old = kop;

        kop = kop->getNext();

        delete old;
    }
};
template <class T>
Task<T> *Todo<T>::getTail()
{

    return tail;
};
template <class T>
bool Todo<T>::addTask(const Task<T> *toAdd)
{

    if (toAdd != NULL)
    {
        Task<T> *copy = new Task<T>(*toAdd);

        if (this->getHead() == NULL)
        {

            this->head = copy;
            tail = copy;
        }
        else
        {
            tail->setNext(copy);
            copy->setPrev(tail);

            tail = copy;
        }

        return true;
    }
    else
    {

        return false;
    }
};
template <class T>
bool Todo<T>::removeTask(Task<T> *toRemove)
{
    if (!this->head || !toRemove)
    {
        return false;
    }

    Task<T> *curr = this->head;

    while (curr)
    {

        if (!(*toRemove == *curr))
        {
        }
        else
        {
            if (!(curr->getNext()))
            {
                tail = curr->getPrev();
            }
            else
            {
                curr->getNext()->setPrev(curr->getPrev());
            }

            if (!curr->getPrev())
            {
                this->head = curr->getNext();
            }
            else
            {
                curr->getPrev()->setNext(curr->getNext());
            }
            delete curr;
            return true;
        }
        curr = curr->getNext();
    }
    return false;

    // if (*toRemove == *this->head)
    // {
    //     this->head = this->head->getNext();
    //     if (this->head)
    //     {
    //         this->head->setPrev(NULL);
    //     }
    //     else
    //     {
    //         tail = NULL;
    //     }
    //     delete toRemove;
    //     return true;
    // }

    // if (*toRemove == *tail)
    // {
    //     tail = tail->getPrev();
    //     if (tail)
    //     {
    //         tail->setNext(NULL);
    //     }
    //     delete toRemove;
    //     return true;
    // }

    // Task<T> *prev = toRemove->getPrev();
    // Task<T> *next = toRemove->getNext();

    // if (prev)
    // {
    //     prev->setNext(next);
    // }
    // if (next)
    // {
    //     next->setPrev(prev);
    // }
    // if (toRemove)
    //     delete toRemove;
    // return true;
};
template <class T>
Task<T> *Todo<T>::findTask(int priority)
{

    if (!this->getHead())
    {
        return NULL;
    }
    Task<T> *current = this->getHead();

    while (current)
    {

        if (current->getPriority() == priority)
        {

            return current;
        }

        current = current->getNext();
    }

    return NULL;
};
template <class T>
Task<T> *Todo<T>::findTask(std::string description)
{

    if (!this->getHead())
    {
        return NULL;
    }
    Task<T> *current = this->getHead();

    while (current)
    {

        if (current->getDescription() == description)
        {

            return current;
        }

        current = current->getNext();
    }

    return NULL;
};
template <class T>
std::string Todo<T>::doTasks()
{
    std::string str = "";
    if (!this->head)
    {
        return str;
    }

    Task<T> *current = this->head;
    while (current)
    {

        str = str + current->getDescription() + "\n";

        current = current->getNext();
    }

    return str;
};

#endif