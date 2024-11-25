#include "Plot.h"
#include "Plant.h"

Plot::Plot(int numRows, int numCols)
{
    this->numRows = numRows;
    this->numCols = numCols;


    soil = new int *[numRows];
    for (int i = 0; i < numRows; i++)
    {
        soil[i] = new int[numCols];

        for (int j = 0; j < numCols; j++)
        {
            soil[i][j] = -1;
        }
    }    
    numPlants = 0;
    plants = new Plant *[numPlants];
}

Plot::~Plot()
{

    for (int i = 0; i < numRows; i++)
    {

        delete[] soil[i];
    }
    delete [] soil;


    delete [] plants;
}

void Plot::waterAllPlants()
{

    for (int i = 0; i < numRows; i++)
    {

        for (int j = 0; j < numCols; j++)
        {
            if (soil[i][j] != -1)
            {

                plants[soil[i][j]]->water();
            }
        }
    }
}

void Plot::harvestAllPlants()
{

    for (int i = 0; i < numRows; i++)
    {

        for (int j = 0; j < numCols; j++)
        {
            if (soil[i][j] != -1)
            {

                plants[soil[i][j]]->harvest();
            }
        }
    }
}

void Plot::printPlot()
{

    for (int i = 0; i < numRows; i++)
    {

        for (int j = 0; j < numCols; j++)
        {
            if (soil[i][j] != -1)
            {
                std::cout << plants[soil[i][j]]->getIcon();
            }
            else
            {
                std::cout << "-";
            }
           
        } std::cout << std::endl;
    }
}

int Plot::getNumRows() 
{
    return numRows;
}

int Plot::getNumCols() 
{
    return numCols;
}

int *Plot::getPosition(int row, int col)
{
    if (row >= numRows || col >= numCols || col < 0 || row < 0)
    {
        return NULL;
    }
    return &soil[row][col];
}

Plant *Plot::getPlant(int *idx)
{
    if (idx == NULL||*idx >= numPlants || *idx < 0  )
    {
        return NULL;
    }
    else
    {
        return plants[*idx];
    }
}

int Plot::addPlant(Plant *plant)
{
    Plant **np = new Plant *[numPlants + 1];
    for (int i = 0; i < numPlants; i++)
    {
        np[i] = plants[i];
    }
    numPlants++;
    np[numPlants - 1] = plant;
    delete[] plants;
    plants = np;

    return numPlants-1;
}
