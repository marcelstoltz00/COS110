#ifndef DYNAMICARRAYS_CPP
#define DYNAMICARRAYS_CPP

#include "DynamicArrays.h"
#include <iostream>
#include <sstream>
#include <string>
std::string intToString(int number)
{
    std::stringstream ss;
    ss << number; // Convert integer to string
    return ss.str();
}
void createArray(int **&array, int *&numColumns, int &numRows, std::string input){
    {

        if (array != NULL){// to make sure everything is clear
                           // for (int i = 0; i < numRows; ++i){
                           //  delete[] array[i];
                           //}
                           // delete[] array;
                           // delete[] numColumns;
                           destroyArray(array, numColumns, numRows);
}
numRows = 1;
for (int i = 0; i < input.size(); i++)
{
    if (input[i] == '|')
    {
        numRows++;
    }
}

// now we allocate memory
array = new int *[numRows];
numColumns = new int[numRows];
// Populate numColumns
int icount_colIndex = 0;
int count = 0; // Start at 0 because count will increase with each element
bool foundElement = false;
for (int y = 0; y <= input.size(); y++)
{
    if (y < input.size() && input[y] == ',')
    {
        count++;
    }
    else if (y == input.size() || input[y] == '|')
    {
        if (foundElement)
        {
            numColumns[icount_colIndex++] = count + 1; // Include the last element
        }
        else
        {
            numColumns[icount_colIndex++] = 0; // No elements found in this row
        }
        count = 0;            // Reset column count for the next row
        foundElement = false; // Reset element found flag for the next row
    }
    else
    {
        foundElement = true;
    }
}
// now we populate the variables
int index = 0;
int icount = 0;int indexRow = 0;
for (int i = 0; i < numRows; i++) // run through rows
{
    array[i] = new int[numColumns[i]]; // initialise memory
}

std::stringstream strinput;
int intoutput;

while (index < input.size())
{
    if (input[index] == '|')
    {
        indexRow++;
        icount = 0;
        index++;
       // continue;
    }
    if (input[index] == ',')
    {
        index++;
     //   continue;
    }

    while (index < input.size() && input[index] != ',' && input[index] != '|')
    {
        strinput << input[index];
        index++;
    }

    strinput >> intoutput;
    strinput.clear(); // Clear the stringstream for the next integer
    strinput.str("");

    array[indexRow][icount] = intoutput;
    icount++;
}
/*
while (index < input.size())
{
    if (input[index] == '|')
    {
        indexRow++;
        icount = 0;
        index++;
       // continue;
    }
    if (input[index] == ',')
    {
        index++;
       // continue;
    }
    if ((input[index] != ',') && (input[index] != '|'))
    {
        if ((index + 1 < input.size()) && (input[index + 1] != ',') && (input[index + 1] != '|'))
        {
            strinput << input[index] << input[index + 1];
            index += 2;
        }
        else
        {
            strinput << input[index];
            index++;
        }
        strinput >> intoutput;
        strinput.clear(); // Clear the stringstream for the next integer
        strinput.str("");

        array[indexRow][icount] = intoutput;
        icount++;
    }*/
}
};
void destroyArray(int **&array, int *&numColumns, int &numRows)
{

    for (int i = 0; i < numRows; i++)
    {

        delete[] array[i];
    }
    delete[] numColumns;
    delete[] array;

    array = NULL;
    numColumns = NULL;

    numRows = 0;
};
std::string printArrayStructure(int **&array, int *&numColumns, int &numRows)
{
    std::string str = "numRows : ";
    std::stringstream number;
    number << numRows;
    str += intToString(numRows);
    str += '\n';
    // every row
    int j=0;
    for (int i = 0; i < numRows - 1; i++)
    {
        str = str + "row[" + intToString(i) + "] : " + intToString(numColumns[i]) + "\n";
        j++;
    }
    str = str + "row[" + intToString(j) + "] : " + intToString(numColumns[j]);
    return str;
};
std::string printArray(int **&array, int *&numColumns, int &numRows)
{
    // std::stringstream str;

    std::string str;

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numColumns[i]; j++)
        {
            // if (numColumns[numRows]!=0)
            str = str + intToString(array[i][j]);
            if (j < numColumns[i] - 1)
            {
                str += ","; // Add comma between elements
            }
            // else
            // str=str+"";
        }
        if ((str != "") && (i < numRows - 1))
            str += "\n";
    }

    return str;
};
void addRow(int **&array, int *&numColumns, int &numRows)
{
    int *newnumCol = new int[numRows + 1];
    int **newarray = new int *[numRows + 1];

    for (int i = 0; i < numRows; i++)
    {
        newnumCol[i] = numColumns[i];
        newarray[i] = array[i];
    }

    // lets add the new row now
    newnumCol[numRows] = 0;
    newarray[numRows] = NULL;

    ///////
    delete[] numColumns;
    delete[] array;

    numColumns = newnumCol;
    array = newarray;
    numRows++;
    // we added new row
};
void addValueToRow(int **&array, int *&numColumns, int &numRows, int rowNumber, int value)
{

    if (rowNumber < 0 || rowNumber >= numRows)
    {
        return;
      
    }
    else
    { 
        int *newrow = new int[numColumns[rowNumber] + 1];
        for (int i = 0; i < numColumns[rowNumber]; ++i)
        {
            newrow[i] = array[rowNumber][i];
        }
        newrow[numColumns[rowNumber]] = value;

        delete[] array[rowNumber];

        array[rowNumber] = newrow;
        numColumns[rowNumber]++;
    }
};
void removeRow(int **&array, int *&numColumns, int &numRows, int rowNumber)
{
    // how will we do this
    // create new array in memory for numcols and array
    if (rowNumber < 0 || rowNumber >= numRows)
    {
        return;
    }
    else
    {
        int **newarr = new int *[numRows - 1];
        int *newcol = new int[numRows - 1];
        int iholdrow = 0;
        for (int i = 0; i < numRows; i++)
        {
            if (i == rowNumber)
            {
                // skip
                delete[] array[i];
            }
            else // save value into next index
            {
                newarr[iholdrow] = array[i];
                newcol[iholdrow] = numColumns[i];

                iholdrow++;
            }
        }
        delete[] array;
        delete[] numColumns;
        numRows--; // one less row

        array = newarr;
        numColumns = newcol;
    }

    // delete

    // first,copy everything before and after,except that line into new array//as well as the columns
    // delete original
    // copy new into original
};
void removeValueFromRow(int **&array, int *&numColumns, int &numRows, int rowNumber, int value)
{
    // how will we do this
    // find row
    if (rowNumber >= numRows || rowNumber < 0)
    {
        return;
    }
    else
    {
        int icountvalues = 0;

        // check non match values
        for (int i = 0; i < numColumns[rowNumber]; i++)
        {

            {
                if (value != array[rowNumber][i])
                    icountvalues++;
            }
        }
        int *newarray = new int[icountvalues];
        icountvalues = 0;

        for (int i = 0; i < numColumns[rowNumber]; i++)
        {
            if (array[rowNumber][i] != value)
            {
                newarray[icountvalues++] = array[rowNumber][i];
            }
        }

        // we know how many values,so now we just copy new to old with that amount
        numColumns[rowNumber] = icountvalues;
        delete[] array[rowNumber];

        array[rowNumber] = newarray;
    }
};
int rowSum(int **&array, int *&numColumns, int &numRows, int rowNumber)
{
if (array==NULL || numColumns==NULL)
    {
        return -1;
    }
   if (numColumns[rowNumber] == 0)
    {
        return 0;
    }
    // Check if rowNumber is within the valid range
    if (rowNumber >= numRows || rowNumber < 0)
    {
        return -1;
    }
  
    // Check if the row has columns (numColumns[rowNumber] should not be zero)

    int sum = 0;

    // Sum the elements in the specified row
    for (int i = 0; i < numColumns[rowNumber]; i++)
    {
        sum += array[rowNumber][i];
    }

    return sum;


};
float rowAvg(int **&array, int *&numColumns, int &numRows, int rowNumber)
{
     if (array==NULL || numColumns==NULL)
    {
        return -1;
    }
    // Check if rowNumber is within the valid range
    if (rowNumber >= numRows || rowNumber < 0)
    {
        return -1;
    }

    // Check if the row has columns (numColumns[rowNumber] should not be zero)
    if (numColumns[rowNumber] == 0)
    {
        return -1;
    }


    float sum = 0;

    for (int i = 0; i < numColumns[rowNumber]; i++)
    {
        sum += array[rowNumber][i];
    }

    sum = sum / numColumns[rowNumber];
    return (sum);
};
int rowMax(int **&array, int *&numColumns, int &numRows, int rowNumber)
{ 
     if (array==NULL || numColumns==NULL)
    {
        return -1;
    }
     // Check if rowNumber is within the valid range
    if (rowNumber >= numRows || rowNumber < 0)
    {
        return -1;
    }
  if (numColumns[rowNumber] == 0)
    {
        return -1;
    }

    // Check if the row has columns (numColumns[rowNumber] should not be zero)
 
    int max = array[rowNumber][0];

    for (int i = 1; i < numColumns[rowNumber]; i++)
    {
        if (max < array[rowNumber][i])
            max = array[rowNumber][i];
    }

    return max;
};
int rowMin(int **&array, int *&numColumns, int &numRows, int rowNumber)
{
     if (array==NULL || numColumns==NULL)
    {
        return -1;
    }
    if (rowNumber < 0 || rowNumber >= numRows || numColumns[rowNumber] == 0)
    {
        return -1;
    }
    int min = array[rowNumber][0];

    for (int i = 1; i < numColumns[rowNumber]; i++)
    {
        if (min > array[rowNumber][i])
            min = array[rowNumber][i];
    }

    return min;
};

#endif