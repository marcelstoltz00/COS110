#ifndef PLANT_H
#define PLANT_H
#include "Plot.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
class Plant
{

private:
    int waterLevel;
    char icon;
    bool planted;

protected:
    Plot *plot;

public:
    Plant(char icon, Plot *plot);
    virtual ~Plant();

    virtual void water()=0;
    virtual void harvest()=0;
    virtual bool plantSeed()=0;
    virtual Plant **getNeighbours()=0;
    char getIcon() ;
    int &getWaterLevel();
    bool &getPlanted();
};

#endif