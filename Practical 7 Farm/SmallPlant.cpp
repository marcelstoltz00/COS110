#include "SmallPlant.h"

SmallPlant::SmallPlant(char icon, Plot *plot) : Plant(icon, plot)
{


    x = -1;
    y = -1;
}
SmallPlant::~SmallPlant(){}

bool SmallPlant::plantSeed()
{
    if (getPlanted())
    {
        return false;
    }

    for (int i = 0; i < plot->getNumRows(); i++)
    {

        for (int j = 0; j < plot->getNumCols(); j++)
        {
            int *wai = plot->getPosition(i, j);

            if (*wai == -1)
            {

                *wai = plot->addPlant(this);
                x = i;
                y = j;
                this->getPlanted() = true;
                return true;
            }
        }
    }
    return false;
}

Plant **SmallPlant::getNeighbours()
{
    Plant **bure = new Plant *[4];


  //  if (x > 0)
    {
      //  plot->getPosition(y, x - 1);
     //   if (li == -1)
        {
        }
     //   else
            bure[0] = plot->getPlant( plot->getPosition(y, x - 1));
    }

//    if (y > 0)
    {
        int *ui = plot->getPosition(y - 1, x);
      //  if (ui == -1)
        {
        }
     //   else
            bure[1] = plot->getPlant(ui);
    }

  //  if (y < plot->getNumRows() - 1)
    {
        int* di = plot->getPosition(y + 1, x);
       // if (di == -1)
        {
        }
   //     else
            bure[2] = plot->getPlant(di);
    }

   // if (x < plot->getNumCols() - 1)
    {
        int *ri = plot->getPosition(y, x + 1);
     //   if (ri == -1)
        {
        }
    //    else
            bure[3] = plot->getPlant(ri);
    }

    return bure;
}
