

#ifndef MANAGER_CPP
#define MANAGER_CPP
#include "manager.h"

// Your code here
template <class T>
TaskManager<T>::TaskManager(std::string fileName)
{
    std::ifstream TXT(fileName.c_str());
    std::string line;

    todo = new Todo<T>();

    while (std::getline(TXT, line))
    {
        std::string str, description, rStr, datas;

        str = line.substr(0, line.find_first_of('#'));
        line = line.substr(line.find_first_of('#') + 1);

        description = line.substr(0, line.find_first_of('#'));
        line = line.substr(line.find_first_of('#') + 1);

        rStr = line.substr(0, line.find_first_of('#'));
        line = line.substr(line.find_first_of('#') + 1);

        datas = line;

        int priority;
        std::stringstream ss_priority(str);
        ss_priority >> priority;

        bool repeat = (rStr == "True");

        int data;
        std::stringstream ss_data(datas);
        ss_data >> data;

        Task<T> *newT = new Task<T>(priority, description, repeat, data);
        newTask(newT);
    }

    TXT.close();

    weekly = NULL;
    priority = NULL;
    history = NULL;
}
template <class T>
TaskManager<T>::~TaskManager()
{
    if (todo)
    {
        delete todo;
    }
    if (weekly)
    {
        delete weekly;
    }
    if (priority)
    {
        delete priority;
    }
    if (history)
    {

        delete history;
    }
};
template <class T>
Todo<T> *TaskManager<T>::getTodo()
{
    return todo;
};
template <class T>
WeeklyTasks<T> *TaskManager<T>::getWeekly()
{
    return weekly;
};
template <class T>
PriorityList<T> *TaskManager<T>::getPriority()
{
    return priority;
};
template <class T>
History<T> *TaskManager<T>::getHistory()
{

    return history;
};
template <class T>
bool TaskManager<T>::newTask(const Task<T> *newTask)
{

    if (!newTask)
    {
        return false;
    }
    else
    {
        todo->addTask(newTask);
        delete newTask;

        return true;
    }
};
template <class T>
void TaskManager<T>::setWeeklyTasks()
{

    weekly = new WeeklyTasks<T>();
    Task<T> *curr = todo->getHead();

    while (curr)
    {
        Task<T> *volg = curr->getNext();
        if (curr->getRepeat())
        {
            weekly->addTask(curr);
            todo->removeTask(curr);
        }
        curr = volg;
    }
};
template <class T>
void TaskManager<T>::setPriority()
{
    if (!priority)
    {
        priority = new PriorityList<T>();
    }

    Task<T> *curr = todo->getHead();
    int hvl = 0;
    while (curr)
    {
        if (!curr->getRepeat())
        {
            hvl++;
        }
        curr = curr->getNext();
    }
    int val = 0;

    while (val < hvl)
    {
        val++;
        curr = todo->getHead();
        Task<T> *smallll = NULL; 


        while (curr)
        {

            if (!smallll && !curr->getRepeat())
                smallll = curr;

            if (smallll && curr->getPriority() < smallll->getPriority() && !curr->getRepeat())
                smallll = curr;

            curr = curr->getNext();
        }

        priority->addTask(smallll);
        todo->removeTask(smallll);
    }

    // Todo<T> *sortedList = new Todo<T>();

    // while (todo->getHead() != NULL)
    // {
    //     Task<T> *curr = todo->getHead();
    //     Task<T> *smallestTask = curr;

    //     while (curr != NULL)
    //     {
    //         if (!curr->getRepeat() && curr->getPriority() < smallestTask->getPriority())
    //         {
    //             smallestTask = curr;
    //         }
    //         curr = curr->getNext();
    //     }

    //     if (!smallestTask->getRepeat())
    //     {
    //         sortedList->addTask(smallestTask);
    //         todo->removeTask(smallestTask);
    //     }
    // }

    // Task<T> *sortedCurr = sortedList->getHead();
    // while (sortedCurr != NULL)
    // {
    //     Task<T> *next = sortedCurr->getNext();
    //     priority->addTask(sortedCurr);
    //     sortedCurr = next;
    // }

    // delete sortedList;
};
template <class T>
std::string TaskManager<T>::doWeekly(int cycles)
{

    return weekly->doTasks(cycles);
};
template <class T>
std::string TaskManager<T>::doPriority(int numTasks)
{
    std::string str;

    if (!priority)
    {
        str = "Priority Queue Empty";

        return str;
    }
    else
    {
        if (history == NULL)
        {
            history = new History<T>();
        };
        int val;
        Task<T> *curr = priority->getTail();
        if (numTasks < priority->getNumTasks())
        {
            val = numTasks;
        }
        else
        {
            val = priority->getNumTasks();
        }
        for (int i = 0; i < val; i++)
        {

            history->addTask(curr);

            curr = curr->getPrev();
        }

        str = priority->doNTasks(numTasks);

        return str;
    }
};

template <class T>
std::string TaskManager<T>::undoTasks(bool all)
{
    std::string str;
    if (!priority)
    {
        priority = new PriorityList<T>();
    }

    if (!history)
    {
        str = "Nothing to Undo";
    }
    else
    {
        if (all)
        {
            while (history->getNumTasks() != 0)
            {
                priority->addTask(history->getHead());
                str += history->undoLatest();
            }
        }
        else
        {
            priority->addTask(history->getHead());
            str += history->undoLatest();
        }
    }
    return str;
};

#endif