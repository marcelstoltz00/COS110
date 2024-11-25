#include <cstdio>
#include <iostream>

#include "DynamicArrays.h"
#include "testingFramework.h"

using namespace std;

void createAndDestroyTest()
{
    int **array = NULL;
    int *numColumns = NULL;
    int numRows = 0;
    startSuite("createAndDestroy");

    startSection("Blank String");
    createArray(array, numColumns, numRows, "");
    int numColumnsAns[] = {0};
    int row0Ans[] = {};
    assert(1, numRows); // 1
    // expected , received ,size
    assertArray(numColumnsAns, numColumns, 1); // 2
    assertArray(row0Ans, array[0], 0);         // 3
    destroyArray(array, numColumns, numRows);  //
    assertNULL(array);                         // 4
    assertNULL(numColumns);                    // 5
    assert(0, numRows);                        // 6

    startSection("Easy example");
    createArray(array, numColumns, numRows, "1,2|3,4|5,6");
    int numColumnsAns2[] = {2, 2, 2};
    int row0Ans2[] = {1, 2}, row1Ans2[] = {3, 4}, row2Ans2[] = {5, 6};
    assert(3, numRows); // 7
                        // expected,received, size
    assertArray(numColumnsAns2, numColumns, 3); // 8
    assertArray(row0Ans2, array[0], 2);         // 9
    assertArray(row1Ans2, array[1], 2);         // 10
    assertArray(row2Ans2, array[2], 2);         // 11
    destroyArray(array, numColumns, numRows);   //
    assertNULL(array);                          // 12
    assertNULL(numColumns);                     // 13
    assert(0, numRows);                         // 14

    endSuite();
}

void printTest()
{
    int **array = NULL;
    int *numColumns = NULL;
    int numRows = 0;

    startSuite("print");

    startSection("Empty String");
    createArray(array, numColumns, numRows, "");
    assert("numRows : 1\nrow[0] : 0", printArrayStructure(array, numColumns, numRows));
    assert("", printArray(array, numColumns, numRows));
    destroyArray(array, numColumns, numRows);

    startSection("Easy Example");
    createArray(array, numColumns, numRows, "1,2|3,4|5,6");
    assert("numRows : 3\nrow[0] : 2\nrow[1] : 2\nrow[2] : 2", printArrayStructure(array, numColumns, numRows));
    assert("1,2\n3,4\n5,6", printArray(array, numColumns, numRows));
    destroyArray(array, numColumns, numRows);

    endSuite();
}
void testrest()
{


   

    int **array = NULL;
    int *numColumns = NULL;
    int numRows = 0;

    // Test Suite for rowSum
    std::cout << "Testing rowSum" << std::endl;
    createArray(array, numColumns, numRows, "");
    assert(rowSum(array, numColumns, numRows, 0) ,-1); // Edge case: empty array
    destroyArray(array, numColumns, numRows);

    createArray(array, numColumns, numRows, "1,2,3|4,5,6|7,8,9");
    assert(rowSum(array, numColumns, numRows, 0), 6); // 1+2+3
    assert(rowSum(array, numColumns, numRows, 1) , 15); // 4+5+6
    assert(rowSum(array, numColumns, numRows, 2) , 24); // 7+8+9
    assert(rowSum(array, numColumns, numRows, 3) , -1); // Edge case: invalid row
    destroyArray(array, numColumns, numRows);

    // Test Suite for rowAvg
    std::cout << "Testing rowAvg" << std::endl;
    createArray(array, numColumns, numRows, "");
    assert(rowAvg(array, numColumns, numRows, 0) , -1); // Edge case: empty array
    destroyArray(array, numColumns, numRows);

    createArray(array, numColumns, numRows, "1,2,3|4,5,6|7,8,9");
    assert(rowAvg(array, numColumns, numRows, 0) , 2.0); // (1+2+3)/3
    assert(rowAvg(array, numColumns, numRows, 1) , 5.0); // (4+5+6)/3
    assert(rowAvg(array, numColumns, numRows, 2) , 8.0); // (7+8+9)/3
    assert(rowAvg(array, numColumns, numRows, 3) , -1); // Edge case: invalid row
    destroyArray(array, numColumns, numRows);

    // Test Suite for rowMax
    std::cout << "Testing rowMax" << std::endl;
    createArray(array, numColumns, numRows, "");
    assert(rowMax(array, numColumns, numRows, 0) , -1); // Edge case: empty array
    destroyArray(array, numColumns, numRows);

    createArray(array, numColumns, numRows, "1,2,3|4,5,6|7,8,9");
    assert(rowMax(array, numColumns, numRows, 0) , 3);
    assert(rowMax(array, numColumns, numRows, 1) , 6);
    assert(rowMax(array, numColumns, numRows, 2) , 9);
    assert(rowMax(array, numColumns, numRows, 3) , -1); // Edge case: invalid row
    destroyArray(array, numColumns, numRows);

    // Test Suite for rowMin
    std::cout << "Testing rowMin" << std::endl;
    createArray(array, numColumns, numRows, "");
    assert(rowMin(array, numColumns, numRows, 0) , -1); // Edge case: empty array
    destroyArray(array, numColumns, numRows);

    createArray(array, numColumns, numRows, "1,2,3|4,5,6|7,8,9");
    assert(rowMin(array, numColumns, numRows, 0) , 1);
    assert(rowMin(array, numColumns, numRows, 1) , 4);
    assert(rowMin(array, numColumns, numRows, 2) , 7);
    assert(rowMin(array, numColumns, numRows, 3) , -1); // Edge case: invalid row
    destroyArray(array, numColumns, numRows);
// Test Suite for addRow
    std::cout << "Testing addRow" << std::endl;
    createArray(array, numColumns, numRows, "1,2,3|4,5,6");
    addRow(array, numColumns, numRows);
    assert(numRows , 3);
    assert(numColumns[2] , 0);
   // assert(array[2] , nullptr);
    destroyArray(array, numColumns, numRows);

    // Test Suite for addValueToRow
    std::cout << "Testing addValueToRow" << std::endl;
    createArray(array, numColumns, numRows, "1,2,3|4,5,6");
    addValueToRow(array, numColumns, numRows, 0, 4);
    assert(numColumns[0] , 4);
    assert(array[0][3] , 4);
    addValueToRow(array, numColumns, numRows, 1, 7);
    assert(numColumns[1] , 4);
    assert(array[1][3] , 7);
    destroyArray(array, numColumns, numRows);

    // Test Suite for removeRow
    std::cout << "Testing removeRow" << std::endl;
    createArray(array, numColumns, numRows, "1,2,3|4,5,6|7,8,9");
    removeRow(array, numColumns, numRows, 1);
    assert(numRows , 2);
    assert(numColumns[0] , 3);
    assert(numColumns[1] , 3);
    assert(array[0][0] , 1);
    assert(array[1][0] , 7);
    destroyArray(array, numColumns, numRows);

    // Test Suite for removeValueFromRow
    std::cout << "Testing removeValueFromRow" << std::endl;
    createArray(array, numColumns, numRows, "1,2,3,2|4,5,6|7,8,9");
    removeValueFromRow(array, numColumns, numRows, 0, 2);
    assert(numColumns[0] , 2);
    assert(array[0][0] , 1);
    assert(array[0][1] , 3);
    removeValueFromRow(array, numColumns, numRows, 2, 9);
    assert(numColumns[2] , 2);
    assert(array[2][0] , 7);
    assert(array[2][1] , 8);
    destroyArray(array, numColumns, numRows);

    std::cout << "All tests passed!" << std::endl;
    
    
}



    

/*
Printmode
    0 -> Normal printing
    1 -> Test Passed/Failed
*/
int main(int argc, char *argv[])
{
    changePrintMode(1);
    createAndDestroyTest();
    printTest();
   testrest();
    return 0;
}