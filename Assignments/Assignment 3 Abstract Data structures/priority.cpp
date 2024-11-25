


#ifndef PRIORITY_CPP
#define PRIORITY_CPP
#include "priority.h"
// Your code here
template <class T>
PriorityList<T>::PriorityList() : List<T>()
{
    tail = NULL;
    numTasks = 0;
};
template <class T>
PriorityList<T>::~PriorityList()
{

    if (!this->head || !tail || numTasks == 0)
        return;

    while (tail != NULL)
    {
        Task<T> *old = tail;
        tail = (tail->getPrev());
        delete old;
    }
    numTasks = 0;
};
template <class T>
Task<T> *PriorityList<T>::getTail()
{
    return tail;
};
template <class T>
int PriorityList<T>::getNumTasks()
{

    return numTasks;
};
template <class T>
bool PriorityList<T>::addTask(const Task<T> *toAdd)
{
    if (!toAdd)
    {
        return false;
    }
    // enqueue

    Task<T> *copy = new Task<T>(*toAdd);

    numTasks++;
    if (!this->getHead())
    {

        tail = this->head = copy;
    }
    else
    {
        copy->setNext(this->head);
        Task<T> *curr = this->getHead();
        curr->setPrev(copy);
        this->head = copy;
    }

    return true;
};
template <class T>
bool PriorityList<T>::removeTask()
{

    if (!tail)
    {
        return false;
    }
    Task<T> *curr = tail;
    tail = tail->getPrev();
    if (tail)
    {
        tail->setNext(NULL);
    }
    else
    {
        this->head = NULL;
    }
    delete curr;
    numTasks--;
    return true;
};

template <class T>
std::string PriorityList<T>::doNTasks(int numTasks)
{
    std::stringstream str;

  //  int num = (this->numTasks < numTasks) ? this->numTasks : numTasks;


    for (int i = 0; i < numTasks; i++)
    {
        if (!tail)
            break;

        str << "Task: " << tail->getDescription()
            << " Priority: " << tail->getPriority()
            << " Data: " << tail->getData() << " COMPLETED"<<"\n";

   

        removeTask();
    }

    return str.str();
};

template <class T>
std::string PriorityList<T>::doTasks()
{

    return doNTasks(numTasks);
};

#endif