#ifndef CABBAGE_H
#define CABBAGE_H

#include "MediumPlant.h"

class Cabbage : public MediumPlant
{
public:
    Cabbage(Plot *plot);
    ~Cabbage();
    void water();
    void harvest();
};

#endif
