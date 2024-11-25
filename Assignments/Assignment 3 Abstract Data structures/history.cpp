

#ifndef HISTORY_CPP
#define HISTORY_CPP
#include "history.h"

// Your code here
template <class T>
History<T>::History() : List<T>()
{   
    this->head = NULL;

    numTasks = 0;
};
template <class T>
History<T>::~History()
{

    if (!this->head || numTasks == 0)
        return;

    while (this->head != NULL)
    {
        Task<T> *old = this->head;
        this->head = old->getNext();
        delete old;
    }
    numTasks = 0;
};
template <class T>
int History<T>::getNumTasks()
{
    return numTasks;
};
template <class T>
bool History<T>::addTask(const Task<T> *newTask)
{

    if (newTask)
    {
        Task<T> *copy = new Task<T>(*newTask);

        if (this->head)
        {
            copy->setNext(this->head);
            this->head = copy;
        }
        else
        {
            this->head = copy;
            copy->setNext(NULL);
        }

        numTasks++;

        return true;
    }
    else
    {

        return false;
    }
};
template <class T>
Task<T> *History<T>::removeTask()
{

    if (!this->head || numTasks == 0)
    {
        return NULL;
    }

    Task<T> *copy = this->head;
    Task<T> *copysend = new Task<T>(*this->head);

    if (copy->getNext())
    {
        this->head = copy->getNext();
    }
    else
    {
        this->head = NULL;
    }

    numTasks--;
    delete copy;

    return copysend;
};
template <class T>
std::string History<T>::undoLatest()
{

    std::stringstream str;

    if (!this->head || numTasks == 0)
        return str.str();
    Task<T> *copy = removeTask();
    str << "Task: " << copy->getDescription() << " Priority: " << copy->getPriority() << " Data: " << copy->getData() << " UNDID" << "\n";
    delete copy;
    return str.str();
};
template <class T>
std::string History<T>::doTasks()
{

    std::stringstream str;
    while (numTasks > 0 && this->head)
    {
        Task<T> *copy = removeTask();
        str << "Task: " << copy->getDescription() << " Priority: " << copy->getPriority()
            << " Data: " << copy->getData() << " UNDID\n";
        delete copy;
    }
    return str.str();
};

#endif