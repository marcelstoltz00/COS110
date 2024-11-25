#include "Plant.h"

Plant::Plant(char icon, Plot *plot)
{
    this->icon = icon;
    this->plot = plot;
    waterLevel = 0;
    planted = false;
}

Plant::~Plant()
{
}


char Plant::getIcon() 
{
    return icon;
}

int &Plant::getWaterLevel()
{
    return waterLevel;
}

bool &Plant::getPlanted()
{
    return planted;
}
