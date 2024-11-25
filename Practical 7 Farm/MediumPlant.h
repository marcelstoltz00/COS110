#ifndef MEDIUMPLANT_H
#define MEDIUMPLANT_H

#include "Plant.h"

class MediumPlant : public Plant
{
protected:
    int x[2];
    int y[2];

public:
    MediumPlant(char icon, Plot *plot);
    ~MediumPlant();
    virtual void water() =0;
    virtual void harvest()=0 ;
    bool plantSeed();
    Plant **getNeighbours();
};

#endif
