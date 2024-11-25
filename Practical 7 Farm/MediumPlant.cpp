#include "MediumPlant.h"

MediumPlant::MediumPlant(char icon, Plot *plot) : Plant(icon, plot)
{

    x[0] = -1;
    x[1] = -1;
    y[0] = -1;
    y[1] = -1;
}

MediumPlant::~MediumPlant() {};

bool MediumPlant::plantSeed()
{

    if (getPlanted())
    {
        return false;
    }

    for (int i = 0; i < plot->getNumRows() - 1; i++)
    {
        for (int j = 0; j < plot->getNumCols() - 1; j++)
        {

            int *wa1 = plot->getPosition(i, j);
            int *wa2 = plot->getPosition(i, j + 1);
            int *wa3 = plot->getPosition(i + 1, j);
            int *wa4 = plot->getPosition(i + 1, j + 1);

            if ((wa1 && wa2 && wa3 && wa4) && (*wa1 == -1 && *wa2 == -1 && *wa3 == -1 && *wa4 == -1))
            {

                int b = plot->addPlant(this);
                *plot->getPosition(i, j) = b;
                *plot->getPosition(i, j + 1) = b;
                *plot->getPosition(i + 1, j) = b;
                *plot->getPosition(i + 1, j + 1) = b;

                x[0] = j;
                x[1] = j + 1;
                y[0] = i;
                y[1] = i + 1;

                this->getPlanted() = true;
                return true;
            }
        }
    }
    return false;
}

Plant **MediumPlant::getNeighbours()
{
    Plant **bure = new Plant *[8];

    for (int i = 0; i < 8; i++)
    {
        bure[i] = NULL;
    }

    int x1 = x[0];
    int x2 = x[1];
    int y1 = y[0];
    int y2 = y[1];

    // if (y1 > 0 && x1 > 0)
    {
        int *tli = plot->getPosition(y1 - 1, x1);
        //  if (*tli == -1)
        {
        }
        //  else
        {
            bure[0] = plot->getPlant(tli);
        }
    }
    // if (y1 > 0 && x2 < plot->getNumCols() - 1)
    {
        int *tri = plot->getPosition(y1 - 1, x2);
        //  if (*tri != -1)
        {
            bure[1] = plot->getPlant(tri);
        }
    }
    // if (y1 > 0)
    {
        int *ti = plot->getPosition(y1, x2 + 1);
        // if (*ti == -1)
        {
        }
        // else
        {
            bure[2] = plot->getPlant(ti);
        }
    }

    // if (x2 < plot->getNumCols() - 1)
    {
        int *ri = plot->getPosition(y2, x2 + 1);
        //    if (*ri != -1)
        {
            bure[3] = plot->getPlant(ri);
        }
    }
    //  if (y2 < plot->getNumRows() - 1)
    {
        int *bi = plot->getPosition(y2 + 1, x2);
        // if (*bi == -1)
        {
        }
        // else
        bure[4] = plot->getPlant(bi);
    }
    //   if (y2 < plot->getNumRows() - 1 && x2 < plot->getNumCols() - 1)
    {
        int *bri = plot->getPosition(y2 + 1, x1);
        //  if (*bri != -1)
        {
            bure[5] = plot->getPlant(bri);
        }
    }

    //  if (y2 < plot->getNumRows() - 1 && x1 > 0)
    {
        int *bli = plot->getPosition(y2, x1 - 1);
        //   if (*bli == -1)
        {
        }
        //   else
        bure[6] = plot->getPlant(bli);
    }

    //  if (x1 > 0)
    {
        int *li = plot->getPosition(y1, x1 - 1);
        //   if (*li == -1)
        {
        }
        //   else
        bure[7] = plot->getPlant(li);
    }

    return bure;
}
