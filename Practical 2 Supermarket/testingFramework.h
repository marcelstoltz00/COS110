#ifndef TESTING_FRAMEWORK_H
#define TESTING_FRAMEWORK_H

#include <iostream>
#include <string>

const std::string ANSI_RED = "\033[31;1m";
const std::string ANSI_GREEN = "\033[32;1m";
const std::string ANSI_BLUE = "\033[34;1m";
const std::string ANSI_RESET = "\033[0m";

class MyTestFrameworkforinventory {
public:
    void runTests();

private:
    int testsRun = 0;
    int testsPassed = 0;

    void startSuite(const std::string& suiteName);
    void endSuite();

    void assertEqual(const int& expected, const int& actual);
    void assertEqual(const std::string& expected, const std::string& actual);
    void assertArrayEqual(int* expected, int* actual, int size);
    void assertNotNull(int* ptr);
    void assertNotNull(int** ptr);

    void testAddItem();
    void testRemoveItem();
    void testRemoveItemOutOfBounds();
    void testStockShelves();
    void testShelfContent();
    void testGenerateReport();
};

#endif // TESTING_FRAMEWORK_H
