#include "testingFramework.h"
#include "inventory.h"

void MyTestFrameworkforinventory::runTests() {
    startSuite("Inventory Tests");

   testAddItem();
   testRemoveItem();
  testRemoveItemOutOfBounds();
   testStockShelves();
  testShelfContent();
    testGenerateReport();
    endSuite();
}

void MyTestFrameworkforinventory::startSuite(const std::string& suiteName) {
    std::cout << ANSI_BLUE << "Starting Test Suite: " << suiteName << ANSI_RESET << std::endl;
}

void MyTestFrameworkforinventory::endSuite() {
    std::cout << ANSI_BLUE << "Test Suite Finished: " << testsPassed << " / " << testsRun << " Tests Passed" << ANSI_RESET << std::endl;
}

void MyTestFrameworkforinventory::assertEqual(const int& expected, const int& actual) {
    testsRun++;
    if (expected == actual) {
        testsPassed++;
        std::cout << ANSI_GREEN << "Test " << testsRun << " Passed" << ANSI_RESET << std::endl;
    } else {
        std::cout << ANSI_RED << "Test " << testsRun << " Failed: Expected " << expected << " but got " << actual << ANSI_RESET << std::endl;
    }
}

void MyTestFrameworkforinventory::assertEqual(const std::string& expected, const std::string& actual) {
    testsRun++;
    if (expected == actual) {
        testsPassed++;
        std::cout << ANSI_GREEN << "Test " << testsRun << " Passed" << ANSI_RESET << std::endl;
    } else {
        std::cout << ANSI_RED << "Test " << testsRun << " Failed: Expected \n" << expected << " but got \n" << actual << ANSI_RESET << std::endl;
    }
}

void MyTestFrameworkforinventory::assertArrayEqual(int* expected, int* actual, int size) {
    testsRun++;
    bool equal = true;
    for (int i = 0; i < size; i++) {
        if (expected[i] != actual[i]) {
            equal = false;
            std::cout << ANSI_RED << "Test " << testsRun << " Failed at index " << i << ": Expected " << expected[i] << " but got " << actual[i] << ANSI_RESET << std::endl;
        }
    }
    if (equal) {
        testsPassed++;
        std::cout << ANSI_GREEN << "Test " << testsRun << " Passed" << ANSI_RESET << std::endl;
    }
}

void MyTestFrameworkforinventory::assertNotNull(int* ptr) {
    testsRun++;
    if (ptr != nullptr) {
        testsPassed++;
        std::cout << ANSI_GREEN << "Test " << testsRun << " Passed" << ANSI_RESET << std::endl;
    } else {
        std::cout << ANSI_RED << "Test " << testsRun << " Failed: Pointer is NULL" << ANSI_RESET << std::endl;
    }
}

void MyTestFrameworkforinventory::assertNotNull(int** ptr) {
    testsRun++;
    if (ptr != nullptr) {
        testsPassed++;
        std::cout << ANSI_GREEN << "Test " << testsRun << " Passed" << ANSI_RESET << std::endl;
    } else {
        std::cout << ANSI_RED << "Test " << testsRun << " Failed: Pointer is NULL" << ANSI_RESET << std::endl;
    }
}

void MyTestFrameworkforinventory::testAddItem() {
    inventory inv(25, "items copy.txt");
    item* newItem1 = new item("TestItem1", 100.0, 50);
    item* newItem2 = new item("TestItem2", 200.0, 30);

    bool result1 = inv.addItem(newItem1);
    bool result2 = inv.addItem(newItem2);

    assertEqual(true, result1);
   assertEqual(true, result2);
    assertEqual(12, inv.getCount());

    delete newItem1;
    delete newItem2;
}

void MyTestFrameworkforinventory::testRemoveItem() {
    inventory inv(12, "items copy.txt");
    item* newItem = new item("TestItem", 100.0, 50);
    inv.addItem(newItem);

    bool result = inv.removeItem(0);

    assertEqual(true, result);
    assertEqual(10, inv.getCount());//this one

    delete newItem;
}

void MyTestFrameworkforinventory::testRemoveItemOutOfBounds() {
    inventory inv(1, "items copy.txt");
    item* newItem = new item("TestItem", 100.0, 50);
    inv.addItem(newItem);

    bool result = inv.removeItem(1);

    assertEqual(false, result);

    delete newItem;
}

void MyTestFrameworkforinventory::testStockShelves() {
    inventory inv(5, "items copy.txt");
    inv.stockShelves();

    assertEqual(4, inv.getNumShelves());
    int expectedSizes[] = { 2, 1,1,1 };
    assertArrayEqual(expectedSizes, inv.getShelfSizes(), 2);

}

void MyTestFrameworkforinventory::testShelfContent() {
    inventory inv(20, "items copy.txt");
   inv.stockShelves();

    item*** shelves = inv.getShelves();

    assertEqual("Toothpaste", shelves[0][0]->getName());
   assertEqual("Chocolate", shelves[1][0]->getName());

   
}

void MyTestFrameworkforinventory::testGenerateReport() {
//     inventory inv(10, "items copy.txt");
//    inv.stockShelves();
//    std::string report = inv.generateReport();

//    std::string expectedReport = 
//     "Shelf 0: Toothpaste Total Stock: 93 Average Price: 622.011 Min Price: 257.65 Max Price: 978.62\n"
//     "Shelf 1: Chocolate Total Stock: 15 Average Price: 308.04 Min Price: 308.04 Max Price: 308.04\n"
//     "Shelf 2: Notebook Total Stock: 39 Average Price: 521.33 Min Price: 521.33 Max Price: 521.33\n"
//     "Shelf 3: Lotion Total Stock: 29 Average Price: 217.67 Min Price: 217.67 Max Price: 217.67\n";
    /*"Shelf 4: Pen Total Stock: 31 Average Price: 847.72 Min Price: 847.72 Max Price: 847.72\n"
    "Shelf 5: Milk Total Stock: 50 Average Price: 118.83 Min Price: 118.83 Max Price: 118.83\n"
    "Shelf 6: Cheese Total Stock: 38 Average Price: 857.55 Min Price: 857.55 Max Price: 857.55\n"
    "Shelf 7: Bread Total Stock: 60 Average Price: 150.00 Min Price: 150.00 Max Price: 150.00\n"
    "Shelf 8: Butter Total Stock: 25 Average Price: 200.50 Min Price: 200.50 Max Price: 200.50\n"
    "Shelf 9: Soap Total Stock: 40 Average Price: 300.25 Min Price: 300.25 Max Price: 300.25\n"
    "Shelf 10: Shampoo Total Stock: 10 Average Price: 450.75 Min Price: 450.75 Max Price: 450.75\n"
    "Shelf 11: Conditioner Total Stock: 15 Average Price: 250.35 Min Price: 250.35 Max Price: 250.35\n"
    "Shelf 12: Eggs Total Stock: 30 Average Price: 120.10 Min Price: 120.10 Max Price: 120.10\n"
    "Shelf 13: Juice Total Stock: 20 Average Price: 220.45 Min Price: 220.45 Max Price: 220.45\n"
    "Shelf 14: Tea Total Stock: 45 Average Price: 80.50 Min Price: 80.50 Max Price: 80.50\n"
    "Shelf 15: Coffee Total Stock: 35 Average Price: 330.75 Min Price: 330.75 Max Price: 330.75\n"
   "Shelf 16: Rice Total Stock: 55 Average Price: 140.00 Min Price: 140.00 Max Price: 140.00\n"; 
   
   Lotion#217.67#29.00
Pen#847.72#31.00
Milk#118.83#50.00
Chocolate#864.70#11.00
Cheese#857.55#38.00
Toothpaste#224.88#42.00
Bread#150.00#60.00
Butter#200.50#25.00
Soap#300.25#40.00
Shampoo#450.75#10.00
Conditioner#250.35#15.00
Eggs#120.10#30.00
Juice#220.45#20.00
Tea#80.50#45.00
Coffee#330.75#35.00
Rice#140.00#55.00*/


  //  assertEqual(expectedReport, report);
}
