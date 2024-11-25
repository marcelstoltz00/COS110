#include "Carrot.h"

Carrot::Carrot(Plot *plot, int harvestCycle) : SmallPlant('c', plot)
{
    if (harvestCycle <= 0)
        this->harvestCycle = 1;
    else
        this->harvestCycle = harvestCycle;
    this->numLeaves = 0;
}

Carrot::~Carrot(){}
void Carrot::water()
{

    if (this->getPlanted() != false)
    {
        this->getWaterLevel()++;
        numLeaves++;
        numLeaves =numLeaves% harvestCycle;
    }
    else
    {
    }
}

void Carrot::harvest()
{
    if (this->getPlanted() == true && getWaterLevel() > 7)
    {

        this->getPlanted() = false;
        getWaterLevel() = 0;

        int *sp = plot->getPosition(y, x);
            *sp = -1;
        std::cout << "Harvested " << numLeaves << " carrots" << std::endl;
    }
    else
    {
    }
}
