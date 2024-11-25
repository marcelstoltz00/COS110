#include "Plot.h"
#include "Plant.h"
#include "MediumPlant.h"
#include "SmallPlant.h"
#include "Cabbage.h"
#include "Radish.h"
#include "Pineapple.h"
#include "Carrot.h"
#include <iostream>

int main()
{
  Plot pl(5, 5);

  Carrot carr(&pl, 3);
  carr.plantSeed();
  pl.printPlot();

  for (int i = 0; i < 10; i++)
  {
    carr.water();
    carr.getWaterLevel();
  }

  carr.harvest();
  pl.printPlot();
  carr.getPlanted();

  Radish rad(&pl, 5);
  rad.plantSeed();
  pl.printPlot();
  for (int i = 0; i < 9; i++)
  {
    rad.water();
    rad.getWaterLevel();
  }

  rad.harvest();
  rad.getPlanted();
  pl.printPlot();
  Cabbage cab(&pl);
  cab.plantSeed();
  pl.printPlot();
  for (int i = 0; i < 9; i++)
  {
    cab.water();
    cab.getWaterLevel();
  }

  cab.harvest();
  cab.getPlanted();
  pl.printPlot();
  Pineapple pine(&pl);
  pine.plantSeed();

  for (int i = 0; i < 9; i++)
  {
    pine.water();
    pine.getWaterLevel();
  }

  pine.getPlanted();

  pl.printPlot();

  pl.waterAllPlants();

  pl.harvestAllPlants();

  cab.harvest();
  pine.harvest();

  pl.printPlot();

  return 0;
}
