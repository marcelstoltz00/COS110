#include "Radish.h"

Radish::Radish(Plot *plot, int period) : SmallPlant('r', plot)
{
    this->period = abs(period);
    if (period == 0)
        this->period = 10;
}

void Radish::water()
{

    if (this->getPlanted())
    {

        this->getWaterLevel()++;
    }
}
Radish::~Radish(){}

void Radish::harvest()
{
    double PI = 3.14159265358979323846264338327950288;

    if (getPlanted() && getWaterLevel() >= 8)
    {
        Plant **bure = getNeighbours();
        int bureWater = 0;

        for (int i = 0; i < 4; i++)
        {
            if (bure[i] == NULL)
            {
          
            }
            else
                  bureWater += bure[i]->getWaterLevel();
        }
        delete [] bure;

        int radish = floor(bureWater * std::pow((std::sin((2 * PI * getWaterLevel()) / period)),2));

        getPlanted() = false;

        int *sp = plot->getPosition(y, x);
        if (sp)
        {
            *sp = -1;
        }

        getWaterLevel() = 0;

        std::cout << "Harvested " << radish << " radishes" << std::endl;

       
    }
}
