#ifndef CARROT_H
#define CARROT_H

#include "SmallPlant.h"

class Carrot : public SmallPlant
{
private:
    int harvestCycle;
    int numLeaves;

public:
    Carrot(Plot *plot, int harvestCycle);
    ~Carrot();
    void water();
    void harvest();
};

#endif
