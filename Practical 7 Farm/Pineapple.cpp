#include "Pineapple.h"

Pineapple::Pineapple(Plot *plot) : MediumPlant('P', plot)
{

    waterHistory = new int[0];
    historySize = 0;
}

Pineapple::~Pineapple()
{

    delete[] waterHistory;
}

void Pineapple::water()
{
    int burewater = 0;

    if (getPlanted())
    {
        getWaterLevel()++;

        Plant **bure = getNeighbours();
        for (int i = 0; i < 8; i++)
        {
            if (bure[i] == NULL)
            {
            }
            else
            {
                burewater += bure[i]->getWaterLevel();
            }
        }
        historySize++;
        delete[] bure;

        int *nwh = new int[historySize];

        for (int i = 0; i < historySize - 1; i++)
        {
            nwh[i] = waterHistory[i];
        }
        nwh[historySize - 1] = burewater;
        delete[] waterHistory;
        waterHistory = nwh;
    }
}

void Pineapple::harvest()
{
    int water = 0;
    int pineapps = 0;

    if (getPlanted() && getWaterLevel() >= 8)
    {
        for (int i = 0; i < historySize; i++)
        {
            water = waterHistory[i] + water;
        }
        pineapps = 1 + (water / 4);

        Plant **bure = getNeighbours();
        for (int i = 0; i < 8; i++)
        {
            if (bure[i] == NULL)
            {
            }
            else
                bure[i]->getWaterLevel()++;
        }
        delete[] waterHistory;
        delete[] bure;

        *plot->getPosition(y[0], x[0]) = -1;
        *plot->getPosition(y[0], x[1]) = -1;
        *plot->getPosition(y[1], x[0]) = -1;
        *plot->getPosition(y[1], x[1]) = -1;
        getPlanted() = false;

        getWaterLevel() = 0;

        waterHistory = new int[0];
        historySize = 0;

        std::cout << "Harvested " << pineapps << " Pineapples" << std::endl;
    }
}
