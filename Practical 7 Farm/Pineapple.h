#ifndef PINEAPPLE_H
#define PINEAPPLE_H

#include "MediumPlant.h"

class Pineapple : public MediumPlant {
private:
    int* waterHistory;
    int historySize;

public:
    Pineapple(Plot* plot);
    ~Pineapple();
    void water() ;
void harvest() ;
};

#endif
