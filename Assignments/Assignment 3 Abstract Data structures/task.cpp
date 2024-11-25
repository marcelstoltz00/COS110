#ifndef TASK_CPP
#define TASK_CPP
#include "task.h"

// Your code here
template <class T>
Task<T>::Task(int priority, std::string description, bool repeat, T data)
{
    this->priority = priority;
    this->description = description;
    this->repeat = repeat;
    this->data = data;
    next = NULL;
    prev = NULL;
};
template <class T>
Task<T>::Task(const Task<T> &toCopy){

    {this->priority = toCopy.priority;
this->description = toCopy.description;
this->repeat = toCopy.repeat;
this->data = toCopy.data;

next = NULL;
prev = NULL;
}
}
;
template <class T>
Task<T>::~Task(){

    // leave blank
};
template <class T>
int Task<T>::getPriority()
{

    return priority;
};
template <class T>
std::string Task<T>::getDescription()
{

    return description;
};
template <class T>
bool Task<T>::getRepeat()
{

    return repeat; // weekly task?
};
template <class T>
T Task<T>::getData()
{

    return data;
};
template <class T>
Task<T> *Task<T>::getNext()
{

    return next;
};
template <class T>
Task<T> *Task<T>::getPrev()
{
    return prev;
};
template <class T>
bool Task<T>::setNext(Task<T> *nextTask){

    // if (nextTask == NULL)
    // {

    //     return false;
    // }
    // else
    {
        this -> next = nextTask;
return true;
}
}
;
template <class T>
bool Task<T>::setPrev(Task<T> *prevTask){

    // if (prevTask == NULL)
    // {

    //     return false;
    //
    {
        this -> prev = prevTask;
return true;
}
}
;
template <class T>
bool Task<T>::operator==(const Task<T> &other)
{

    return (priority == other.priority && description == other.description && repeat == other.repeat && data == other.data);
};

#endif