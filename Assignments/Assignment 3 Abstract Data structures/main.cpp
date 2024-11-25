#include <iostream>
#include "manager.h"


void taskman()
{

    TaskManager<int> *manager = new TaskManager<int>("tasks1.txt");

    manager->setWeeklyTasks();
    std::cout << "\nWeekly Tasks Set:" << std::endl;
    WeeklyTasks<int> *weeklyTasks = manager->getWeekly();
    // weeklyTasks->displayTasks();

    std::cout << "\nExecuting Weekly Tasks (2 cycles):" << std::endl;
    std::cout << manager->doWeekly(4) << std::endl;

    manager->setPriority();
    std::cout << "\nPriority List Set (ordered by priority):" << std::endl;
    PriorityList<int> *priorityList = manager->getPriority();

    Task<int> *t5 = new Task<int>(9, "e", true, 75);
    manager->getPriority()->addTask(t5);

    std::cout
        << "\nExecuting Top 3 Priority Tasks:" << std::endl;
    std::cout << manager->doPriority(3) << std::endl;

    std::cout << "\nUndoing the last completed task:" << std::endl;
    std::cout << manager->undoTasks(false) << std::endl;
    std::cout << manager->doPriority(0) << std::endl;

    std::cout << "\nUndoing all completed tasks:" << std::endl;
    std::cout << manager->undoTasks(true) << std::endl;
    std::cout << manager->doPriority(3) << std::endl;

    // Clean up
    delete manager;
    delete t5;
}
void priorityListTests()
{

    PriorityList<int> pList;
    Task<int> *task1 = new Task<int>(3, "Go shopping", true, 45);
    Task<int> *task2 = new Task<int>(1, "Attend meeting", false, 15);
    Task<int> *task4 = new Task<int>(5, "Workout", true, 10);

    pList.addTask(task1);
    pList.addTask(task2);
    pList.addTask(task4);

    std::cout << pList.getNumTasks()
              << std::endl;

    pList.removeTask();
    pList.removeTask();
    pList.removeTask();
    pList.removeTask();

    std::cout << "Test Remove Task (Remove Tail):\n";
    std::cout << "Expected Remaining Tasks:\nAttend meeting\nGo shopping\n";
    std::cout << "Actual:\n"
              << pList.doTasks() << "\n";

    delete task1;
    delete task2;
    delete task4;

    PriorityList<int> doList;
    task1 = new Task<int>(2, "Clean the house", true, 35);
    task2 = new Task<int>(1, "Read a book", false, 25);

    doList.addTask(task1);
    doList.addTask(task2);

    std::cout << "Test Do Tasks:\n";
    std::cout << "Expected:\nRead a book\nClean the house\n";
    std::cout << "Actual:\n"
              << doList.doTasks() << "\n";
    Task<int> *task10 = new Task<int>(2, "Clean the house", true, 35);
    Task<int> *task15 = new Task<int>(1, "Read a book", false, 25);
    doList.addTask(task10);
    doList.addTask(task15);

    std::cout << "Actual:\n"
              << doList.doNTasks(1) << "\n";

    PriorityList<int> emptyList;
    std::cout << "Test Do Tasks (Empty List):\n";
    std::cout << "Expected:\n";
    std::cout << "Actual:\n"
              << emptyList.doTasks() << "\n";

    delete task1;
    delete task2;

    delete task10;
    delete task15;
}
void testHistoryClass()
{

    History<int> history;

    if (history.getNumTasks() == 0)
        std::cout << "Initial state test passed.\n";
    else
        std::cout << "Initial state test failed.\n";

    Task<int> *task1 = new Task<int>(1, "Task 1", true, 100);
    Task<int> *task2 = new Task<int>(2, "Task 2", true, 200);
    Task<int> *task3 = new Task<int>(3, "Task 3", true, 300);

    if (history.addTask(task1) && history.getNumTasks() == 1)
        std::cout << "Add task 1 test passed.\n";
    else
        std::cout << "Add task 1 test failed.\n";

    if (history.addTask(task2) && history.getNumTasks() == 2)
        std::cout << "Add task 2 test passed.\n";
    else
        std::cout << "Add task 2 test failed.\n";

    if (history.addTask(task3) && history.getNumTasks() == 3)
        std::cout << "Add task 3 test passed.\n";
    else
        std::cout << "Add task 3 test failed.\n";

    Task<int> *removedTask = history.removeTask();
    if (removedTask && removedTask->getDescription() == "Task 3" && history.getNumTasks() == 2)
    {
        std::cout << "Remove task test passed for Task 3.\n";
    }
    else
    {
        std::cout << "Remove task test failed for Task 3.\n";
    }
    delete removedTask;

    std::string undoResult = history.undoLatest();
    if (undoResult.find("Task 2") != std::string::npos && history.getNumTasks() == 1)
    {
        std::cout << "Undo latest task test passed for Task 2.\n";
    }
    else
    {
        std::cout << "Undo latest task test failed for Task 2.\n";
    }

    history.addTask(task2);
    history.addTask(task3);
    std::string doTasksResult = history.doTasks();
    if (doTasksResult.find("Task 1") != std::string::npos &&
        doTasksResult.find("Task 2") != std::string::npos &&
        doTasksResult.find("Task 3") != std::string::npos &&
        history.getNumTasks() == 0)
    {
        std::cout << "Do tasks test passed.\n";
    }
    else
    {
        std::cout << "Do tasks test failed.\n";
    }

    delete task1;
    delete task2;
    delete task3;
}
void todo()
{

    Task<int> *t1 = new Task<int>(1, "a", false, 55);
    Task<int> *t2 = new Task<int>(2, "b", true, 60);
    Task<int> *t3 = new Task<int>(6, "c", false, 65);
    Task<int> *t4 = new Task<int>(4, "d", true, 70);
    Task<int> *t5 = new Task<int>(9, "e", true, 75);

    Todo<int> *todo1 = new Todo<int>();
    todo1->addTask(t1);
    todo1->addTask(t2);
    todo1->addTask(t3);
    todo1->addTask(t4);
    todo1->addTask(t5);

    std::cout << todo1->doTasks() << std::endl;
    std::cout << "Testing removing tasks: " << std::endl;
    todo1->removeTask(todo1->getHead()->getNext());
    todo1->removeTask(todo1->getTail());
    todo1->removeTask(todo1->getTail()->getPrev());

    std::cout << todo1->doTasks() << std::endl;

    delete todo1;
    delete t1;
    delete t2;
    delete t3;
    delete t4;
    delete t5;
    // Test Task
    Task<int> *task1 = new Task<int>(1, "Do the dishes", true, 42);
    Task<int> *task2 = new Task<int>(2, "Take out the trash", false, 13);
    Task<int> *task3 = new Task<int>(*task1);

    std::cout << "Task 1 Priority: " << task1->getPriority() << std::endl;
    std::cout << "Task 1 Description: " << task1->getDescription() << std::endl;
    std::cout << "Task 1 Repeat: " << task1->getRepeat() << std::endl;
    std::cout << "Task 1 Data: " << task1->getData() << std::endl;

    task1->setNext(task2);
    task2->setPrev(task1);

    std::cout << "Task 1 Next Description: " << task1->getNext()->getDescription() << std::endl;
    std::cout << "Task 2 Prev Description: " << task2->getPrev()->getDescription() << std::endl;

    if (*task1 == *task3)
        std::cout << "Task 1 is equal to Task 3" << std::endl;
    else
        std::cout << "Task 1 is not equal to Task 3" << std::endl;

    if (*task1 == *task2)
        std::cout << "Task 1 is equal to Task 2" << std::endl;
    else
        std::cout << "Task 1 is not equal to Task 2" << std::endl;

    delete task1;
    delete task2;
    delete task3;

    // Test Remove Task
    Todo<int> todoList;
    task1 = new Task<int>(1, "Do the dishes", true, 42);
    task2 = new Task<int>(2, "Take out the trash", false, 13);
    Task<int> *task4 = new Task<int>(3, "Task 3", true, 12);

    todoList.addTask(task1);
    todoList.addTask(task2);
    todoList.addTask(task4);

    todoList.removeTask(task1);
    std::cout << "Test Remove Task (Remove Head):\n";
    std::cout << "Expected: Take out the trash\nTask 3\n";
    std::cout << "Actual:\n"
              << todoList.doTasks() << "\n";

    todoList.removeTask(task2);
    std::cout << "Test Remove Task (Remove Tail):\n";
    std::cout << "Expected: Take out the trash\n";
    std::cout << "Actual:\n"
              << todoList.doTasks() << "\n";

    todoList.removeTask(task4);
    std::cout << "Test Remove Task (Remove Last Task):\n";
    std::cout << "Expected:\n";
    std::cout << "Actual:\n"
              << todoList.doTasks() << "\n";

    Todo<int> findTodoList;
    task1 = new Task<int>(1, "Do the dishes", true, 42);
    task2 = new Task<int>(2, "Take out the trash", false, 13);
    task4 = new Task<int>(3, "Task 3", true, 12);

    findTodoList.addTask(task1);
    findTodoList.addTask(task2);
    findTodoList.addTask(task4);

    std::cout << "Test Find Task By Priority:\n";
    Task<int> *found = findTodoList.findTask(2);
    std::cout << "Expected: Take out the trash\n";
    std::cout << "Actual: " << (found ? found->getDescription() : "Not Found") << "\n";

    found = findTodoList.findTask(4);
    std::cout << "Expected: Not Found\n";
    std::cout << "Actual: " << (found ? found->getDescription() : "Not Found") << "\n";

    delete task1;
    delete task2;
    delete task4;

    Todo<int> descTodoList;
    task1 = new Task<int>(1, "Do the dishes", true, 42);
    task2 = new Task<int>(2, "Take out the trash", false, 13);
    task4 = new Task<int>(3, "Task 3", true, 12);

    descTodoList.addTask(task1);
    descTodoList.addTask(task2);
    descTodoList.addTask(task4);

    std::cout << "Test Find Task By Description:\n";
    found = descTodoList.findTask("Take out the trash");
    std::cout << "Expected: Take out the trash\n";
    std::cout << "Actual: " << (found ? found->getDescription() : "Not Found") << "\n";

    found = descTodoList.findTask("Task 4");
    std::cout << "Expected: Not Found\n";
    std::cout << "Actual: " << (found ? found->getDescription() : "Not Found") << "\n";

    delete task1;
    delete task2;
    delete task4;

    Todo<int> doTodoList;
    task1 = new Task<int>(1, "Do the dishes", true, 42);
    task2 = new Task<int>(2, "Take out the trash", false, 13);

    doTodoList.addTask(task1);
    doTodoList.addTask(task2);

    std::cout << "Test Do Tasks:\n";
    std::cout << "Expected: Do the dishes\nTake out the trash\n";
    std::cout << "Actual:\n"
              << doTodoList.doTasks() << "\n";

    Todo<int> emptyList;
    std::cout << "Test Do Tasks (Empty List):\n";
    std::cout << "Expected:\n";
    std::cout << "Actual:\n"
              << emptyList.doTasks() << "\n";

    delete task1;
    delete task2;
}
void Circular()
{

    WeeklyTasks<int> weeklyTasks;

    // Test addTask function
    Task<int> *task1 = new Task<int>(1, "A2", true, 101);
    Task<int> *task2 = new Task<int>(2, "A3", false, 102);
    Task<int> *task3 = new Task<int>(3, "A5", true, 103);
    Task<int> *task4 = new Task<int>(4, "A4", false, 104);
    Task<int> *task5 = new Task<int>(5, "A1", false, 105);
    std::cout << "Adding tasks...\n";
    weeklyTasks.addTask(task1);

    weeklyTasks.addTask(task2);

    weeklyTasks.addTask(task3);
    weeklyTasks.addTask(task4);
    weeklyTasks.addTask(task5);
    std::cout << "before :\n"
              << weeklyTasks.doTasks();

    std::cout << weeklyTasks.removeTask(weeklyTasks.getTail()->getNext());
    std::cout << "Tasks after removing :\n"
              << weeklyTasks.doTasks();
    std::cout << weeklyTasks.removeTask(weeklyTasks.getTail()->getNext()->getNext());
    std::cout << "Tasks after removing :\n"
              << weeklyTasks.doTasks();
    std::cout << weeklyTasks.removeTask(weeklyTasks.getTail()->getNext()->getNext());
    std::cout << "Tasks after removing :\n"
              << weeklyTasks.doTasks();

    // Test doTasks with repetition
    std::cout << "\nDoing tasks with 2 repetitions:\n"
              << weeklyTasks.doTasks(2);

    delete task1;
    delete task2;
    delete task3;
    delete task4;
    delete task5;
}

int main()
{
    // {
    todo();
    Circular();
    priorityListTests();
    testHistoryClass();
    taskman();

    // stackremove();

    return 0;
}