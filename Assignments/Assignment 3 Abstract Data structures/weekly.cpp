#ifndef WEEKLY_CPP
#define WEEKLY_CPP
#include "weekly.h"
// circular linked list
//  Your code here
template <class T>
WeeklyTasks<T>::WeeklyTasks() : List<T>()
{
    numTasks = 0;

    tail = NULL;
};
template <class T>
WeeklyTasks<T>::~WeeklyTasks()
{
    if (!tail)
        return;
    Task<T> *current = tail->getNext();

    while (current != tail)
    {
        Task<T> *old = current;

        current = current->getNext();
        delete old;
    }
    delete tail;
    tail = NULL;
};
template <class T>
Task<T> *WeeklyTasks<T>::getTail()
{

    return tail;
};
template <class T>
int WeeklyTasks<T>::getNumTasks()
{
    return numTasks;
};
template <class T>
bool WeeklyTasks<T>::addTask(const Task<T> *toAdd)
{

    if (toAdd != NULL)
    {
        //    std::cout << "here"<<std::endl;
        Task<T> *copy = new Task<T>(*toAdd);
        if (!tail)
        {

            tail = copy;
            tail->setNext(copy);
            numTasks++;
            return true;
        }

        Task<T> *current = tail->getNext();
        Task<T> *prev = NULL;

        while (current != tail && current->getDescription()[0] < copy->getDescription()[0])
        {
            //  std::cout << current->getDescription()[0] << "<" << copy->getDescription()[0] << std::endl;
            prev = current;
            current = current->getNext();
        }

        if (current == tail->getNext()) // in the beginning
        {

            tail->setNext(copy);
            copy->setNext(current);
        }
        else if (current == tail) // add to the end
        {
            if (current->getDescription()[0] < copy->getDescription()[0])
            { // at the end
              //  std::cout << current->getDescription()[0] << "<" << copy->getDescription()[0] << std::endl;

                copy->setNext(tail->getNext());
                current->setNext(copy);
                tail = copy;
            }
            else
            { // before the end

                copy->setNext(current);
                prev->setNext(copy);
            }
        }
        else
        { // fine

            copy->setNext(current);
            prev->setNext(copy);
        }

        // order alphabetically

        numTasks++;
        //  std::cout << "here 2" << std::endl;

        Task<T> *beginning = tail->getNext();
        tail->setNext(NULL);

        bool see;
        do
        {
            see = false;
            Task<T> *current = beginning;
            Task<T> *prev = NULL;

            while (current && current->getNext())
            {
                Task<T> *next = current->getNext();
                if (current->getDescription() > next->getDescription())
                {

                    if (prev)
                        prev->setNext(next);
                    else
                        beginning = next;

                    current->setNext(next->getNext());
                    next->setNext(current);

                    see = true;
                    prev = next;
                }
                else
                {
                    prev = current;
                    current = next;
                }
            }
        } while (see);

        tail = beginning;
        while (tail->getNext())
        {
            tail = tail->getNext();
        }
        tail->setNext(beginning);

        return true;
    }
    else
    {
        return false;
    }
};

template <class T>
bool WeeklyTasks<T>::removeTask(Task<T> *toRemove)
{
    if (!tail || !toRemove)
    {
        return false;
    }

    Task<T> *current = tail->getNext();
    Task<T> *prev = NULL;

    while (!(*current == *toRemove) && !(*current == *tail))
    {
        prev = current;
        current = current->getNext();
    }

    if (!(*current == *toRemove))
    {
        return false;
    }

    if (*current == *tail->getNext())
    {
        if (!(*current == *tail))
        {
            tail->setNext(current->getNext());
        }
        else
        {
            tail = NULL;
        }
    }
    else if (*current == *tail)
    {
        if (tail->getNext() != tail)
        {
            prev->setNext(current->getNext());
            tail = prev;
        }
        else
        {
            tail = NULL;
        }
    }
    else
    {
        prev->setNext(current->getNext());
    }

    --numTasks;
    delete current;
    return true;
}
template <class T>
std::string WeeklyTasks<T>::doTasks()
{

    std::stringstream str;
    if (!tail || numTasks == 0)
    {
        return str.str();
    }
    // std::cout << "here";

    Task<T> *current = tail->getNext();
    do
    {
        str << "Task: " << current->getDescription() << " Data: " << current->getData() << " COMPLETED\n";
        current = current->getNext();
    } while (current != tail->getNext());

    return str.str();
};
template <class T>
std::string WeeklyTasks<T>::doTasks(int repitions)
{

    std::string str = "";

    if (!tail || numTasks == 0)
    {
        return str;
    }
    for (int i = 0; i < repitions; i++)
    {

        str += WeeklyTasks::doTasks();
    }
    return str;
};

#endif