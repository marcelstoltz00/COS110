#include "Cabbage.h"

Cabbage::Cabbage(Plot *plot) : MediumPlant('C', plot)
{
}

Cabbage::~Cabbage() {};

void Cabbage::water()
{

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
                (bure[i]->getWaterLevel())++;
            }
        }

        delete[] bure;
    }
}

void Cabbage::harvest()
{

    if (getPlanted() && getWaterLevel() >= 8)
    {

        int cab = 4;

        Plant **bure = getNeighbours();

        for (int i = 0; i < 8; i++)
        {
            if (bure[i])
                bure[i]->getWaterLevel()++;
        }

        *plot->getPosition(y[0], x[0]) = -1;
        *plot->getPosition(y[0], x[1]) = -1;
        *plot->getPosition(y[1], x[0]) = -1;
        *plot->getPosition(y[1], x[1]) = -1;

        getWaterLevel() = 0;

        std::cout << "Harvested 4 cabbages" << std::endl;
        getPlanted() = false;

        delete[] bure;
    }
}
