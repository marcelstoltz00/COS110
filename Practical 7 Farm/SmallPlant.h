#ifndef SMALLPLANT_H
#define SMALLPLANT_H

#include "Plant.h"

class SmallPlant : public Plant
{
protected:
    int x;
    int y;

public:
    SmallPlant(char icon, Plot *plot);
   ~SmallPlant();
    virtual void water()=0;
    virtual void harvest()=0;
    bool plantSeed();
    Plant **getNeighbours();
};

#endif
