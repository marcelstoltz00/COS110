#ifndef RADISH_H
#define RADISH_H

#include "SmallPlant.h"

class Radish : public SmallPlant
{
private:
  int period;

public:
  Radish(Plot *plot, int period);
  ~Radish();
  void water();
  void harvest();
};

#endif
